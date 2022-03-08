#ifndef BOARDARRAY2D_H
#define BOARDARRAY2D_H
#include "AbstractBoard.h"
namespace swr{
    class BoardArray2D:public AbstractBoard{

        private:
            int** array;
            int** solutionArray;
        public:
            BoardArray2D();
            BoardArray2D(int row,int col);
            //*****BIG THREE*******
            BoardArray2D(const BoardArray2D& other);
            BoardArray2D& operator=(const BoardArray2D& other);
            ~BoardArray2D();


            void print()const;
            void reset();
            bool moveRight();
            bool moveLeft();
            bool moveUp();
            bool moveDown();
            void locateValue(int);
            bool isSolved();
            void initBoardFile(vector<int> arr);
            void initSolutionBoardFile();
            void writeToFile(string);
            int operator()(int x,int y);
            bool operator==(const BoardArray2D& other);

    };
}
#endif