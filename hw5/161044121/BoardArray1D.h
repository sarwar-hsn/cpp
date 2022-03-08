#ifndef BOARDARRAY1D_H
#define BOARDARRAY1D_H
#include "AbstractBoard.h"
namespace swr{
    class BoardArray1D:public AbstractBoard{

        private:
            int* array;
            int* solutionArray;
        public:
            BoardArray1D();
            BoardArray1D(int row,int col);
            //*****BIG THREE*******
            BoardArray1D(const BoardArray1D& other);
            BoardArray1D& operator=(const BoardArray1D& other);
            ~BoardArray1D();

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
            vector<vector<int>> convert(int* array)const;
            void convertBack(vector<vector<int>>,int *arr);
            bool operator==(const BoardArray1D& other);
            vector<vector<int>> getSolutionArray();
    };
}
#endif