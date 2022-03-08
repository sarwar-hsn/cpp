#include <iostream>
using namespace std;

template<class T>
class A{
    public:
        virtual int print()=0;
    protected:
        int x;
};
template<class T>
class B:public A<T>{
    public: 
        int print(){
            return this->x;
        }
};
int main(){

}