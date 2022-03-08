/*all the methods pretty much do the same task like BoardArray1D ,just the array is two dimensional in this case */
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
public class BoardArray2D extends AbstractBoard{
    private int[][] array;
    private int[][] solutionArray;
    public BoardArray2D(int x,int y){
        super(x,y);
        array=new int[row][];
        solutionArray=new int[row][];
        for(int i=0; i<row; i++){
            array[i]=new int[col];
            solutionArray[i]=new int[col];
        }
    }
    public int[][] getArray(){
        return array;
    }
    public void reset(){
        int k=1;
        array=new int[row][];
        solutionArray=new int[row][];
        for(int i=0; i<row; i++){
            array[i]=new int[col];
            solutionArray[i]=new int[col];
        }
        for (int i=0; i< row; i++) //we loop throught the array 
        {
            for (int j=0; j< col ; j++)
            {
                array[i][j]=k; //fill interger values 
                solutionArray[i][j]=k;
                if(i==row-1 && j==col-1) //for the last position we place a 0
                {
                    array[i][j]=-1;
                    solutionArray[i][j]=-1;
                }
                k++;
            }
        }
    }
    public boolean moveRight(){
        boolean flag;
        locateValue(array, -1); // locate the position of space in the board
        if (y+1>=col || array[x][y+1]==0){   //checks if the move is valid 
            flag=false;
        }
        else{
            swap temp=new swap(array[x][y+1],array[x][y]);
            temp.swap(temp); 
            array[x][y+1]=temp.a;
            array[x][y]=temp.b;   
            flag=true;     //if swap is a success then returns true else returns false 
        }
        return flag;
    }
    public boolean moveLeft(){
        boolean flag;
        locateValue(array, -1); // locate the position of space in the board
        if (y-1<0 || array[x][y-1]==0){   //checks if the move is valid 
            flag=false;
        }
        else{ 
            swap temp=new swap(array[x][y-1],array[x][y]);
            temp.swap(temp);
            array[x][y-1]=temp.a;
            array[x][y]=temp.b;
            flag=true;     //if swap is a success then returns true else returns false 
        }
        return flag;
    }
    public boolean moveUp(){
        boolean flag;
        locateValue(array, -1); // locate the position of space in the board
        if (x-1<0 || array[x-1][y]==0){   //checks if the move is valid 
            flag=false;
        }
        else{
            swap temp=new swap(array[x-1][y],array[x][y]);   
            temp.swap(temp);
            array[x-1][y]=temp.a;
            array[x][y]=temp.b;         
            flag=true;     //if swap is a success then returns true else returns false 
        }
        return flag;
    }
    public boolean moveDown(){
        boolean flag;
        locateValue(array, -1); // locate the position of space in the board
        if (x+1>=row || array[x+1][y]==0){   //checks if the move is valid 
            flag=false;
        }
        else{
            swap temp=new swap(array[x+1][y],array[x][y]);
            temp.swap(temp);
            array[x+1][y]=temp.a;
            array[x][y]=temp.b;
            flag=true;     //if swap is a success then returns true else returns false 
        }
        return flag;
    }
    public boolean isSolved(){
        boolean flag=true; //initially we set the flag value to be true
        int i,j;
        for (i=0; i<row ;i++){
            for (j=0; j<col; j++){
                if(array[i][j]!=solutionArray[i][j]){
                    flag=false;
                    break;
                }
            }
        }
        return flag;
    }
    public void initSolutionBoardFile(){
        int i,j,k=1;
        for (i=0; i < row; i++){
            for(j=0; j < col; j++){
                if(array[i][j]==0){
                    solutionArray[i][j]=0;
                }
                else if(array[i][j]!=0){
                    solutionArray[i][j]=k;
                    k++;
                }
                if(i==x-1 && j==y-1) //for the last position we place a -1
                {
                    solutionArray[i][j]=-1;
                }
            }
        }
    }
    public void writeToFile(String fileName){
        int i;
        try {
            FileWriter output=new FileWriter(fileName);
            for (i=0; i<row; i++ ){  //this loop writes in the file 
                for (int j=0; j< col; j++){
                    String x=Integer.toString(array[i][j]);
                    output.write(x);
                    output.write(" ");
                }
                output.write("\n");
            }
            output.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public void readFromFile(String fName){//this function is innerclass public member function which will load a saved game  
        String word;
        try {
            File file=new File(fName);
            if(file.exists()){
                Scanner input=new Scanner(file);
                int i=0,j=0;
                while(input.hasNext()){
                    word=input.next();
                    if(word.equals("bb")){
                        array[i][j]=-1;
                        j++;
                        if(j==col){
                            i++;j=0;
                        }
                    }
                    else if(word.equals("-1")){
                        array[i][j]=-1;
                        j++;
                        if(j==col){j=0; i++;}
                    }
                    else{
                        array[i][j]=Integer.parseInt(word);
                        j++;
                        if(j==col){j=0; i++;}
                    }
                }
                input.close();
            }  
        } catch (IOException e) {
            e.printStackTrace();
        }
        
    }
    public int cell(int x,int y){
        return array[x][y];
    }
    public boolean Equals(AbstractBoard x,AbstractBoard y){
        if(x instanceof BoardArray2D && y instanceof BoardArray2D){
            BoardArray2D t1=(BoardArray2D)x;
            BoardArray2D t2=(BoardArray2D)y;
            int [][] temp1=t1.getArray();
            int [][] temp2=t2.getArray();
            for(int i=0; i<x.getRow(); i++){
                for(int j=0; j<y.getCol(); j++){
                    if(temp1[i][j]!=temp2[i][j]){
                        return false;
                    }
                }
            }
            return true;
        }
        return false;
    }
}