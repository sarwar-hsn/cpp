/*including headers*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
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
            cout<<"Total move: "<<board.moveAmount()<<endl;
        }
        void readFromFile(string fileName){  //this function read from file by calling inner clss readfromfile function
            board.readFromFile(fileName);
        }
        void writeToFile(string fileName){ //this function write to file by calling inner class writetofile function
            board.writeToFile(fileName);
        }
        void shuffle(int **array,int x,int y); //this function shuffles the board 
        void reset(){   //this function shuffles the board to it's original state 
            board.reset();
        }
        void setsize (const int x,const int y){  //this function allocates dynamic array according to the given size 
            board.setsize(x,y);
        }
        bool moveRandom(int moveChoice);  //this funtion does random move 
        void moveIntelligent(int **array,int **solution_array, int x,int y);  //this function makes an intelligent move 
        int alreadyPositioned(int **array,int **solution_array,int x,int y,int value); //function declaration
        void move(char moveChoice){  //this function calls the inner class move function
            board.move(moveChoice);
        }
        void locateValueIntellegence(int **array,int x,int y,int &row,int &col,int value);//function declaration
        void solvePuzzle(int **array,int **solution_array, int x,int y,bool gamePlay);//this function solves the board to solution

        int** arr(){  //this function calls a inner class function which ulimately return the array mallocated for board 
            return (board.arr());
        }
        int **solarr(){ //this function does the same thing like arr() function
            return (board.solarr());
        }
        inline int rowCol(string fileName,int &x,int &y){ //this function calls the inner class rowCol function
            return board.rowCol(fileName,x,y);
        }
        void fillPositionCal(int *array,int value); //function declaration
        bool isSolved(int **array1,int **array2,int x,int y){//this function calls inner class function
            return board.isSolved(array1,array2,x,y);
        }
        void setMoveAmount(int amount){
            board.setMoveAmount(amount);
        }
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
                bool isSolved(int **array,int **solution_array,int x,int y);
                void initBoardFile(int *arr);
                void initSolutionBoardFile();
                int stringtoNUM(string word); 
                inline int rowCol(string fileName,int &x,int &y);
                int **arr(){  //this function returns an array 
                    return array;
                }
                int **solarr(){ // this function returns the solution array from private member of board class
                    return solutionArray;
                }
                int moveAmount(){ //this function returns the amount of legal move done 
                    return totalMove;
                }
                void setMoveAmount(int amount){
                    totalMove=amount;
                }
            private:
                fstream file; //related private variables 
                string fileName;
                int **array,**solutionArray,row,col,x,y,totalMove=0;
                char moveChoice;
        };
        Board board; //creating a board object 
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
                if(puzzle.isSolved(puzzle.arr(),puzzle.solarr(),x,y)==true) //we are checking if the user has won the game
                    gamePlay=false;
                break;
            case 'L':   //if user wants to go left 
            case 'l':
                puzzle.move('L');
                if(puzzle.isSolved(puzzle.arr(),puzzle.solarr(),x,y)==true)
                    gamePlay=false;
                break;
            case 'U':   //if  user wants to go up 
            case 'u':
                puzzle.move('U');
                if(puzzle.isSolved(puzzle.arr(),puzzle.solarr(),x,y)==true)
                    gamePlay=false;
                break;
            case 'D':   //if user wants to go down 
            case 'd':
                puzzle.move('D');
                if(puzzle.isSolved(puzzle.arr(),puzzle.solarr(),x,y)==true)
                    gamePlay=false;
                break;
            case 'e':
            case 'E':
                cout<<"Enter your file name:";
                cin>> fileName;  //taking file name 
                puzzle.writeToFile(fileName); //wrinting the current state of the game in loadable file shape 
                break;
            case 'i':
            case 'I':
                puzzle.moveIntelligent(puzzle.arr(),puzzle.solarr(),x,y); //calling intellegent move 
                if(puzzle.isSolved(puzzle.arr(),puzzle.solarr(),x,y)==true)
                    gamePlay=false;
                break;
            case 'v':       //if user wants the computer to solve the game 
            case 'V':       
                puzzle.solvePuzzle(puzzle.arr(),puzzle.solarr(),x,y,gamePlay);
                if(puzzle.isSolved(puzzle.arr(),puzzle.solarr(),x,y)==true)
                    gamePlay=false;
                break;
            case 's':   //shuffles the board 
            case 'S':
                puzzle.shuffle(puzzle.arr(),x,y);
                puzzle.setMoveAmount(0); //for shuffling we igonore the move 
                break;
            case 't':   //prints a report about how many move has been done 
            case 'T':
                puzzle.printReport();//if user wants to know the amount of move he/she has done so far 
                break;
            case 'o': //here we load the saved game 
            case 'O':
                    free(puzzle.arr());//we free the array and take a filename from user 
                    cout<<"enter a filename:";
                    cin>>fileName;
                    puzzle.rowCol(fileName,x,y);
                    puzzle.setsize(x,y);
                    puzzle.readFromFile(fileName);  //loading the game from a saved game state
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
            if(gamePlay==false){ // we check if user has won the game after every valid move
                puzzle.print();
                cout<<endl<<"congratulation.you won!!!"<<endl;
                gamePlay=false;  //we set the gameplay value to be false to finish the game 
            }
    }
    
}
void NPuzzle::moveIntelligent(int **array,int **solution_array, int x,int y)
{
    int i,j,row=0,col=0,row2=0,col2=0,moveValue=0,count=0;
    /*if the blank space value is not in the side values then we find the co-ordinate of the actual value 
    and we will move our move in that direction*/
    locateValueIntellegence(array,x,y,row,col,-1); //locating blank space 
    moveValue=solution_array[row][col];//locating which value is supposed to be in that postion 
    locateValueIntellegence(array,x,y,row2,col2,moveValue);//finding where the value is now by finding it's cordinate 
    if (row==row2){ //if in the same row 
        if (col < col2){   //we check column values and goes right left accordingly
            board.moveRight();
            cout<<"intelligent move right"<<endl;
        }
        else{
            board.moveLeft();
            cout<<"intelligent move left"<<endl;
        }
    }
    else if(col==col2){ //if column are the same then we move according to row value 
        if (row > row2){
            board.moveUp();
            cout<<"intelligent move up"<<endl;
        }
        else{
            board.moveDown();
            cout<<"intelligent move down"<<endl;
        }
    }
    /*if the value is in corner then we found out in which way we should go , like Upright corner Upleftcorner
    Downrightcorner Downleftcorner. then we select a path to go there*/ 
    else if (row > row2 && col < col2){  //value is in uprightcorner direction 
        if(alreadyPositioned(array,solution_array,x,y,array[row][col+1])==false){ /*if our designed destination has no perfectly placed value then we
                                                                                    go in that direction. same logic holds for the rest of the code but 
                                                                                    for different direction*/ 
            board.moveRight();
            cout<<"intelligent move right"<<endl;
        }
        else if(alreadyPositioned(array,solution_array,x,y,array[row-1][col])==false){ 
            board.moveUp();
            cout<<"intelligent move up"<<endl;
        }
        else{
            board.moveRight();
            cout<<"intelligent move right"<<endl;
        }
    }
    else if (row > row2 && col > col2){ //value is in upleftcorner direction 

        if(alreadyPositioned(array,solution_array,x,y,array[row-1][col])==false){
            board.moveUp();
            cout<<"intelligent move up"<<endl;
        }
        else if(alreadyPositioned(array,solution_array,x,y,array[row][col-1])==false){
            board.moveLeft();
            cout<<"intelligent move left"<<endl;
        }
        else{
            board.moveLeft();
            cout<<"intelligent move left"<<endl;
        }
    }
    else if (row < row2 && col > col2){ //downleftcorner direction
        if(alreadyPositioned(array,solution_array,x,y,array[row-1][col])==false){
            board.moveDown();
            cout<<"intelligent move down"<<endl;
        }
        else if(alreadyPositioned(array,solution_array,x,y,array[row][col-1])==false){
            board.moveDown();
            cout<<"intelligent move down"<<endl;
        }
        else{
            board.moveUp();
            cout<<"intelligent move up"<<endl;
        }
    }
    else if (row < row2 && col < col2){//downright corner direction 
        if(alreadyPositioned(array,solution_array,x,y,array[row][col+1])==false){
            board.moveRight();
            cout<<"intelligent move right"<<endl;
        }
        else if(alreadyPositioned(array,solution_array,x,y,array[row+1][col])==false){
            board.moveDown();
            cout<<"intelligent move down"<<endl;
        }
        else{
            board.moveRight();
            cout<<"intelligent move right"<<endl;
        }
    }
}

inline void NPuzzle::actionList(){   //this function will print the options that we have 
    cout<<"case insensetive action list"<<endl;
    cout<<"-----------------------------\n";
    cout<<"->"<<"right=r left=l  down=d  up=u  shuffle=s  intelligentMove=i "<<endl;
    cout<<"->"<<"extra intelligence=v total move=t saveGame=e loadsavedGame=o"<<endl;
    cout<<"->"<<"quit game=q"<<endl;
}

inline int NPuzzle::Board::rowCol(string fileName,int &x,int &y){ //this function will give the size of the row and column of the board that we will get from file 
    if(!file){  //if failes to open the file 
        cout<<"error!!! couldn't open the file";
    }
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
    row=x;
    col=y;
    return true;
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
void NPuzzle::Board::readFromFile(string fileName){//this function is innerclass public member function which will load a saved game 
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
    file.close();  
}
void NPuzzle::Board::initBoardFile(int *arr){  //this function initialize the board that we will get from file 
    int i,j,k=0;
    for (i=0; i< row; i++) //we loop throught the array 
    {
        for (j=0; j < col ; j++)
        {
            array[i][j]=arr[k]; //fill interger values 
            k++;
        }
    }

}
void NPuzzle::Board::initSolutionBoardFile(){  //this function creates a solution board according to the given file 
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
bool NPuzzle::Board::isSolved(int **array1,int **array2,int x,int y){ //this function is from innerclass and will return a bool value.win returns true and vice versa 
    int flag=true; //initially we set the flag value to be true
    int i,j;
    for (i=0; i<x ; i++)  //we run a loop between the elements of two array 
    {      
        for (j=0; j<y; j++)
        {
            if(array1[i][j]!=array2[i][j])//if they don't match then we exit as user didn't win the game 
            {
                flag=false; //we set the flag value to be false 
                break;
            }
        }
    }
    return flag; //we return the flag value 
}
void NPuzzle::Board::print(){  //this function prints the game board 

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
void NPuzzle::Board::reset(){ //this function resets  the board to it's initial state 
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

void NPuzzle::Board::setsize(int x,int y){  //this function allocates array memory dynamically according to the given size 
    int i;
    row=x;
    col=y;
    //mallocating dynamic array 
    array=(int**)malloc(row*sizeof(int*));
    for (i=0; i<row; i++)
    {
        array[i]=(int*)malloc(col*sizeof(int));
    }
    solutionArray=(int**)malloc(row*sizeof(int*));
    for (i=0; i<row; i++)
    {
        solutionArray[i]=(int*)malloc(col*sizeof(int));
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

//the following functions are for moving in different directions 

bool NPuzzle::Board::moveRight(){
    locateValue(-1); //locate the position of space in the board 
    if (y+1>=col || array[x][y+1]==0){   //checks if the move is valid 
        return false;
    }
    else{           //if move is valid then swaps it's place with the right side place 
        swap(array[x][y+1],array[x][y]);  //calling swap function to swap position
        totalMove++;
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
        return true;     //if swap is a success then returns true else returns false 
        
    }
}
//this function is innerclass function which finds the co-ordinate of blank space and returns 
void NPuzzle::locateValueIntellegence(int **array,int x,int y,int &row,int &col,int value){
    int i,j;
    for (i=0; i< x; i++)
    {
        for (j=0; j<y; j++)
        {
            if (array[i][j]==value)
            {
                row=i;
                col=j;
            }
        }
    }
}

//this function will take a coodinate and check if the value is already in right position
int NPuzzle::alreadyPositioned(int **array,int **solution_array,int x,int y,int value)
{
    int row ,col,row2,col2,flag=false;
    locateValueIntellegence(array,x,y,row,col,value);//locating the value in gameplay board
    locateValueIntellegence(solution_array,x,y,row2,col2,solution_array[row][col]);//locating the value in solution board
    if(row==row2 && col==col2){//checking if same or not 
        flag=true;
    }
    return flag;
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

//this function will shuffle the game board 
void NPuzzle::shuffle(int **array,int x,int y)
{
    srand(time(NULL)); //for generating random number 
    int randomMove,moveDone;
    for (int i=0; i < x*y; i++)//loop goes for n*n times 
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

}

int NPuzzle::Board::stringtoNUM(string word){  //this function converts a string to integer 
    int num=0,i;
    for (i=0; word[i]!='\0'; i++){
        num=num*10+word[i]-'0';
    }
    return num;
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
    
    return flag;
}

//this function will solve the board to a solution 
void NPuzzle::solvePuzzle(int **array,int **solution_array, int x,int y,bool gamePlay){
    int postionCal[3]={-2,-2,-2};
    int i,moveChoice=0,stuck,row2=0,col2=0;
    decltype(i) j;
    auto count=0;
    stuck=0;
    while (gamePlay!=false)   //we keep playing until we find a solution 
    {
        int stuckCount=0;
        moveIntelligent(array,solution_array,x,y); //calling intelligent move funtion 
        count++;
        print();
        locateValueIntellegence(array,x,y,row2,col2,-1); //we find the position of the the blank 
        fillPositionCal(postionCal,solution_array[row2][col2]); //we put the value of that postion in the array
        for ( i=0; i< 3; i++){
            if(postionCal[i]!=-2){
                stuckCount++;
            }
        }
        if(stuckCount==3){
            if(postionCal[0]==postionCal[2] && postionCal[2]!=-2){
                stuck++;
                }
            else{
                for (i=0; i< 3; i++){
                postionCal[i]=-2;
                }
               // stuckCount=0;
            }
        }
        if(stuck!=0){
            stuck=0;
            i=0; 
            while (i!=5) //then we do 5 random moves 
            {
                moveChoice=rand()%4;
                if(moveRandom(moveChoice)==true){
                    i++;
                    count++;
                }
                if(board.isSolved(array,solution_array,x,y)==true){ // we check if user has won 
                cout<<"Number of steps to solve is:"<<count<<endl;
                gamePlay=false;  //we set the gameplay value to be false to finish the game 
                break;
                }
            }

        }
         
    }
}
void NPuzzle::fillPositionCal(int *array,int value){  //this function will take an array and a value and put the value in the array 
    int i;
    for (i=0; i < 3; i++){
        if (array[i]==-2)
        {
            array[i]=value;
            break;
        }
    }
}