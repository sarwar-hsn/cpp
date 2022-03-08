#include "BoardArray2D.h"
namespace swr{
    //*********CONSTRUCTORS***********
    BoardArray2D::BoardArray2D(){}
    BoardArray2D::BoardArray2D(int row,int col):AbstractBoard(row,col){
        lastMove='S';
        array=new int*[row];
        solutionArray=new int*[row];
        for (int i=0; i<row; i++){
            array[i]=new int[col];
            solutionArray[i]=new int[col];
        }
    }
    //***********BIG THREE************
    //copy constructor
    BoardArray2D::BoardArray2D(const BoardArray2D& other):AbstractBoard(other.row,other.col){ 
        this->lastMove=other.lastMove;
        this->x=other.x;this->y=other.y;
        this->fileName=other.fileName;
        this->array=new int*[other.row];
        this->solutionArray=new int*[other.row];
        for(int i=0; i<row;i++){
            this->array[i]=new int[col];
            this->solutionArray[i]=new int[col];
        }
        for(int i=0; i<row; i++){
            for (int j=0; j<col;j++){
                this->array[i][j]=other.array[i][j];
                this->solutionArray[i][j]=other.solutionArray[i][j];
            }
        }
    }

    BoardArray2D& BoardArray2D::operator=(const BoardArray2D& other){
        this->row=other.row;
        this->col=other.col;
        this->lastMove=other.lastMove;
        this->x=other.x;this->y=other.y;
        this->fileName=other.fileName;
        this->array=new int*[other.row];
        this->solutionArray=new int*[other.row];
        for(int i=0; i<row;i++){
            this->array[i]=new int[col];
            this->solutionArray[i]=new int[col];
        }
        for(int i=0; i<row; i++){
            for (int j=0; j<col;j++){
                this->array[i][j]=other.array[i][j];
                this->solutionArray[i][j]=other.solutionArray[i][j];
            }
        }
        return *this;
    }

    BoardArray2D::~BoardArray2D(){
        delete[] array;
        delete[] solutionArray;
    }






    void BoardArray2D::print()const{  //this function prints the game board 
        int i,j;
        cout<<endl<<endl;
        for (i=0; i<row; i++)//loop till the size 
        {
            for (j=0; j<col; j++)
            {
                // cout.setf(ios::left); //aligning the element left side of screen
                // cout.width(10); //setting the gap between elements 
                if(array[i][j]==0){
                    cout<<"00   ";
                } 
                else if(array [i][j]==-1){
                    cout<<"__   ";
                }
                else if(array [i][j] >0 && array [i][j]<=9){
                    cout<<'0'<<array[i][j]<<"   ";
                }
                else{
                    cout<<array[i][j]<<"   ";
                }
            }
            cout<<endl<<endl;
        }
    }
    void BoardArray2D::reset(){ //this function resets  the board to it's initial state 
        int i,j,k=1;
        for (i=0; i< row; i++) //we loop throught the array 
        {
            for (j=0; j< col ; j++)
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


    bool BoardArray2D::moveRight(){
        int flag;
        locateValue(-1); //locate the position of space in the board 
        if (y+1>=col || array[x][y+1]==0){   //checks if the move is valid 
            flag=false;
        }
        else{           //if move is valid then swaps it's place with the right side place 
            swap(array[x][y+1],array[x][y]);  //calling swap function to swap position
            flag=true;     //if swap is a success then returns true else returns false 
            
        }
        return flag;
    }
    bool BoardArray2D::moveLeft(){
        int flag;
        locateValue(-1); //locate the position of space in the board 
        if (y-1<0 || array[x][y-1]==0){   //checks if the move is valid 
            flag=false;
        }
        else{           //if move is valid then swaps it's place with the right side place 
            swap(array[x][y-1],array[x][y]);  //calling swap function to swap position
            flag=true;     //if swap is a success then returns true else returns false 
            
        }
        return flag;
    }
    bool BoardArray2D::moveUp(){
        int flag;
        locateValue(-1); //locate the position of space in the board 
        if (x-1<0 || array[x-1][y]==0){   //checks if the move is valid 
            flag=false;
        }
        else{           //if move is valid then swaps it's place with the right side place 
            swap(array[x-1][y],array[x][y]);  //calling swap function to swap position
            flag=true;     //if swap is a success then returns true else returns false 
            
        }
        return flag;
    }
    bool BoardArray2D::moveDown(){
        int flag;
        locateValue(-1); //locate the position of space in the board 
        if (x+1>=row || array[x+1][y]==0){   //checks if the move is valid 
            flag=false;
        }
        else{           //if move is valid then swaps it's place with the right side place 
            swap(array[x+1][y],array[x][y]);  //calling swap function to swap position
            flag=true;     //if swap is a success then returns true else returns false 
        }
        return flag;
    }
    void BoardArray2D::locateValue(int value){
        int i,j;
        for (i=0; i< row; i++)
        {
            for (j=0; j<col; j++)
            {
                if (array[i][j]==value)
                {
                    x=i;
                    y=j;
                }
            }
        }
    }
    bool BoardArray2D::isSolved(){
        int flag=true; //initially we set the flag value to be true
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
    void BoardArray2D::initBoardFile(vector<int> arr){
        int i,j,k=0;
        for (i=0; i< row; i++) //we loop throught the array 
        {
            for (j=0; j < col; j++)
            {
                array[i][j]=arr[k];
                k++;
            }
        }
    }
    void BoardArray2D::initSolutionBoardFile(){
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
    void BoardArray2D::writeToFile(string fileName){
        int i;
        file.open (fileName,ios::out ); //opening the file in writing mode 
        for (i=0; i<row; i++ ){  //this loop writes in the file 
            for (int j=0; j< col; j++){
                file << array[i][j]<<" ";
            }
            file << endl;
        }
        file.close();  //closing file 
    }
    int BoardArray2D::operator()(int x,int y){
        if(x>=0 && x<col && y>=0 && y<col){
            return array[x][y];
        }
        else
            exit(1);
    }
    bool BoardArray2D::operator== (const BoardArray2D &other){
        int flag=true;
        for (int i=0; i<this->row; i++){
            for (int j=0; j<this->col; j++){
                if(this->array[i][j]!=other.array[i][j]){
                    flag=false;
                    break;
                }
            }
        }
        return flag;
    }
}