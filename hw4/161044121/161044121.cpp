/*including headers*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
using namespace std;

//this is the class for puzzle 
class NPuzzle{

    public :   //this is the public member section for npuzzle class 

        //all the functions from here are public member of this class
        inline void actionList(); //this function print the options
        void print(){   //this function prints the board
            board.print();  //calling the inner class print function
        }
        void printReport(){  //this function prints the number of move we have done
            cout<<"Total move: "<<board.numberOfMoves()<<endl;
        }
        void readFromFile(string fileName){  //this function read from file by calling inner clss readfromfile function
            board.readFromFile(fileName);
            boardObj.resize(1);
        }
        void writeToFile(string fileName){ //this function write to file by calling inner class writetofile function
            board.writeToFile(fileName);
        }
        void shuffle(int random); //this function shuffles the board 
        void reset(){   //this function shuffles the board to it's original state 
            board.reset();
            boardObj.resize(0);

        }
        void setsize (const int x,const int y){  //this function allocates dynamic array according to the given size 
            board.setsize(x,y);
        }
        bool moveRandom(int moveChoice);  //this funtion does random move 
        void move(char moveChoice){  //this function calls the inner class move function
            board.move(moveChoice);
            boardObj.resize(1);
        }
        inline int rowCol(string fileName,int &x,int &y){ //this function calls the inner class rowCol function
            return board.rowCol(fileName,x,y);
        }
        bool isSolved(){//this function calls inner class function
            return board.isSolved();
        }
        void setMoveAmount(int amount){
            board.setMoveAmount(amount);
        }
         vector<vector<int>> getArray(){
                    return board.getArray();
                }
        vector<vector<int>> getSolutionArray(){
            return  board.getSolutionArray();
        }
        int numberOfMoves(){ //this function returns the amount of legal move done 
            return board.numberOfMoves();
        }
        char getLastMove(){
            return board.getLastMove();
        }
        void solvePuzzle();
    private:
        class Board{
            public:
                //function declaration
                void print();
                void readFromFile(string fileName);
                void writeToFile(string fileName);
                void reset();
                void setsize (const int x,const int y);
                void swap(int &a,int &b);
                void move(char moveChoice);  
                bool moveRight();
                bool moveLeft();
                bool moveUp();
                bool moveDown();
                void locateValue(int) ;                                                                                                                                                                             
                bool isSolved();
                void initBoardFile(int *arr);
                void initSolutionBoardFile();
                int stringtoNUM(string word); 
                inline int rowCol(string fileName,int &x,int &y);
                int numberOfMoves(){ //this function returns the amount of legal move done 
                    return totalMove;
                }
                char getLastMove(){
                    return lastMove;
                }
                bool operator==(const Board &other);
                int operator()(const int x,const int y);

                void setMoveAmount(int amount){
                    totalMove=amount;
                }
                vector<vector<int>> getArray(){
                    return array;
                }
                vector<vector<int>> getSolutionArray(){
                    return solutionArray;
                }
                Board(){};
                Board(vector<vector<int>> initBoard,char x,int i){
                    initBoard=array;
                    lastMove=x;
                    i=totalMove;
                }                
            private:
                fstream file; //related private variables 
                string fileName;
                vector<vector<int>>array;int row,col,x,y,totalMove=0;
                vector<vector<int>>solutionArray;
                char moveChoice,lastMove;
        };
        Board board; //creating a board object 
        vector<Board> boardObj;
};
int main(int argc, char *argv[])
{
    //related variables 
    int x,y,moveAmount=0;char moveChoice;
    string fileName;
    NPuzzle puzzle;
    bool gamePlay=true;
    srand(time(NULL)); //for generating different random numbers 
    if(argc > 1){//if user enters a file in the command line argument then we open it from file
          
        if(puzzle.rowCol(argv[1],x,y)==false){
            return false;
        }
        puzzle.setsize(x,y);
        puzzle.readFromFile(argv[1]);
    }
    //if the user don't give a file name we continue normal gameplay 
    else{
        cout<<"enter size of the board(only, number between 3 to 9):";          
        while(!(cin>>x) || x < 3 || x > 9) //taking user input between 3 to 9
        {
            cout<<"invalid move!!!"<<endl;  //for invalid input exit the program 
            return false;
        }
        y=x;
        puzzle.setsize(x,y); //calling function 
        puzzle.reset();
    }
    while (gamePlay) 
    {
       puzzle.print(); //calling function 
       puzzle.actionList();
       cout<<"enter your move: ";
       cin>>moveChoice; 
       if(!moveChoice){ //in case of invalid move choice we warn the user 
           cout<<"invalid input"<<endl;
       }
       switch (moveChoice)
       {
            case 'R':   //if user wants to go right 
            case 'r':
                puzzle.move('R');
                break;
            case 'L':   //if user wants to go left 
            case 'l':
                puzzle.move('L');
                break;
            case 'U':   //if  user wants to go up 
            case 'u':
                puzzle.move('U');
                break;
            case 'D':   //if user wants to go down 
            case 'd':
                puzzle.move('D');
                break;
            case 'e':
            case 'E':
                cout<<"Enter your file name:";
                cin>> fileName;  //taking file name 
                puzzle.writeToFile(fileName); //wrinting the current state of the game in loadable file shape 
                break;
            case 'v':       //if user wants the computer to solve the game 
            case 'V':
                puzzle.solvePuzzle();       
                break;
            case 's':   //shuffles the board 
            case 'S':
                puzzle.shuffle(x*x);
                puzzle.setMoveAmount(0); //for shuffling we igonore the move 
                break;
            case 't':   //prints a report about how many move has been done 
            case 'T':
                puzzle.printReport();//if user wants to know the amount of move he/she has done so far 
                break;
            case 'o': //here we load the saved game 
            case 'O':
                    cout<<"enter a filename:";
                    cin>>fileName;
                    x=0,y=0;
                   if(puzzle.rowCol(fileName,x,y)==false){
                        gamePlay=false;
                    }
                    puzzle.setsize(x,y);
                    puzzle.readFromFile(fileName);
                    break;
            case 'q':
            case 'Q':
                    cout<<"exiting . . ."<<endl;  //if user press q then he/she will exit from the game 
                    gamePlay=false;
                    break;
            default:
                cout<<"invalid move!!!"<<endl;
                break;
            }
            if(puzzle.isSolved()==true){ // we check if user has won the game after every valid move
                puzzle.print();
                cout<<endl<<"congratulation.you won!!!"<<endl;
                gamePlay=false;  //we set the gameplay value to be false to finish the game 
        }
    }
}

void NPuzzle::solvePuzzle(){
    int i,j,solutionFound=false;
    boardObj.push_back(Board(getArray(),'S',0));
    
}

bool NPuzzle::Board::operator== (const Board &other){
    int i,j,flag=true;
    for (i=0; i<row; i++){
        for (j=0; j< col; j++){
            if(array[i][j]!=other.array[i][j]){
                flag=false;
                break;
            }
        }
    }
    return flag;
}

int NPuzzle::Board::operator()(const int x,const int y){
    if(x>=0 && x<col && y>=0 && y<col){
        return array[x][y];
    }
    else
        exit(1);
}
//this function will shuffle the game board 
void NPuzzle::shuffle(int random)
{
    srand(time(NULL)); //for generating random number 
    int randomMove,moveDone;
    for (int i=0; i < random; i++)//loop goes for n*n times 
    {
        moveDone=false;   //initially we set move done to be false 
        randomMove=rand()%4; //generating number between 0 - 3
        while (moveDone!=true) // till the time we are not getting any valid move we will continue
        {
            switch (randomMove) //we switch to the random move and move according to randomly generate number
            {
            /*if generated random number is 0 we go right , go left for 1, go up for 2,go down for 3.
            if move right, move left function will return a true or false value according to the execution.
            if they move then move_done will be true and we will exit the while loop  and continue the for loop*/
            case 0:
                moveDone=board.moveRight();
                break;
            case 1:
                moveDone=board.moveLeft();
                break;
            case 2:
                moveDone=board.moveUp();
                break;
            case 3:
                moveDone=board.moveDown();
                break;
            }
            randomMove=rand()%4; //generating random number for false move 
        }
    }
    boardObj.resize(1);
}

//this functions does random moves according to generated number 
bool NPuzzle::moveRandom(int moveChoice){
    int flag=false;
    if(moveChoice==0){
        if(board.moveLeft()==true){
            cout<<"intelligent move left"<<endl;
            print();
            flag=true;
        }
    }
    else if(moveChoice==1){
        if(board.moveRight()==true){
        cout<<"intelligent move right"<<endl;
        print();
        flag=true;
        }
    }
        
    else if (moveChoice==2){
        if(board.moveUp()==true){
        cout<<"intelligent move up"<<endl;
        print();
        flag=true;
        }
    }
        
    else{
        if(board.moveDown()==true){
        cout<<"intelligent move down"<<endl;
        print();
        flag=true;
        }
    }  
    boardObj.resize(1);
    return flag;
}

inline int NPuzzle::Board::rowCol(string fileName,int &x,int &y){ //this function will give the size of the row and column of the board that we will get from file 
    file.open(fileName);
    x=0; y=0;
    string line,word;
    if(!file){
        cout<<"Error while opening file"<<endl;
        return false;
    }
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
    return true;
}

void NPuzzle::Board::setsize(int x,int y){  //this function allocates array memory dynamically according to the given size 
    int i;
    row=x;
    col=y; 
}

void NPuzzle::Board::readFromFile(string fileName){//this function is innerclass public member function which will load a saved game 
    array.clear();
    solutionArray.clear();
    int i=0,arr[100];
    file.open(fileName);  
    string word;
    i=0;
    while (file >> word)  //this one will read the file word by word 
    {
        if(word=="bb"){  //if we encounter bb then we replace -1 
            arr[i]=-1;
        }
        else if(word=="-1"){  
            arr[i]=-1;
        }
        else{
            arr[i] = stringtoNUM(word); //else we convert it to integer 
        }
        i++;
    }
    initBoardFile(arr);  //calling function
    initSolutionBoardFile();
    file.close();  
}
int NPuzzle::Board::stringtoNUM(string word){  //this function converts a string to integer 
    int num=0,i;
    for (i=0; word[i]!='\0'; i++){
        num=num*10+word[i]-'0';
    }
    return num;
}

void NPuzzle::Board::initBoardFile(int *arr){  //this function initialize the board that we will get from file 
    int i,j,k=0;
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

void NPuzzle::Board::print(){  //this function prints the game board 

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

void NPuzzle::Board::reset(){ //this function resets  the board to it's initial state 
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

inline void NPuzzle::actionList(){   //this function will print the options that we have 
    cout<<"case insensetive action list"<<endl;
    cout<<"-----------------------------\n";
    cout<<"->"<<"right=r left=l  down=d  up=u  shuffle=s  intelligentMove=i "<<endl;
    cout<<"->"<<"extra intelligence=v total move=t saveGame=e loadsavedGame=o"<<endl;
    cout<<"->"<<"quit game=q"<<endl;
}

void NPuzzle::Board::writeToFile(string fileName){//this funcion is innerclass public member function which will the current game state in loadable file shape 
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

void NPuzzle::Board::initSolutionBoardFile(){  //this function creates a solution board according to the given file 
    int i,j,k=1;
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
bool NPuzzle::Board::isSolved(){ //this function is from innerclass and will return a bool value.win returns true and vice versa 
    int flag=true; //initially we set the flag value to be true
    int i,j;
    return (array==solutionArray); //we return the flag value 
}
//the following functions are for moving in different directions 

bool NPuzzle::Board::moveRight(){
    locateValue(-1); //locate the position of space in the board 
    if (y+1>=col || array[x][y+1]==0){   //checks if the move is valid 
        return false;
    }
    else{           //if move is valid then swaps it's place with the right side place 
        swap(array[x][y+1],array[x][y]);  //calling swap function to swap position
        totalMove++;
        lastMove='R';
        return true;     //if swap is a success then returns true else returns false 
        
    }
}

bool NPuzzle::Board::moveLeft(){
    locateValue(-1); //locate the position of space in the board 
    if (y-1<0 || array[x][y-1]==0){   //checks if the move is valid 
        return false;
    }
    else{           //if move is valid then swaps it's place with the right side place 
        swap(array[x][y-1],array[x][y]);  //calling swap function to swap position
        totalMove++;
        lastMove='L';
        return true;     //if swap is a success then returns true else returns false 
        
    }
}
bool NPuzzle::Board::moveUp(){
    locateValue(-1); //locate the position of space in the board 
    if (x-1<0 || array[x-1][y]==0){   //checks if the move is valid 
        return false;
    }
    else{           //if move is valid then swaps it's place with the right side place 
        swap(array[x-1][y],array[x][y]);  //calling swap function to swap position
        totalMove++;
        lastMove='U';
        return true;     //if swap is a success then returns true else returns false 
        
    }
}

bool NPuzzle::Board::moveDown(){
    locateValue(-1); //locate the position of space in the board 
    if (x+1>=row || array[x+1][y]==0){   //checks if the move is valid 
        return false;
    }
    else{           //if move is valid then swaps it's place with the right side place 
        swap(array[x+1][y],array[x][y]);  //calling swap function to swap position
        totalMove++;
        lastMove='D';
        return true;     //if swap is a success then returns true else returns false 
        
    }
}

//this function will move the blank space according to the given function parameter 
void NPuzzle::Board::move(char moveChoice){
    switch (moveChoice)
    {
        case 'R':   //if user wants to go right 
        case 'r':
            if(moveRight()==false) //we check if the move will be valid if he goes left 
                {
                    cout<<endl<<"invalid move"<<endl; //we warn the user if the move is invalid 
                }
                break;
        case 'L':   //if user wants to go left 
        case 'l':
            if(moveLeft()==false)  //valid move check for right side 
            {
                cout<<endl<<"invalid move"<<endl;
            }
            break;
        case 'U':   //if  user wants to go up 
        case 'u':
            if(moveUp()==false) //valid move check 
            {
                cout<<endl<<"invalid move"<<endl;
            }
            break;
        case 'D':   //if user wants to go down 
        case 'd':
            if(moveDown()==false)
            {
                cout<<endl<<"invalid move"<<endl;
            } 
            break;
    }
}

//this function will take a value and locate it's position 
void NPuzzle::Board::locateValue(int value){
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

void NPuzzle::Board::swap(int &a,int &b){
    int temp=a;//initially the temp holds the value of a
    a=b;//we change the value of a with b
    b=temp;//we set the value of b to temp 

}
