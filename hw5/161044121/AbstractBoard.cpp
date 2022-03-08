#include "AbstractBoard.h"
namespace swr{
    AbstractBoard::AbstractBoard(){
        totalMove=0;
        row=0;
        col=0;
        lastMove='S';
        boardCreated+=1;
    }
    AbstractBoard::AbstractBoard(int x,int y):row(x),col(y){
        lastMove='S';
        totalMove=0;
        boardCreated+=1;
    }
    void AbstractBoard::setSize(int x,int y){
        row=x;
        col=y;
    }
    void AbstractBoard::swap(int &a,int &b){
        int temp=a;//initially the temp holds the value of a
        a=b;//we change the value of a with b
        b=temp;//we set the value of b to temp 
    }
    void AbstractBoard::move(char moveChoice){
        switch (moveChoice)
        {
            case 'R':   //if user wants to go right 
            case 'r':
                if(moveRight()==false) //we check if the move will be valid if he goes left 
                    {
                        cout<<endl<<"invalid move"<<endl; //we warn the user if the move is invalid 
                    }
                else
                {
                    setLastMove('R');
                    totalMove++;
                }
                
                    break;
            case 'L':   //if user wants to go left 
            case 'l':
                if(moveLeft()==false)  //valid move check for right side 
                {
                    cout<<endl<<"invalid move"<<endl;
                }
                else
                {
                    setLastMove('L');
                    totalMove++;
                }
                break;
            case 'U':   //if  user wants to go up 
            case 'u':
                if(moveUp()==false) //valid move check 
                {
                    cout<<endl<<"invalid move"<<endl;
                    totalMove++;
                }
                else
                {
                    setLastMove('U');
                }
                break;
            case 'D':   //if user wants to go down 
            case 'd':
                if(moveDown()==false)
                {
                    cout<<endl<<"invalid move"<<endl;
                } 
                else
                {
                    setLastMove('D');
                    totalMove++;
                }
                break;
            case 'S':
            case 's':
                break;
        }
    }

void AbstractBoard::readFromFile(string fName){//this function is innerclass public member function which will load a saved game 
    vector<int> arr;
    file.open(fName);  
    string word;
    while (file >> word)  //this one will read the file word by word 
    {
        if(word=="bb"){  //if we encounter bb then we replace -1 
            arr.push_back(-1);
        }
        else if(word=="-1"){  
            arr.push_back(-1);
        }
        else{
            arr.push_back(stringtoNUm(word));
        }
    }
    file.close();  
    rowCol(fName);
    initBoardFile(arr);  //calling function
    initSolutionBoardFile();
    arr.clear();
    
}

int AbstractBoard::stringtoNUm(string word){  //this function converts a string to integer 
    int num=0,i;
    for (i=0; word[i]!='\0'; i++){
        num=num*10+word[i]-'0';
    }
    return num;
}

int AbstractBoard::rowCol(string fileName){
    file.open(fileName);
    string line,word;
    if(!file){
        cout<<"Error while opening file"<<endl;
        return false;
    }
    x=0; y=0;
    while (getline(file,line)){ 
        x++;
    }
    file.close();
    file.open(fileName);
    while (file >> word) {
        y++;
    }
    file.close();
    y/=x;
    row=x;
    col=y;
    return true;
}

int AbstractBoard::numberofBoards(){ //total number of objects created so far. static in every context
    return boardCreated;
}
int AbstractBoard::numberofMoves(){ //returns total move a obj hase made
    return totalMove;
}

//***********************setters & getters**************************

    void AbstractBoard::setRow(int newRow){
        row=newRow;
    }
    void AbstractBoard::setCol(int newCol){
        col=newCol;
    }
    void AbstractBoard::setX(int newX){
        x=newX;
    }
    void AbstractBoard::setY(int newY){
        y=newY;
    }
    void AbstractBoard::setMoveChoice(char newMoveChoice){
        moveChoice=newMoveChoice;
    }
    void AbstractBoard::setLastMove(char newMove){
        lastMove=newMove;
    }
    void AbstractBoard::setFileName(string newFileName){
        fileName=newFileName;
    }

    int AbstractBoard::getRow()const{
        return row;
    }
    int AbstractBoard::getCol()const{
        return col;
    }
    int AbstractBoard::getX()const{
        return x;
    }
    int AbstractBoard::getY()const{
        return y;
    }
    char AbstractBoard::getMoveChoice()const{
        return moveChoice;
    }
    char AbstractBoard::getLastMove()const{ //this function will return the last move
        return lastMove;
    }
    string AbstractBoard::getFileName()const{
        return fileName;
    }

    int AbstractBoard::boardCreated=0;

}