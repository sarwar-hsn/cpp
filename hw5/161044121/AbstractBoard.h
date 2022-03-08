#ifndef ABSTRACTBOARD_H
#define ABSTRACTBOARD_H
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
namespace swr{
    class AbstractBoard
    {
    protected:
        fstream file; //related private variables 
        string fileName;
        int row,col,x=0,y=0,totalMove=0;
        char moveChoice,lastMove;
    public:
            static int boardCreated;
            
            AbstractBoard();
            AbstractBoard(int x,int y);
            virtual void print()const=0;
            void setSize(int x,int y);
            virtual void reset()=0;
            void swap(int&,int&);
            void move(char);
            virtual bool moveRight()=0;
            virtual bool moveLeft()=0;
            virtual bool moveUp()=0;
            virtual bool moveDown()=0;
            virtual void locateValue(int)=0;
            virtual bool isSolved()=0;
            void readFromFile(string);
            virtual void initBoardFile(vector<int> arr)=0;
            virtual void initSolutionBoardFile()=0;
            int stringtoNUm(string);
            int rowCol(string);
            virtual void writeToFile(string)=0;
            virtual int operator()(int x,int y)=0;
            int numberofBoards();
            char returnLastMove();
            int numberofMoves();
            //************setters and getters***********
            void setRow(int);
            void setCol(int);
            void setX(int);
            void setY(int);
            void setMoveChoice(char);
            void setLastMove(char);
            void setFileName(string);

            int getRow()const;
            int getCol()const;
            int getX()const;
            int getY()const;
            char getMoveChoice()const;
            char getLastMove()const;
            string getFileName()const;

    };
    
}
#endif