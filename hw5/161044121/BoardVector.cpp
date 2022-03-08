#include "BoardVector.h"
using namespace std;
namespace swr{

    BoardVector::BoardVector(){}
    BoardVector::BoardVector(int row,int col):AbstractBoard(row,col){
        setLastMove('S');
    }

    void BoardVector::print()const{
        int i,j;
        cout<<endl<<endl;
        for (i=0; i<array.size(); i++)//loop till the size 
        {
            for (j=0; j<array[i].size(); j++)
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
    void BoardVector::reset(){
         int i,j,k=1;
        for (i=0; i< row; i++) //we loop throught the array 
        {
            vector<int>temp;
            for (j=0; j< col ; j++)
            {
                if(i==row-1 && j==col-1) //for the last position we place a 0
                {
                    temp.push_back(-1);
                }
                else{
                    temp.push_back(k); //fill interger values 
                }
                k++;
            }
            array.push_back(temp);
            solutionArray.push_back(temp);
        }
    }
    bool BoardVector::moveRight(){
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
    bool BoardVector::moveLeft(){
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
    bool BoardVector::moveUp(){
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
    bool BoardVector::moveDown(){
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
    void BoardVector::locateValue(int value){
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
    bool BoardVector::isSolved(){
        int flag=true; //initially we set the flag value to be true
        int i,j;
        for (i=0; i< array.size();i++){
            for (j=0; j<array[i].size(); j++){
                if(array[i][j]!=solutionArray[i][j]){
                    flag=false;
                    break;
                }
            }
        }
        return flag;
    }
    void BoardVector::initBoardFile(vector<int> arr){
        int i,j,k=0;
        array.clear();
        for (i=0; i< row; i++) //we loop throught the array 
        {
            vector<int> temp;
            for (j=0; j < col; j++)
            {
                temp.push_back(arr[k]);
                k++;
            }
            array.push_back(temp);
        }
    }
    void BoardVector::initSolutionBoardFile(){
        int i,j,k=1;
        solutionArray.clear();
        for (i=0; i < row; i++){
            vector<int>temp;
            for(j=0; j < col; j++){
                if(i==row-1 && j==col-1) //for the last position we place a -1
                {
                    temp.push_back(-1);
                }
                else{
                    if(array[i][j]==0){
                    temp.push_back(0);
                    }
                    else if(array[i][j]!=0){
                        temp.push_back(k);
                        k++;
                    }
                }
            }
            solutionArray.push_back(temp);
        }
    }
    void BoardVector::writeToFile(string fileName){
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
    int BoardVector::operator()(int x,int y){
        if(x>=0 && x<col && y>=0 && y<col){
            return array[x][y];
        }
        else
            exit(1);
    }
    bool BoardVector::operator== (const BoardVector &other){
        int flag=true;
        for (int i=0; i<this->array.size(); i++){
            for (int j=0; j<this->array[i].size(); j++){
                if(this->array[i][j]!=other.array[i][j]){
                    flag=false;
                    break;
                }
            }
        }
        return flag;
    }

}