#include "GTUContainer.h"
namespace swr{
        template<class T>
        GtuContainer<T>::GtuContainer():capacity(20),used(0),max(100){
            std::shared_ptr<T> x(new T[capacity], [](T* ptr)
            {
                delete[] ptr;
            });
            array=x;
        }
        template<class T>
        GtuContainer<T>::GtuContainer(int capacity):capacity(capacity),used(0),max(100){
            std::shared_ptr<T> x(new T[capacity], [](T* ptr)
            {
                delete[] ptr;
            });
            array=x;
        }
        template<class T>
        GtuContainer<T>::GtuIterator::GtuIterator(T* x){
            this->current=x;
        }
        template<class T>
        T& GtuContainer<T>::GtuIterator::operator*(){
            return *(this->current);
        }
        template<class T>
        bool GtuContainer<T>::GtuIterator::operator!=(const GtuIterator& rhs)const{
            return (this->current !=rhs.current);
        }
        template<class T>
        bool GtuContainer<T>::GtuIterator::operator==(const GtuIterator& rhs){
            return (this->current==rhs.current);
        }

        template<class T>
        GtuContainer<T>::GtuIteratorConst::GtuIteratorConst(T* x){
            this->current=x;
        }
        template<class T>
        const T& GtuContainer<T>::GtuIteratorConst::operator*()const{
            return *(this->current);
        }
        template<class T>
        bool GtuContainer<T>::GtuIteratorConst::operator ==(const GtuIteratorConst& rhs)const{
            return (this->current==rhs.current);
        }
        
}