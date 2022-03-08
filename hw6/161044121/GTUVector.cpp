#include "GTUVector.h"
namespace swr{

    template<class T>
    void GtuVector<T>::expand(){ //expande the capacity of the vector if we reach the capacity 
        try{
            int newSize=this->capacity*2;
            if(newSize>this->max){throw newSize;}
            shared_ptr<T> temp(new T[newSize]{0},[](T* ptr){delete[] ptr;});
            for(int i=0; i<this->used;i++){
                temp.get()[i]=this->array.get()[i];
            }
        }
        catch(int newSize){
            cout<<"max limit reached\n";
        }
    }
    template<class T>
    bool GtuVector<T>::empty()const{ //checks if the vector is empty
        if(this->used==0){
            return true;
        }
        return false;
    }
    template<class T>
    int GtuVector<T>::size()const{ //returns size of the vector 
        return this->used;
    }
    template<class T>
    int GtuVector<T>::max_size()const{ //returns max size of the vector 
        return this->max;
    }
    template<class T>
    void GtuVector<T>::insert(const T& x,int pos){ //insert element in a valid location
        try
        {
            if(pos<0 ||(pos>=this->used) && this->used!=0){
                throw pos;
            }
            for(int i=this->used; i>pos; i--){
                this->array.get()[i] = this->array.get()[i-1];
            }
            this->array.get()[pos] = x;
            this->used++;
        }
        catch(const int& pos)
        {
            cout<<"Invalid index!!!\n"<<this->used;
        }
    }
    template<class T>
    void GtuVector<T>::insert(const T& x){  //insert element at the end of teh vector 
        if(this->used == this->capacity){expand();}
        else{
            this->array.get()[this->used]=x;
            this->used++;
        }
    }
    template<class T>
    void GtuVector<T>::erase(T* pos){ //erase a element 
        for(auto i = pos; i<this->end(); i++){
            *i=*(i+1);
        }
        this->used--;
    }
    template<class T>
    void GtuVector<T>::erase(int pos){ //erase a element through direct indexing 
        try{
            if(pos<0 || pos>=this->used ||empty()==true){throw pos;}
            for(int i = pos; i<this->used-1; i++)
                this->array.get()[i] = this->array.get()[i+1];
            this->used-=1;
        }
        catch(int pos){
            cout<<"not a valid position!\n";
        }
    }
    template<class T>
    T* GtuVector<T>::begin(){  //returns the beggining of the vector 
        return &(*(this->array));
    }
    template<class T>
    T* GtuVector<T>::end(){
        return &(this->array.get()[this->used]);
    }
    template<class T>
    void GtuVector<T>::erase(int x,int y){ //erase element between two range 
        try{
            if(x>=this->used || y>=this->used || x<0 || y<0 ||empty()==true){throw x;}
            if(x>y){int temp=x;y=x;x=y;}
            int j=y+1;
            for(int i = x; i<this->used-1; i++){
                this->array.get()[i]=this->array.get()[j];
                j++;
            }
            this->used-=(y-x);
        }
        catch(int x){
            cout<<"not a valid position!\n";
        }
    }
    template<class T>
    void GtuVector<T>::clear(){ //clear the vector elements 
        this->capacity=10;
        this->used=0;
        shared_ptr<T> temp(new T[this->capacity],[](T* ptr){delete[] ptr;});
        this->array=temp;
    }

    template<class T>
    T& GtuVector<T>::operator[](int index){ //overloading [] operator 
        if(index>=this->used){
            cout<<"invalid index"<<endl;
        }
        return this->array.get()[index];
    }
}