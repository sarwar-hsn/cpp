import java.io.File;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;
public abstract class AbstractBoard{
    protected String fileName;
    protected int row,col,x=0,y=0;
    public static int boardCreated=0;
    public int totalMove=0;
    protected char moveChoice,lastMove;
    
    //setters and getters 
    public void setRow(int var){
        row=var;
    }
    public void setCol(int var){
        col=var;
    }
    public void setX(int var){
        x=var;
    }
    public void setY(int var){
        y=var;
    }
    public void setMoveChoice(char var){
        moveChoice=var;
    }
    public void setLastMove(char var){
        lastMove=var;
    }
    public void setFileName(String var){
        fileName=var;
    }

    public int getRow(){
        return row;
    }
    public int getCol(){
        return col;
    }
    public int getX(){
        return x;
    }
    public int getY(){
        return y;
    }
    public char getMoveChoice(){
        return moveChoice;
    }
    public String getFileName(){
        return fileName;
    }

    //moving  in all four direction
    public abstract boolean moveRight();
    public abstract boolean moveLeft();
    public abstract boolean moveUp();
    public abstract boolean moveDown();
    public abstract void initSolutionBoardFile();
    
    
    public AbstractBoard(){
        setRow(0);
        setCol(0);
        setLastMove('S');
        totalMove=0;
        boardCreated+=1;
    }
    AbstractBoard(int x,int y){
        this.row=x;
        this.col=y;
        setLastMove('S');
        totalMove=0;
        boardCreated+=1;
    }
   
    public class locateValue {

        public void locateValue2D(int[][]temp,int value){
            for (int i=0; i< row; i++)
            {
                for (int j=0; j<col; j++)
                {
                    if (temp[i][j]==value)
                    {
                        setX(i);
                        setY(j);
                    }
                }
            }
        }
        
    }
    public void locateValue(int [][]temp,int value){
        locateValue x=new locateValue();
        x.locateValue2D(temp, value);
    }
    public void rowCol(String fileName){
        try {
            
            boolean exist;
            File x=new File(fileName);
            exist=x.exists();
            if(exist){
                row=0;col=0;
                Scanner input = new Scanner(x);
                while (input.hasNext()) {
                    String word  = input.next();
                    col++;
                  }
                  input.close();
                Scanner in = new Scanner(x);
                while(in.hasNextLine()){
                    String word = in.nextLine();
                    row++;
                }
                in.close();
                col/=row;
            }
        } catch (Exception e) {
            System.out.println("error in opening file");
        }
    }

    //to test
    public String toString(int[][] array){
        return String.format(Arrays.deepToString(array));
    }
    public String toString(int[] array){
        return String.format(Arrays.toString(array));
    }
    abstract void readFromFile(String fName);
    abstract void writeToFile(String fileName);
    abstract void reset();
    public void setSize(int x,int y){
        setRow(x);
        setCol(y);
    }
    public void move(char moveChoice){
        switch (moveChoice)
        {
            case 'R':   //if user wants to go right 
            case 'r':
                if(moveRight()==false){
                    System.out.println("Invalid move!!");
                }else{
                    setLastMove('R');
                    totalMove++;
                }
                break;
            case 'L':   //if user wants to go left 
            case 'l':
                if(moveLeft()==false){
                    System.out.println("Invalid move!!");
                }else{
                    setLastMove('L');
                    totalMove++;
                }
                break;
            case 'U':   //if  user wants to go up 
            case 'u':
                if(moveUp()==false){
                    System.out.println("Invalid move!!");
                }else{
                    setLastMove('U');
                    totalMove++;
                }
                break;
            case 'D':   //if user wants to go down 
            case 'd':
                if(moveDown()==false){
                    System.out.println("Invalid move!!");
                }else{
                    setLastMove('D');
                    totalMove++;
                }
                break;
            case 'S':
            case 's':
                break;
        }
    }
    abstract boolean isSolved();
    abstract int cell(int x,int y);
    abstract boolean Equals(AbstractBoard x,AbstractBoard y);
    public char getLastMove(){
        return lastMove;
    }
    public int NumberofBoards(){
        return boardCreated;
    }
    public int numberofMoves(){
        return totalMove;
    }
    
    //statict method for checking valid sequence of onedimensional board
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
            else if(a!=c && b!=d) return false;
        }
        return true;
    }
    //statict method for checking valid sequence of two dimensional board
    public static boolean validSeq(BoardArray2D[] array,int size){
        if(size==1){
            return array[0].isSolved();
        }
        for(int i=0; i<size-1;i++){
            int temp1[][]=array[i].getArray();
            int temp2[][]=array[i+1].getArray();
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
            else if(a!=c && b!=d) return false;
        }
        return true;
    }

}
