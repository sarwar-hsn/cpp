#ifndef GTUSET_H
#define GTUSET_H
#include "GTUContainer.h"
namespace swr{
    template<class T> //template class inherited from base class GtuContainer 
    class GtuSet:public GtuContainer<T>{
        public:
            //related functions along with overriden functions 
            void expand();
            bool empty()const;
            int size()const;
            int max_size()const;
            void insert(const T& x);
            void erase(const T& value);
            void erase(T* pos);
            void clear();
            T* begin();
            T* end();
            T& operator[](int index);
    };
}



#endif