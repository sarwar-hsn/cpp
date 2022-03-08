/*including headers*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

/*function declaration*/
inline void action_list();
void load_file(fstream& infile,int **board,string fileName,int row,int col);
int stringtoNUM(string word);
void init_board(int **array,int x,int y);
void init_board_file(int **array,int *arr,int row,int col);
void init_solutionboard_file(int **array1,int **array2,int x,int y);
inline void print_board(int **array,const int row,const int col);
void locate_value(int **array,int x,int y,int &row,int &col,int value);
int alreadyPositioned(int **array,int **solution_array,int x,int y,int value);
int move_right(int **array,int x,int y);
int move_left(int **array,int x,int y);
int move_up(int **array,int x,int y);
int move_down(int **array,int x,int y);
void swap(int &a,int &b);
void shuffle(int **array,int x,int y);
int check_win(int **array1,int **array2,int x,int y);
inline void rowCol(fstream& input,int &row,int &col,string fileName);
void intelligent_move(int **array,int **solution_array, int x,int y);
void fill_positionCal(int *array,int value);

int main(int argc, char *argv[]){
    fstream file;string fileName;
    auto i=0; //the type of the variable will be what variable is presenting at the right side. In this case it's integer
    decltype(i) row,col,**array,**solution_array,moveAmount=0,stuck; //here we said type of this variable will be the same type as variable i 
    int postionCal[3]={-1,-1,-1};//this array will help us to find if we get stucked in intelligent part 
    char move_choice; 
    bool gamePlay=true; 
   
    if(argc > 1){//if user enters a file in the command line argument then we open it from file
        fileName=argv[1];//we take the name of the file from command line 
        rowCol(file,row,col,fileName); //calculating row and column of the board imported from file
        col/=row;

        array=(int**)malloc(row*sizeof(int*)); //creating array according to the size 
        for (i=0; i<row; i++)
        {
            array[i]=(int*)malloc(col*sizeof(int));
        }
        solution_array=(int**)malloc(row*sizeof(int*));
        for (i=0; i<row; i++)
        {
            solution_array[i]=(int*)malloc(col*sizeof(int));
        }

        load_file(file,array,fileName,row,col);//calling funtions 
        init_solutionboard_file(array,solution_array,row,col);
    }
    //if the user don't give a file name we continue normal gameplay 
        else{
        cout<<"enter row and column of the  board(only, number between 3 to 9):";          
        while(!(cin>>row>>col) || row < 3 || row > 9 || col < 3 || col > 9) //taking user input between 3 to 9
        {
            cout<<"invalid input!!!"<<endl;  //for invalid input exit the program 
            return false;
        }
        array=(int**)malloc(row*sizeof(int*));
        for (i=0; i<row; i++)
        {
            array[i]=(int*)malloc(col*sizeof(int));
        }
        solution_array=(int**)malloc(row*sizeof(int*));
        for (i=0; i<row; i++)
        {
            solution_array[i]=(int*)malloc(col*sizeof(int));
        }
        init_board(array,row,col); //calling functions 
        init_board(solution_array,row,col);
        }
        while ( gamePlay ) //condition to play the game till solve the puzzle
        {
            print_board(array,row,col); //calling function
            action_list();
            cin>>move_choice;  //we take users move 
            switch (move_choice)//then we switch according to users choice
            {
            case 'R':   //if user wants to go right 
            case 'r':
                if(move_right(array,row,col)==false) //we check if the move will be valid if he goes left 
                {
                    cout<<endl<<"invalid move"<<endl; //we warn the user if the move is invalid 
                }
                else{
                    moveAmount++;
                }
                break;
            case 'L':   //if user wants to go left 
            case 'l':
                if(move_left(array,row,col)==false)  //valid move check for right side 
                {
                    cout<<endl<<"invalid move"<<endl;
                }
                break;
            case 'U':   //if  user wants to go up 
            case 'u':
                if(move_up(array,row,col)==false) //valid move check 
                {
                    cout<<endl<<"invalid move"<<endl;
                }
                else{
                    moveAmount++;
                }
                break;
            case 'D':   //if user wants to go down 
            case 'd':
                if(move_down(array,row,col)==false)
                {
                    cout<<endl<<"invalid move"<<endl;
                } 
                else{
                    moveAmount++;
                }      
                break;
            case 'S':   //if user wants to shuffle the board 
            case 's':
                shuffle(array,row,col);
                if(check_win(array,solution_array,row,col)==true){
		    gamePlay=true;
                    shuffle(array,row,col);
                }
                break;
            case 'e': //if user wants to save the current game state to a file 
            case 'E':
                cout<<"Enter your file name:";
                cin>> fileName;  //taking file name 
                file.open (fileName,ios::out ); //opening the file in writing mode 
                for (i=0; i<row; i++ ){  //this loop writes in the file 
                    for (int j=0; j< col; j++){
                        file << array[i][j]<<" ";
                    }
                    file << endl;
                }
                file.close();  //closing file 
                break;
            case 'v':   //if the user wants to solve the game using extra-intelligence 
            case 'V':
                    while (gamePlay!=false)   //we keep playing until we find a solution 
                    {
                        int row2,col2;
                        auto stuck=0; 
                        decltype(stuck) j,count=0;
                        intelligent_move(array,solution_array,row,col); //calling intelligent move funtion 
                        count++;
                        print_board(array,row,col);
                        locate_value(array,row,col,row2,col2,-1); //we find the position of the the blank 
                        fill_positionCal(postionCal,solution_array[row2][col2]); //we put the value of that postion in the array
                        for  (int i=0; i< 3; i++){
                            for (j=i+1; j<3; j++){
                                if(array[i]==array[j])
                                    stuck++;
                            }
                        }
                        if(stuck!=1){   //if stucked then at first we set the array to its initial postion 
                            for(i=0; i<3; i++){
                                postionCal[i]=-1;
                            }
                        i=0; 
                        while (i!=5) //then we do 5 random moves 
                        {
                            move_choice=rand()%5;
                            if(move_choice==0){
                                move_left(array,row,col);
                                cout<<"intelligent move left";
                                print_board(array,row,col);
                                count++;
                                i++;
                            }
                            else if(move_choice==1){
                                move_left(array,row,col);
                                cout<<"intelligent move right";
                                print_board(array,row,col);
                                count++;
                                i++;
                            }
                                
                            else if (move_choice==2){
                                move_up(array,row,col);
                                cout<<"intelligent move up";
                                print_board(array,row,col);
                                count++;
                                i++;
                            }
                                
                            else{
                                move_down(array,row,col);
                                cout<<"intelligent move down";
                                print_board(array,row,col);
                                count++;
                                i++;
                            }  
                        }
                        }
                         if(check_win(array,solution_array,row,col)==true){ // we check if user has won 
                            cout<<"Number of steps to solve is:"<<count<<endl;
                            gamePlay=false;  //we set the gameplay value to be false to finish the game 
                        }
                    }
                    
                break;
            case 'y': //here we load the saved game 
            case 'Y':
                    free(array);  //we free the array and take a filename from user 
                    cout<<"enter a filename:";
                    cin>>fileName;
                    file.open(fileName); //opening the file 
                    if(!file){
                        cout<<"error to open file"<<endl;  //if failed to open the file 
                    }
                    array=(int**)malloc(row*sizeof(int*));  //arranging new array 
                    for (i=0; i<row; i++)
                    {
                        array[i]=(int*)malloc(col*sizeof(int));
                    }
                    file.close();
                    load_file(file,array,fileName,row,col);  //loading the array from saved game file 
                    break;
            case 'q':
            case 'Q':
                    cout<<"exiting . . ."<<endl;  //if user press q then he/she will exit from the game 
                    gamePlay=false;
                    break;
            case 'I':   //if user wants an intelligent move 
            case 'i':
                intelligent_move(array,solution_array,row,col);
                moveAmount++;
                break;
            case 't':
            case 'T':
                cout<<endl<<"Total move:"<<moveAmount<<endl;  //if user wants to know the amount of move he/she has done so far 
                break;
            default:  //for invalid move we display a message 
                cout<<"invalid input!!!\n";
                break;
            }
            if(check_win(array,solution_array,row,col)==true){ // we check if user has won the game after every valid move
                print_board(array,row,col);
                cout<<endl<<"congratulation.you won!!!"<<endl;
                gamePlay=false;  //we set the gameplay value to be false to finish the game 
            }
        }
}

void fill_positionCal(int *array,int value){  //this function will take an array and a value and put the value in the array 
    int i;
    for (i=0; i < 3; i++){
        if (array[i]==-1)
        {
            array[i]=value;
        }
    }
}

void intelligent_move(int **array,int **solution_array, int x,int y)
{
    int i,j,row,col,row2,col2,move_value,count=0;
    /*if the blank space value is not in the side values then we find the co-ordinate of the actual value 
    and we will move our move in that direction*/
    locate_value(array,x,y,row,col,-1); //locating blank space 
    move_value=solution_array[row][col];//locating which value is supposed to be in that postion 
    locate_value(array,x,y,row2,col2,move_value);//finding where the value is now by finding it's cordinate 
    if (row==row2){ //if in the same row 
        if (col < col2){   //we check column values and goes right left accordingly
            move_right(array,x,y);
            cout<<"intelligent move right"<<endl;
        }
        else{
            move_left(array,x,y);
            cout<<"intelligent move left"<<endl;
        }
    }
    else if(col==col2){ //if column are the same then we move according to row value 
        if (row > row2){
            move_up(array,x,y);
            cout<<"intelligent move up"<<endl;
        }
        else{
            move_down(array,x,y);
            cout<<"intelligent move down"<<endl;
        }
    }
    /*if the value is in corner then we found out in which way we should go , like Upright corner Upleftcorner
    Downrightcorner Downleftcorner. then we select a path to go there*/ 
    else if (row > row2 && col < col2){  //value is in uprightcorner direction 
        if(alreadyPositioned(array,solution_array,x,y,array[row][col+1])==false){ /*if our designed destination has no perfectly placed value then we
                                                                                    go in that direction. same logic holds for the rest of the code but 
                                                                                    for different direction*/ 
            move_right(array,x,y);
            cout<<"intelligent move right"<<endl;
        }
        else if(alreadyPositioned(array,solution_array,x,y,array[row-1][col])==false){ 
            move_up(array,x,y);
            cout<<"intelligent move up"<<endl;
        }
        else{
            move_right(array,x,y);
            cout<<"intelligent move right"<<endl;
        }
    }
    else if (row > row2 && col > col2){ //value is in upleftcorner direction 

        if(alreadyPositioned(array,solution_array,x,y,array[row-1][col])==false){
            move_up(array,x,y);
            cout<<"intelligent move up"<<endl;
        }
        else if(alreadyPositioned(array,solution_array,x,y,array[row][col-1])==false){
            move_left(array,x,y);
            cout<<"intelligent move left"<<endl;
        }
        else{
            move_left(array,x,y);
            cout<<"intelligent move left"<<endl;
        }
    }
    else if (row < row2 && col > col2){ //downleftcorner direction
        if(alreadyPositioned(array,solution_array,x,y,array[row-1][col])==false){
            move_down(array,x,y);
            cout<<"intelligent move down"<<endl;
        }
        else if(alreadyPositioned(array,solution_array,x,y,array[row][col-1])==false){
            move_down(array,x,y);
            cout<<"intelligent move down"<<endl;
        }
        else{
            move_up(array,x,y);
            cout<<"intelligent move up"<<endl;
        }
    }
    else if (row < row2 && col < col2){//downright corner direction 
        if(alreadyPositioned(array,solution_array,x,y,array[row][col+1])==false){
            move_right(array,x,y);
            cout<<"intelligent move right"<<endl;
        }
        else if(alreadyPositioned(array,solution_array,x,y,array[row+1][col])==false){
            move_down(array,x,y);
            cout<<"intelligent move down"<<endl;
        }
        else{
            move_right(array,x,y);
            cout<<"intelligent move right"<<endl;
        }
    }
}


int alreadyPositioned(int **array,int **solution_array,int x,int y,int value)
{
    int row ,col,row2,col2,flag=false;
    locate_value(array,x,y,row,col,value);//locating the value in gameplay board
    locate_value(solution_array,x,y,row2,col2,solution_array[row][col]);//locating the value in solution board
    if(row==row2 && col==col2){//checking if same or not 
        flag=true;
    }
    return flag;
}

/*this function will take two array and their size and decide the win condition*/
int check_win(int **array1,int **array2,int x,int y)
{
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


//this function will load the game from the choosen file 
void load_file(fstream& infile,int **board,string fileName,int row,int col){
    int i=0,arr[100];
    infile.open(fileName);  
    string word;
    i=0;
    if(!infile){  //if failes to open the file 
        cout<<"error!!! couldn't open the file";
    }
    while (infile >> word)  //this one will read the file word by word 
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
    init_board_file(board,arr,row,col);  //calling function
    infile.close();  
    }

int stringtoNUM(string word){  //this function converts a string to integer 
    int num=0,i;
    for (i=0; word[i]!='\0'; i++){
        num=num*10+word[i]-'0';
    }
    return num;
}
void init_board(int **array,int x,int y)//this function will fill the gameplay board to it's initial state
{
    int i,j,k=1;
    for (i=0; i< x; i++) //we loop throught the array 
    {
        for (j=0; j< y ; j++)
        {
            array[i][j]=k; //fill interger values 
            if(i==x-1 && j==y-1) //for the last position we place a 0
            {
                array[i][j]=-1;
            }
            k++;
        }
    }
}

void init_board_file(int **array,int *arr,int row,int col)//this function will fill the gameplay board to it's initial state
{
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

void init_solutionboard_file(int **array1,int **array2,int x,int y){ //this function will make a solution board according the board from the file 
    int i,j,k=1;
    for (i=0; i < x; i++){
        for(j=0; j < y; j++){
            if(array1[i][j]==0){
                array2[i][j]=0;
            }
            else if(array1[i][j]!=0){
                array2[i][j]=k;
                k++;
            }
            if(i==x-1 && j==y-1) //for the last position we place a 0
            {
                array2[i][j]=-1;
            }

        }
    }
}



inline void print_board(int **array,const int row,const int col){
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



/*this function will take and array , it's size and a value and will return it's cordinate in the board 
in call-by-reference method*/
void locate_value(int **array,int x,int y,int &row,int &col,int value)//here row and col will return two value indirectly
{
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




/*these function will move the blank space around the game board and will return a either true or false 
depending on the valid move. the logic works same for right left down and up move */

int move_right(int **array,int x,int y){   //takes an array and it's size 
    int row,col;
    locate_value(array,x,y,row,col,-1); //locate the position of space in the board 
    if (col+1>=y || array[row][col+1]==0){   //checks if the move is valid 
        return false;
    }
    else{           //if move is valid then swaps it's place with the right side place 
        swap(array[row][col+1],array[row][col]);  //calling swap function to swap position
        return true;     //if swap is a success then returns true else returns false 
    }
    
}

int move_left(int **array,int x,int y){ 
    int row,col;
    locate_value(array,x,y,row,col,-1);
    if (col-1<0 ||array[row][col-1]==0)
    {
        return false;
    }
    else
    {
        swap(array[row][col-1],array[row][col]);
        return true;
    }
}

int move_up(int **array,int x,int y){
    int row,col;
    locate_value(array,x,y,row,col,-1);
    if (row-1<0 ||array[row-1][col]==0)
    {
        return false;
    }
    else{
        swap(array[row-1][col],array[row][col]);
        return true;
    }
    
}

int move_down(int **array,int x,int y){
    int row,col;
    locate_value(array,x,y,row,col,-1);
    if (row+1>=x || array[row+1][col]==0)
    {
        return false;
    }
    else{
        swap(array[row+1][col],array[row][col]);
        return true;
    }
}

/*this function takes two value in call by reference method and swap their value */
void swap(int &a,int &b)
{
    int temp=a;//initially the temp holds the value of a
    a=b;//we change the value of a with b
    b=temp;//we set the value of b to temp 
}


void shuffle(int **array,int x,int y)
{
    srand(time(NULL)); //for generating random number 
    int random_move,move_done;
    for (int i=0; i < x*y; i++)//loop goes for n*n times 
    {
        move_done=false;   //initially we set move done to be false 
        random_move=rand()%4; //generating number between 0 - 3
        while (move_done!=true) // till the time we are not getting any valid move we will continue
        {
            switch (random_move) //we switch to the random move and move according to randomly generate number
            {
            /*if generated random number is 0 we go right , go left for 1, go up for 2,go down for 3.
            if move right, move left function will return a true or false value according to the execution.
            if they move then move_done will be true and we will exit the while loop  and continue the for loop*/
            case 0:
                move_done= move_right(array,x,y);
                break;
            case 1:
                move_done= move_left(array,x,y);
                break;
            case 2:
                move_done= move_up(array,x,y);
                break;
            case 3:
                move_done= move_down(array,x,y);
                break;
            }
            random_move=rand()%4; //generating random number for false move 
        }
        
        
    }

}
inline void rowCol(fstream& input,int &row,int &col,string fileName){ //this function will give the size of the row and column of the board that we will get from file 
    input.open(fileName);
    row=0; col=0;
    string line,word;
    while (getline(input,line)){ 
        row++;
    }
    input.close();
    input.open(fileName);
    while (input >> word) {
        col++;
    }
    input.close();
}

inline void action_list(){   //this function will print the options that we have 
    cout<<"case insensetive action list"<<endl;
    cout<<"-----------------------------\n";
    cout<<"->"<<"right=r left=l  down=d  up=u  shuffle=s  intelligentMove=i "<<endl;
    cout<<"->"<<"extra intelligence=v moveDone=t saveGame=e loadsavedGame=y"<<endl;
    cout<<"->"<<"quit game=q"<<endl;
}
