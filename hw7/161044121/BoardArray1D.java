
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
public class BoardArray1D extends AbstractBoard{
    private int[] array;
    private int[] solutionArray;
    private int size;
    /*constructor that takes two parameter row and column */
    public BoardArray1D(int row,int col){
        super(row,col);
        size=row*col;
        array=new int[size];
        solutionArray=new int[size];
    }
    public int getSize(){
        return size;
    }
    //converts an 1d array to 2d array. private within contex 
    public int[][] convert(int[] array){
        int[][] temp;
        temp=new int[row][col];
        for(int i=0; i < row; i++){
            temp[i]=new int[col];
        }
        int k=0; 
        for(int i=0; i<row; i++){
            for(int j=0; j<col;j++){
                temp[i][j]=array[k];
                k++;
            }
        }
        return temp;
    }
    //convert 2d array to 1d array 
    public void convertBack(int[][] temp,int []arr){
        int k=0;
        for (int i=0;i<row;i++ ){
            for (int j=0; j<col; j++){
                arr[k]=temp[i][j];
                k++;
            }
        }
    }
    //return the array 
    public int[] getArray(){
        return array;
    }
    //reset a board to initial condition
    public void reset(){
        int i,k=1;
        for (i=0; i< size; i++) //we loop throught the array 
        {
            array[i]=k;
            solutionArray[i]=k;
            k++;
            if(i==size-1){
                array[i]=-1;
                solutionArray[i]=-1;
            }
        }
    }
    //move the space at right side 
    public boolean moveRight(){
        boolean flag;
        int[][] tempArr=convert(array);
        locateValue(tempArr, -1); // locate the position of space in the board
        if (y+1>=col || tempArr[x][y+1]==0){   //checks if the move is valid 
            flag=false;
        }
        else{
            swap temp=new swap(tempArr[x][y+1],tempArr[x][y]);
            temp.swap(temp); 
            tempArr[x][y+1]=temp.a;
            tempArr[x][y]=temp.b;   
            flag=true;     //if swap is a success then returns true else returns false 
            convertBack(tempArr, array);
        }
        return flag;
    }
    //move the space at left side 
    public boolean moveLeft(){
        boolean flag;
        int[][] tempArr=convert(array);
        locateValue(tempArr, -1); // locate the position of space in the board
        if (y-1<0 || tempArr[x][y-1]==0){   //checks if the move is valid 
            flag=false;
        }
        else{ 
            swap temp=new swap(tempArr[x][y-1],tempArr[x][y]);
            temp.swap(temp);
            tempArr[x][y-1]=temp.a;
            tempArr[x][y]=temp.b;
            flag=true;     //if swap is a success then returns true else returns false 
            convertBack(tempArr, array);
        }
        return flag;
        
    }
    //move the space up
    public boolean moveUp(){
        boolean flag;
        int[][] tempArr=convert(array);
        locateValue(tempArr, -1); // locate the position of space in the board
        if (x-1<0 || tempArr[x-1][y]==0){   //checks if the move is valid 
            flag=false;
        }
        else{
            swap temp=new swap(tempArr[x-1][y],tempArr[x][y]);   
            temp.swap(temp);
            tempArr[x-1][y]=temp.a;
            tempArr[x][y]=temp.b;         
            flag=true;     //if swap is a success then returns true else returns false 
            convertBack(tempArr, array);
        }
        return flag;
    }
    //move the space down
    public boolean moveDown(){
        boolean flag;
        int[][] tempArr=convert(array);
        locateValue(tempArr, -1); // locate the position of space in the board
        if (x+1>=row || tempArr[x+1][y]==0){   //checks if the move is valid 
            flag=false;
        }
        else{
            swap temp=new swap(tempArr[x+1][y],tempArr[x][y]);
            temp.swap(temp);
            tempArr[x+1][y]=temp.a;
            tempArr[x][y]=temp.b;
            flag=true;     //if swap is a success then returns true else returns false 
            convertBack(tempArr, array);
        }
        return flag;
    }
    //if the current board is a solution 
    public boolean isSolved(){
        boolean flag=true; //initially we set the flag value to be true
        int i,j;
        int[][] temp1=convert(array);
        int[][] temp2=convert(solutionArray);
        for (i=0; i<row ;i++){
            for (j=0; j<col; j++){
                if(temp1[i][j]!=temp2[i][j]){
                    flag=false;
                    break;
                }
            }
        }
        return flag;
    }
    //initialize the solution board from file 
    public void initSolutionBoardFile(){
        int i,j,k=1;
        int[][] temp1=convert(array);
        int[][] temp2=convert(solutionArray);
        for (i=0; i < row; i++){
            for(j=0; j < col; j++){
                if(temp1[i][j]==0){
                    temp2[i][j]=0;
                }
                else if(temp1[i][j]!=0){
                    temp2[i][j]=k;
                    k++;
                }
                if(i==x-1 && j==y-1) //for the last position we place a -1
                {
                    temp2[i][j]=-1;
                }
            }
        }
        convertBack(temp2, solutionArray);
    }
    //write the current state of the board to a file 
    public void writeToFile(String fileName){
        int i;
        try {
            int [][] temp=convert(array);
            FileWriter output=new FileWriter(fileName);
            for (i=0; i<row; i++ ){  //this loop writes in the file 
                for (int j=0; j< col; j++){
                    String x=Integer.toString(temp[i][j]);
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
    //reads a file and create a board accordingly
    public void readFromFile(String fName){//this function is innerclass public member function which will load a saved game  
        String word;
        try {
            int [][] temp;
            temp=new int[row][];
            for(int i=0; i<row; i++){
                temp[i]=new int[col];
            }
            File file=new File(fName);
            if(file.exists()){
                Scanner input=new Scanner(file);
                int i=0,j=0;
                while(input.hasNext()){
                    word=input.next();
                    if(word.equals("bb")){
                        temp[i][j]=-1;
                        j++;
                        if(j==col){
                            i++;j=0;
                        }
                    }
                    else if(word.equals("-1")){
                        temp[i][j]=-1;
                        j++;
                        if(j==col){j=0; i++;}
                    }
                    else{
                        temp[i][j]=Integer.parseInt(word);
                        j++;
                        if(j==col){j=0; i++;}
                    }
                }
                input.close();
                convertBack(temp, array);
            }  
        } catch (IOException e) {
            e.printStackTrace();
        }
        
    }
    //takes two cordinate and returns corresponding cell value
    public int cell(int x,int y){
        int[][]temp=convert(array);
        return temp[x][y];
    }
    //takes two board and checks if they are equal and returns boolean value based on that 
    public boolean Equals(AbstractBoard x,AbstractBoard y){
        if(x instanceof BoardArray1D && y instanceof BoardArray1D){
            BoardArray1D t1=(BoardArray1D)x;
            BoardArray1D t2=(BoardArray1D)y;
            int[] temp1=t1.getArray();
            int[] temp2=t2.getArray();
            for(int i=0; i<x.getCol()*x.getRow(); i++){
                if(temp1[i]!=temp2[i]){
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    public static boolean validSeq(BoardArray1D[] array,int size){
        if(size==1){
            return array[0].isSolved();
        }
        for(int i=0; i<size-1;i++){
            int temp1[][]=array[i].convert(array[i].getArray());
            int temp2[][]=array[i+1].convert(array[i+1].getArray());
            int j=0,k=0,m=0,n=0;
            int a=0,b=0,c=0,d=0;
            for( j=0; j<array[i].getRow(); j++){
                for( k=0; k< array[i].getCol(); k++){
                    if(temp1[j][k]==-1){
                        a=j;b=k;
                        break;}
                }
            }
            for( m=0; m<array[i].getRow(); m++){
                for( n=0; n< array[i].getCol(); n++){
                    if(temp2[m][n]==-1){
                        c=m;d=n;
                        break;}
                }
            }
            if(a==c){
                if(b<d){
                    if((d-b)!=1)return false; 
                }
                else if(b>d){
                    if((b-d)!=1) return false;
                }
                else if(b==d) return false;
            }
            else if(b==d){
                if(a<c){
                    if((c-a)!=-1) return false;
                }
                else if(a>c){
                    if((a-c)!=1) return false;
                }
                else if(a==c) return false;
            }
        }
        return true;
    }
}