#include <iostream>
#include "AbstractBoard.h"
#include "BoardVector.h"
#include "BoardArray2D.h"
#include "BoardArray1D.h"
using namespace std;
using namespace swr;
bool globalFunc(vector<swr::AbstractBoard*> array){
    bool sequenced=true,mark;
    int activeBoard=0;
    int m,n,o,p;
    int pivot=0;
    while( pivot!=array.size()){
         if(array[pivot]->moveRight()==true){
            array[pivot]->moveLeft();
            array[pivot]->locateValue(-1);
            m=array[pivot]->getX();
            n=array[pivot]->getY();
            array[pivot+1]->locateValue(-1);
            o=array[pivot+1]->getX();
            p=array[pivot+1]->getY();
            if(m==o && n==(p-1)){
                mark=true;
            }
            else{
                mark=false;
                 return mark;
                 break;
            }
        }
        else{
            array[pivot]->moveLeft();
        }
        if(array[pivot]->moveLeft()==true){
            array[pivot]->moveRight();
            array[pivot]->locateValue(-1);
            m=array[pivot]->getX();
            n=array[pivot]->getY();
            array[pivot+2]->locateValue(-1);
            o=array[pivot+2]->getX();
            p=array[pivot+2]->getY();
            if(m==o && n==(p+1)){
                mark=true;
            }
            else{
                mark=false;
                return mark;
                break;
            }
        }
        else{
            array[pivot]->moveRight();
        }
        if(array[pivot]->moveUp()==true){
            array[pivot]->moveDown();
            array[pivot]->locateValue(-1);
            m=array[pivot]->getX();
            n=array[pivot]->getY();
            array[pivot+3]->locateValue(-1);
            o=array[pivot+3]->getX();
            p=array[pivot+3]->getY();
            if((m+1)==o && n==p){
                 
                mark=true;
            }
            else{
                mark=false;
                return mark;
                break;
            }
        }
        else{
            array[pivot]->moveDown();
        }
        if(array[pivot]->moveDown()==true){
            array[pivot]->moveDown();
            array[pivot]->locateValue(-1);
            m=array[pivot]->getX();
            n=array[pivot]->getY();
            array[pivot+3]->locateValue(-1);
            o=array[pivot+3]->getX();
            p=array[pivot+3]->getY();
            if((m+1)==o && n==p){
                mark=true;
            }
            else{
                mark=false;
                return mark;
                break;
            }
        }
        else{
            array[pivot]->moveUp();
        }
        pivot++;
    }
    return mark;
}



int main(){
    vector<AbstractBoard*> objects;
    swr::AbstractBoard *x;
    swr::AbstractBoard *y;
    swr::AbstractBoard *z;
    swr::AbstractBoard *k;
    //creating obj
    BoardArray2D m(3,3);
    m.reset();
    cout<<"checking moves"<<endl;
    m.move('R');
    cout<<"checking print"<<endl;
    m.print();//print 
    m.move('L');
    m.print();//print 
    m.move('U');
    m.print();//print 
    m.move('D');
    BoardArray2D n(3,3);
    n.reset();
    n.moveUp();
    BoardArray2D o(3,3);
    o.reset();
    o.moveLeft();
    o.moveLeft();
    o.moveUp();
    BoardArray2D p(3,3);
    p.reset();
    p.moveUp();
    p.moveUp();
    p.moveLeft();
    x=&m;
    y=&n;
    z=&o;
    k=&p;
    //pushing to AbstractBoard* vector
    objects.push_back(x);
    objects.push_back(y);
    objects.push_back(z);
    objects.push_back(k);
   cout<<"Total obj created"<<endl;
    cout<<"total board:"<<x->numberofBoards()<<endl;
    x->writeToFile("init.txt");
    x->readFromFile("init.txt");
    x->print();
   cout<<"checking two equal obj"<<endl;
    BoardArray2D test1(3,3);
    test1.reset();
    BoardArray2D test2(3,3);
    test2.reset();
    cout<<(test1==test2)<<endl;
    test2.move('L');
    cout<<(test1==test2)<<endl;
    cout<<"checking last move"<<endl;
    cout<<test2.getLastMove()<<endl;
    cout<<"checking number of moves"<<endl;
    cout<<test2.numberofMoves()<<endl;
    
    //check for BoardArray1D
    BoardArray1D u(3,3);
    u.reset();
    cout<<"checking moves"<<endl;
    u.move('R');
    cout<<"checking print"<<endl;
    u.print();//print 
    u.move('L');
    u.print();//print 
    u.move('U');
    u.print();//print 
    u.move('D');
    BoardArray1D v(3,3);
    v.reset();
    v.moveUp();
    BoardArray1D w(3,3);
    w.reset();
    w.moveLeft();
    w.moveLeft();
    w.moveUp();
    BoardArray1D q(3,3);
    q.reset();
    q.move('R');
    x=&u;
    y=&v;
    z=&w;
    k=&q;
    //pushing to AbstractBoard* vector
    objects.push_back(x);
    objects.push_back(y);
    objects.push_back(z);
    objects.push_back(k);
   cout<<"Total obj created"<<endl;
    cout<<"total board:"<<x->numberofBoards()<<endl;
    x->writeToFile("init.txt");
    x->readFromFile("init.txt");
    x->print();
   cout<<"checking two equal obj"<<endl;
    BoardArray2D test3(3,3);
    test1.reset();
    BoardArray2D test4(3,3);
    test2.reset();
    cout<<(test1==test3)<<endl;
    test2.move('L');
    cout<<(test1==test4)<<endl;
    cout<<"checking last move"<<endl;
    cout<<test2.getLastMove()<<endl;
    cout<<"checking number of moves"<<endl;
    cout<<test2.numberofMoves()<<endl;

    cout<<"overloads"<<endl;
    BoardVector test5(3,3);
    test5.reset();
    cout<<test5(1,1)<<endl;

    cout<<"global function"<<endl;
    cout<<globalFunc(objects)<<endl;

}