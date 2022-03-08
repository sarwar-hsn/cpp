
  

public class Driver {
 
  public static void main(String[] args) {

    System.out.println("\n\ntesting boardarray1d\n");
    {
      BoardArray1D obj=new BoardArray1D(3, 3);//creating 2d board
      obj.reset(); //reseting the board 
      System.out.println(obj.toString(obj.getArray()));
      obj.move('L'); //move left
      System.out.println(obj.toString(obj.getArray()));//board after move left
      obj.move('R');//move right
      System.out.println(obj.toString(obj.getArray()));//board after move right
      obj.move('U');//move up
      System.out.println(obj.toString(obj.getArray()));//board after mvoe up
      obj.move('D');//move down 
      System.out.println(obj.toString(obj.getArray()));//board after mvoe down
      obj.writeToFile("init.txt");//save the state of the board to a file
      obj.readFromFile("init.txt");//reading board from the file 
      System.out.println(obj.toString(obj.getArray()));//board after reading from file
      System.out.printf("Checking if the board is solution->");
      System.out.println(obj.isSolved());//checking if the board is solution
      System.out.printf("Contents of cell(1,1)-> ");
      System.out.println(obj.cell(1, 1));//getting element of from cell index
      BoardArray1D temp=new BoardArray1D(2, 2);//creating another object 
      System.out.printf("Checking if the two boards are equal-> ");
      System.out.println(obj.equals(temp));
      System.out.printf("Printing total number of board created -> %d \n",obj.NumberofBoards());
      System.out.printf("Printing last move -> %c \n",obj.getLastMove());
      System.out.printf("Printing total move for (obj) -> %d \n",obj.totalMove);
      System.out.println("\nChecking valid sequence funtion\n");
      BoardArray1D[] array=new BoardArray1D[3];
      BoardArray1D x=new BoardArray1D(3, 3);
      x.reset();
      x.moveLeft();
      array[0]=x;
      BoardArray1D y=new BoardArray1D(3, 3);
      y.reset();
      y.moveLeft();
      y.moveLeft();
      array[1]=y;
      BoardArray1D z=new BoardArray1D(3, 3);
      z.reset();
      z.moveLeft();
      z.moveUp();
      array[2]=z;
      System.out.println("first passing a valid sequence which is: ");
      System.out.println(array[0].toString(array[0].getArray()));
      System.out.println(array[0].toString(array[1].getArray()));
      System.out.println(array[0].toString(array[2].getArray()));
      System.out.printf("valid sequence reusult->");
      System.out.println(BoardArray1D.validSeq(array, 3));
      System.out.println("\nnow passing an invalid sequence which is: ");
      array[0].moveUp();
      System.out.println(array[0].toString(array[0].getArray()));
      System.out.println(array[0].toString(array[1].getArray()));
      System.out.println(array[0].toString(array[2].getArray()));
      System.out.printf("valid sequence reusult->");
      System.out.println(AbstractBoard.validSeq(array, 3));
    }

    System.out.println("\n\ntesting boardarray2d\n");

    {
      BoardArray2D obj=new BoardArray2D(3, 3);//creating 2d board
      obj.reset(); //reseting the board 
      System.out.println(obj.toString(obj.getArray()));
      obj.move('L'); //move left
      System.out.println(obj.toString(obj.getArray()));//board after move left
      obj.move('R');//move right
      System.out.println(obj.toString(obj.getArray()));//board after move right
      obj.move('U');//move up
      System.out.println(obj.toString(obj.getArray()));//board after mvoe up
      obj.move('D');//move down 
      System.out.println(obj.toString(obj.getArray()));//board after mvoe down
      obj.writeToFile("init.txt");//save the state of the board to a file
      obj.readFromFile("init.txt");//reading board from the file 
      System.out.println(obj.toString(obj.getArray()));//board after reading from file
      System.out.printf("Checking if the board is solution->");
      System.out.println(obj.isSolved());//checking if the board is solution
      System.out.printf("Contents of cell(1,1)-> ");
      System.out.println(obj.cell(1, 1));//getting element of from cell index
      BoardArray2D temp=new BoardArray2D(2, 2);//creating another object 
      System.out.printf("Checking if the two boards are equal-> ");
      System.out.println(obj.equals(temp));
      System.out.printf("Printing total number of board created -> %d \n",obj.NumberofBoards());
      System.out.printf("Printing last move -> %c \n",obj.getLastMove());
      System.out.printf("Printing total move for (obj) -> %d \n",obj.totalMove);
      System.out.println("\nChecking valid sequence funtion\n");
      BoardArray2D[] array=new BoardArray2D[3];
      BoardArray2D x=new BoardArray2D(3, 3);
      x.reset();
      x.moveLeft();
      array[0]=x;
      BoardArray2D y=new BoardArray2D(3, 3);
      y.reset();
      y.moveLeft();
      y.moveLeft();
      array[1]=y;
      BoardArray2D z=new BoardArray2D(3, 3);
      z.reset();
      z.moveLeft();
      z.moveUp();
      array[2]=z;
      System.out.println("first passing a valid sequence which is: ");
      System.out.println(array[0].toString(array[0].getArray()));
      System.out.println(array[0].toString(array[1].getArray()));
      System.out.println(array[0].toString(array[2].getArray()));
      System.out.printf("valid sequence reusult->");
      System.out.println(BoardArray1D.validSeq(array, 3));
      System.out.println("\nnow passing an invalid sequence which is: ");
      array[0].moveUp();
      System.out.println(array[0].toString(array[0].getArray()));
      System.out.println(array[0].toString(array[1].getArray()));
      System.out.println(array[0].toString(array[2].getArray()));
      System.out.printf("valid sequence reusult->");
      System.out.println(AbstractBoard.validSeq(array, 3));

    }
    
    
  }
}
