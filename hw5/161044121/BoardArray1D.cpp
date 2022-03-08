#include "BoardArray1D.h"
namespace swr{
    BoardArray1D::BoardArray1D(){
    }
    BoardArray1D::BoardArray1D(int row,int col):AbstractBoard(row,col){
        lastMove='S';
        array=new int[row*col];
        solutionArray=new int[row*col];
    }

    //*********BIG THREE*********
    BoardArray1D::BoardArray1D(const BoardArray1D& other):AbstractBoard(other.row,other.col){ 
        this->lastMove=other.lastMove;
        this->x=other.x;this->y=other.y;
        this->fileName=other.fileName;
        this->array=new int[other.row*other.col];
        this->solutionArray=new int[other.row*other.col];
        vector<vector<int>> temp1=convert(other.array);
        vector<vector<int>> temp2=convert(other.solutionArray);
        convertBack(temp1,this->array);
        convertBack(temp2,this->solutionArray);
    }

     BoardArray1D& BoardArray1D::operator=(const BoardArray1D& other){
        this->row=other.row;
        this->col=other.col;
        this->lastMove=other.lastMove;
        this->x=other.x;this->y=other.y;
        this->fileName=other.fileName;
        this->array=new int[other.row*other.col];
        this->solutionArray=new int[other.row*other.col];
        vector<vector<int>> temp1=convert(other.array);
        vector<vector<int>> temp2=convert(other.solutionArray);
        convertBack(temp1,this->array);
        convertBack(temp2,this->solutionArray);
        return *this;
    }

    BoardArray1D::~BoardArray1D(){
        delete[] array;
        delete[] solutionArray;
    }

    void BoardArray1D::print()const{
        vector<vector<int>> temp=convert(array);
        int i,j;
        cout<<endl<<endl;
        for (i=0; i<temp.size(); i++)//loop till the size 
        {
            for (j=0; j<temp[i].size(); j++)
            {
                // cout.setf(ios::left); //aligning the element left side of screen
                // cout.width(10); //setting the gap between elements 
                if(temp[i][j]==0){
                    cout<<"00   ";
                } 
                else if(temp [i][j]==-1){
                    cout<<"__   ";
                }
                else if(temp [i][j] >0 && temp [i][j]<=9){
                    cout<<'0'<<temp[i][j]<<"   ";
                }
                else{
                    cout<<temp[i][j]<<"   ";
                }
            }
            cout<<endl<<endl;
        }
        temp.clear();
    }
    void BoardArray1D::reset(){
        int i,j,k=1;
        for (i=0; i< row*col; i++) //we loop throught the array 
        {
            array[i]=k;
            k++;
            if(i==(row*col)-1){
                array[i]=-1;
            }
        }
    }
    bool BoardArray1D::moveRight(){
        int flag;
        vector<vector<int>> temp=convert(array);
        locateValue(-1); //locate the position of space in the board 
        if (y+1>=col || temp[x][y+1]==0){   //checks if the move is valid 
            flag=false;
        }
        else{           //if move is valid then swaps it's place with the right side place 
            swap(temp[x][y+1],temp[x][y]);  //calling swap function to swap position
            convertBack(temp,array);
            totalMove++;
            flag=true;     //if swap is a success then returns true else returns false 
            
        }
        return flag;
    }
    bool BoardArray1D::moveLeft(){
        int flag;
        vector<vector<int>> temp=convert(array);
        locateValue(-1); //locate the position of space in the board 
        if (y-1<0 || temp[x][y-1]==0){   //checks if the move is valid 
            flag=false;
        }
        else{           //if move is valid then swaps it's place with the right side place 
            swap(temp[x][y-1],temp[x][y]);  //calling swap function to swap position
            convertBack(temp,array);
            totalMove++;
            flag=true;     //if swap is a success then returns true else returns false 
            
        }
        return flag;
    }
    bool BoardArray1D::moveUp(){
        int flag;
        vector<vector<int>> temp=convert(array);
        locateValue(-1); //locate the position of space in the board 
        if (x-1<0 || temp[x-1][y]==0){   //checks if the move is valid 
            flag=false;
        }
        else{           //if move is valid then swaps it's place with the right side place 
            swap(temp[x-1][y],temp[x][y]);  //calling swap function to swap position
            convertBack(temp,array);
            totalMove++;
            flag=true;     //if swap is a success then returns true else returns false 
            
        }
        return flag;
    }
    bool BoardArray1D::moveDown(){
        int flag;
        vector<vector<int>> temp=convert(array);
        locateValue(-1); //locate the position of space in the board 
        if (x+1>=row || temp[x+1][y]==0){   //checks if the move is valid 
            flag=false;
        }
        else{           //if move is valid then swaps it's place with the right side place 
            swap(temp[x+1][y],temp[x][y]);  //calling swap function to swap position
            convertBack(temp,array);
            totalMove++;
            flag=true;     //if swap is a success then returns true else returns false 
        }
        return flag;
    }
    void BoardArray1D::locateValue(int value){
        vector<vector<int>> temp=convert(array);
        int i,j;
        for (i=0; i< row; i++)
        {
            for (j=0; j<col; j++)
            {
                if (temp[i][j]==value)
                {
                    x=i;
                    y=j;
                }
            }
        }
    }
    bool BoardArray1D::isSolved(){
        vector<vector<int>> temp1=convert(array);
        vector<vector<int>> temp2=convert(solutionArray);
        int flag=true; //initially we set the flag value to be true
        int i,j;
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
    void BoardArray1D::initBoardFile(vector<int> arr){
        vector<vector<int>> temp;
        int i,j,k=0;
        for (i=0; i< row; i++) //we loop throught the array 
        {
            vector<int> x;
            for (j=0; j < col; j++)
            {
                x.push_back(arr[k]);
                k++;
            }
            temp.push_back(x);
        }
        convertBack(temp,array);
    }
    void BoardArray1D::initSolutionBoardFile(){
        int i,j,k=1;
        vector<vector<int>> temp1=convert(solutionArray);
        vector<vector<int>> temp2=convert(solutionArray);
        for (i=0; i < row; i++){
            vector<int>x;
            for(j=0; j < col; j++){
                if(i==row-1 && j==col-1) //for the last position we place a -1
                {
                    x.push_back(-1);
                }
                else{
                    if(temp2[i][j]==0){
                    x.push_back(0);
                    }
                    else if(temp2[i][j]!=0){
                        x.push_back(k);
                        k++;
                    }
                }
            }
            temp1.push_back(x);
        }
        convertBack(temp1,solutionArray);
    }
    void BoardArray1D::writeToFile(string fileName){
        int i;
        vector<vector<int>> temp=convert(array);
        file.open (fileName,ios::out ); //opening the file in writing mode 
        for (i=0; i<row; i++ ){  //this loop writes in the file 
            for (int j=0; j< col; j++){
                file << temp[i][j]<<" ";
            }
            file << endl;
        }
        file.close();  //closing file 
    }
    int BoardArray1D::operator()(int x,int y){
        vector<vector<int>> temp=convert(array);
        if(x>=0 && x<col && y>=0 && y<col){
            return temp[x][y];
        }
        else
            exit(1);
    }
    vector<vector<int>> BoardArray1D::convert(int* array)const{
        vector<vector<int>> temp;
        int k=0; 
        for(int i=0; i<row; i++){
            vector<int> x;
            for(int j=0; j<col;j++){
                x.push_back(array[k]);
                k++;
            }
            temp.push_back(x);
        }
        return temp;
    }
    void BoardArray1D::convertBack(vector<vector<int>> temp,int *arr){
        int k=0;
        for (int i=0;i<row;i++ ){
            for (int j=0; j<col; j++){
                arr[k]=temp[i][j];
                k++;
            }
        }
    }
    bool BoardArray1D::operator==(const BoardArray1D& other){
        int flag=true;
        vector<vector<int>> temp1=convert(this->array);
        vector<vector<int>> temp2=convert(other.array);
        for (int i=0; i<temp1.size(); i++){
            for (int j=0; j<temp1[i].size(); j++){
                if(temp1[i][j]!=temp2[i][j]){
                    flag=false;
                    break;
                }
            }
        }
        return flag;
    }
}