/*including headers*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std; //using the standard c++ input output

/*function prototypes*/
void init_board(int **array,int size);
void print_board(int **array,int size);
void locate_value(int **array,int n,int &row,int &col,int value);
int move_right(int **array,int size);
int move_left(int **array,int size);
int move_up(int **array,int size);
int move_down(int **array,int size);
void shuffle(int **array,int size);
void swap(int &a,int &b);
int check_win(int **array1,int **array2,int size);
void intelligent_move(int **array,int **solution_array, int size);
int alreadyPositioned(int **array,int **solution_array,int size ,int value);

int main() 
{
    int n,i,j,row,col,flag=false; //related variables
    char move_choice; 
    bool gamePlay=true;  
   
    cout<<endl;
    cout<<"enter the size of the board(only, number between 3 to 9):";          
    while(!(cin>>n) || n < 3 || n > 9) //taking user input between 3 to 9
    {
        cout<<"invalid input!!!"<<endl;  //for invalid input exit the program 
        return false;
    }
    cout<<endl;
   
    /*creating dynamic two dimensional array one for the solution and one for the game play*/
    int *array[n];
    for (i=0; i<n; i++)
    {
        array[i]=(int*)malloc(n*sizeof(int));
    }
    int *solution_array[n];
    for (i=0; i<n; i++)
    {
        solution_array[i]=(int*)malloc(n*sizeof(int));
    }

    /*calling functions*/
    init_board(array,n);
    init_board(solution_array,n);
    shuffle(array,n);

    while ( gamePlay ) //condition to play the game till solve the puzzle
    {
        print_board(array,n);   //calling function
        cout<<"enter your move(right=r,left=l,down=d,up=u,shuffle=s,intelligentMove=i) :";
        cin>>move_choice;  //we take users move 
        switch (move_choice)//then we switch according to users choice
        {
        case 'R':   //if user wants to go right 
        case 'r':
            if(move_right(array,n)==false) //we check if the move will be valid if he goes left 
            {
                cout<<endl<<"invalid move"<<endl; //we warn the user if the move is invalid 
            }
            break;
        case 'L':   //if user wants to go left 
        case 'l':
            if(move_left(array,n)==false)  //valid move check for right side 
            {
                cout<<endl<<"invalid move"<<endl;
            }
            break;
        case 'U':   //if  user wants to go up 
        case 'u':
            if(move_up(array,n)==false) //valid move check 
            {
                cout<<endl<<"invalid move"<<endl;
            }
            break;
        case 'D':   //if user wants to go down 
        case 'd':
            if(move_down(array,n)==false)
            {
                cout<<endl<<"invalid move"<<endl;
            }       
            break;
        case 'S':   //if user wants to shuffle the board 
        case 's':
            shuffle(array,n);
            break;
        case 'I':   //if user wants an intelligent move 
        case 'i':
            intelligent_move(array,solution_array,n);
            break;
        default:  //for invalid move we display a message 
            cout<<"invalid input!!!\n";
            break;
        }
        if(check_win(array,solution_array,n)==true){ // we check if user has won the game after every valid move
            print_board(array,n);
            cout<<endl<<"congratulation.you won!!!"<<endl;
            gamePlay=false;  //we set the gameplay value to be false to finish the game 
        }
    }
    return 0;
}

/*this function will take two array and their size and decide the win condition*/
int check_win(int **array1,int **array2,int size)
{
    int flag=true; //initially we set the flag value to be true
    int i,j;
    for (i=0; i<size ; i++)  //we run a loop between the elements of two array 
    {      
        for (j=0; j<size; j++)
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
void init_board(int **array,int size)//this function will fill the gameplay board to it's initial state
{
    int i,j,k=1;
    for (i=0; i< size; i++) //we loop throught the array 
    {
        for (j=0; j< size ; j++)
        {
            array[i][j]=k; //fill interger values 
            if(i==size-1 && j==size-1) //for the last position we place a 0
            {
                array[i][j]=0;
            }
            k++;
        }
    }
}


/*this function doesn't return anything and takes an array and it's size then suffle the element
we will shuffle  n*n time and if we find any invalid move then we will generate random number 
again till we have n*n times valid move*/
void shuffle(int **array,int size)
{
    srand(time(NULL)); //for generating random number 
    int random_move,move_done;
    for (int i=0; i < size*size; i++)//loop goes for n*n times 
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
                move_done= move_right(array,size);
                break;
            case 1:
                move_done= move_left(array,size);
                break;
            case 2:
                move_done= move_up(array,size);
                break;
            case 3:
                move_done= move_down(array,size);
                break;
            }
            random_move=rand()%4; //generating random number for false move 
        }
        
        
    }

}

/*this function will take and array , it's size and a value and will return it's cordinate in the board 
in call-by-reference method*/
void locate_value(int **array,int size,int &row,int &col,int value)//here row and col will return two value indirectly
{
    int i,j;
    for (i=0; i< size; i++)
    {
        for (j=0; j<size; j++)
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

int move_right(int **array,int size){   //takes an array and it's size 
    int row,col;
    locate_value(array,size,row,col,0); //locate the position of space in the board 
    if (col+1>=size){   //checks if the move is valid 
        return false;
    }
    else{           //if move is valid then swaps it's place with the right side place 
        swap(array[row][col+1],array[row][col]);  //calling swap function to swap position
        return true;     //if swap is a success then returns true else returns false 
    }
    
}

int move_left(int **array,int size){ 
    int row,col;
    locate_value(array,size,row,col,0);
    if (col-1<0)
    {
        return false;
    }
    else
    {
        swap(array[row][col-1],array[row][col]);
        return true;
    }
}

int move_up(int **array,int size){
    int row,col;
    locate_value(array,size,row,col,0);
    if (row-1<0)
    {
        return false;
    }
    else{
        swap(array[row-1][col],array[row][col]);
        return true;
    }
    
}

int move_down(int **array,int size){
    int row,col;
    locate_value(array,size,row,col,0);
    if (row+1>=size)
    {
        return false;
    }
    else{
        swap(array[row+1][col],array[row][col]);
        return true;
    }
}
   
    
/*this function takes and array and display it's element */
void print_board(int **array,int size){
    int i,j;
    cout<<endl<<endl;
    for (i=0; i<size; i++)//loop till the size 
    {
        for (j=0; j<size; j++)
        {
            cout.setf(ios::left); //aligning the element left side of screen
            cout.width(10); //setting the gap between elements 
            if(array[i][j]==0){ //if we encounter 0 then we print  _  in the screen
                cout<<"_";
            }
            else{
                cout<<array[i][j];//otherwise we print the regular value 
            }   
        }
        cout<<endl<<endl;
    }
}
/*this function takes two value in call by reference method and swap their value */
void swap(int &a,int &b)
{
    int temp=a;//initially the temp holds the value of a
    a=b;//we change the value of a with b
    b=temp;//we set the value of b to temp 
}

/*this function will check if the element is already in correct position and send response accordingly
if yes the will return true else will return false*/
int alreadyPositioned(int **array,int **solution_array,int size ,int value)
{
    int row ,col,row2,col2,flag=false;
    locate_value(array,size,row,col,value);//locating the value in gameplay board
    locate_value(solution_array,size,row2,col2,solution_array[row][col]);//locating the value in solution board
    if(row==row2 && col==col2){//checking if same or not 
        flag=true;
    }
    return flag;
}
void intelligent_move(int **array,int **solution_array, int size)
{
    int i,j,row,col,row2,col2,move_value,count=0;
    /*if the blank space value is not in the side values then we find the co-ordinate of the actual value 
    and we will move our move in that direction*/
    locate_value(array,size,row,col,0); //locating blank space 
    move_value=solution_array[row][col];//locating which value is supposed to be in that postion 
    locate_value(array,size,row2,col2,move_value);//finding where the value is now by finding it's cordinate 
    
    /*If we get locked out at the initial position of zero and find the surrounding values are 
    as it is in the solution board then */
    if(row==size-1 && col==size-1 && check_win(array,solution_array,size)==false)//condition of locked out
    {
        for (i=0; i < size ; i++)//we go through the loop and find where the position is not matched 
        {
            for (j=0; j < size ; j++)
            {
                if (array[i][j]!=solution_array[i][j])
                {
                    move_value=array[i][j];//we set the move value at that position 
                }
            }
        }
        locate_value(array,size,row,col,0);
        locate_value(array,size,row2,col2,move_value);//we locate that value 
        if (row==row2 && col!=col2)//if the value is in same row 
        {
            move_left(array,size); //we go left 
        }
        else if(col==col2 && row !=row2)//if the value is in same column
        {
            move_up(array,size); //we go up 
        }
        else{
            move_left(array,size);//else we go left. this is a mistake and there is a high possibility to get locked out again 
        }
        return;//we return not to execute the rest part of the code 
    }
    /*here we find  out in which direction we should go */
    if (row==row2){ //if in the same row 
        if (col < col2){   //we check column values and goes right left accordingly
            move_right(array,size);
        }
        else{
            move_left(array,size);
        }
    }
    if(col==col2){ //if column are the same then we move according to row value 
        if (row > row2){
            move_up(array,size);
        }
        else{
            move_down(array,size);
        }
    }
    /*if the value is in corner then we found out in which way we should go , like Upright corner Upleftcorner
    Downrightcorner Downleftcorner. then we select a path to go there*/ 
    if (row > row2 && col < col2){  //value is in uprightcorner direction 
        if(alreadyPositioned(array,solution_array,size,array[row][col+1])==false){ /*if our designed destination has no perfectly placed value then we
                                                                                    go in that direction. same logic holds for the rest of the code but 
                                                                                    for different direction*/ 
            move_right(array,size);
        }
        else if(alreadyPositioned(array,solution_array,size,array[row-1][col])==false){ 
            move_up(array,size);
        }
        else{
            move_right(array,size);
        }
    }
    if (row > row2 && col > col2){ //value is in upleftcorner direction 

        if(alreadyPositioned(array,solution_array,size,array[row-1][col])==false){
            move_up(array,size);
        }
        else if(alreadyPositioned(array,solution_array,size,array[row][col-1])==false){
            move_left(array,size);
        }
        else{
            move_left(array,size);
        }
    }
    if (row < row2 && col > col2){ //downleftcorner direction
        if(alreadyPositioned(array,solution_array,size,array[row-1][col])==false){
            move_down(array,size);
        }
        else if(alreadyPositioned(array,solution_array,size,array[row][col-1])==false){
            move_down(array,size);
        }
        else{
            move_up(array,size);
        }
    }
    if (row < row2 && col < col2){//downright corner direction 
        if(alreadyPositioned(array,solution_array,size,array[row][col+1])==false){
            move_right(array,size);
        }
        else if(alreadyPositioned(array,solution_array,size,array[row+1][col])==false){
            move_down(array,size);
        }
        else{
            move_right(array,size);
        }
    }
}