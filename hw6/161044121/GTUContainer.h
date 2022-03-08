#ifndef GTUCONTAINER_H
#define GTUCONTAINER_H
#include <iostream>
#include <memory>

//abastract base class 
using namespace std;
namespace swr{
    template<class T> //template 
    class GtuContainer{
        public:
            //constructors 
            GtuContainer();
            GtuContainer(int capacity);
            class GtuIterator{ //inner iterator class
                public: 
                    GtuIterator(){}
                    GtuIterator(T* x);
                    //overloads 
                    T& operator*();
                    GtuIterator& operator++(){
                        this->current++;
                        return *this;
                    } 
                    GtuIterator& operator++(int){
                        this->current++;
                        return *this;
                    }
                    bool operator !=(const GtuIterator& rhs)const;
                    GtuIterator& operator--(){
                        this->current--;
                        return *this;
                    } 
                    GtuIterator& operator--(int){
                        this->current--;
                        return *this;
                    }
                    bool operator==(const GtuIterator& rhs);
                    GtuIterator& operator=(const GtuIterator& rhs){
                        this->current=rhs.current;
                        return *this;
                    } 
                protected:
                    T* current;
            };
            //read only inner iterator class
            class GtuIteratorConst{
                public:
                    GtuIteratorConst(){}
                    GtuIteratorConst(T* x);
                    const T& operator*()const;
                    const GtuIteratorConst& operator++(){
                        this->current++;
                        return *this;
                    } 
                    const GtuIteratorConst& operator++(int){
                        this->current++;
                        return *this;
                    }
                    bool operator !=(const GtuIteratorConst& rhs)const;
                    const GtuIteratorConst& operator--(){
                        this->current--;
                        return *this;
                    } 
                    const GtuIteratorConst& operator--(int){
                        this->current--;
                        return *this;
                    }
                    bool operator==(const GtuIteratorConst& rhs)const;
                    const GtuIteratorConst& operator=(const GtuIteratorConst& rhs){
                        this->current=rhs.current;
                        return *this;
                    }
                private:
                    T* current;
            };
            //pure virtual fucntions 
            virtual T* begin()=0;
            virtual T* end()=0;
            virtual void expand()=0;
            virtual int size()const=0;
            virtual bool empty()const=0;
            virtual int max_size()const=0;
            virtual void insert(const T& x)=0;
            virtual void erase(T* pos)=0;
            virtual void clear()=0;
        protected:
            shared_ptr<T> array; //array through shared_ptr
            int capacity;
            int max;
            int used;
    };
}

#endif