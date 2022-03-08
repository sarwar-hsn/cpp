#ifndef BOARDVECTOR_H
#define BOARDVECTOR_H
#include "AbstractBoard.h"
namespace swr{
    class BoardVector:public AbstractBoard{
        private:
            vector<vector<int>> array;
            vector<vector<int>> solutionArray;
        public:
            BoardVector();
            BoardVector(int row,int col);
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
            bool operator== (const BoardVector& other);

    };
}

#endif