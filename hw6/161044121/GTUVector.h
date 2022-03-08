#ifndef GTUVECTOR_H
#define GTUVECTOR_H
#include "GTUContainer.h"
namespace swr{
    template<class T> //template class derived from gtu container class 
    class GtuVector:public GtuContainer<T>{
        public:
            //related functions along with overriden functions 
            void expand();
            bool empty()const;
            int size()const;
            int max_size()const;
            void insert(const T& x,int pos);
            void insert(const T& x);
            void erase(int pos);
            void erase(T* pos);
            void erase(int x,int y);
            void clear();
            T& operator[](int index);
            T* begin();
            T*end();
    };

}





#endif