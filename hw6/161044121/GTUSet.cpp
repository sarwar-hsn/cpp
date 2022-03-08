//the functions are almost like vector functions but in the insert the set class doesn't allow duplicate element
//beside these the changes are mainly in the functions parameter and in very less amount

#include "GTUSet.h"
namespace swr{
    template<class T>
    void GtuSet<T>::expand(){
        try{
            int newSize=this->capacity*2;
            if(newSize>this->max){throw newSize;}
            shared_ptr<T> temp(new T[newSize]{0},[](T* ptr){delete[] ptr;});
            for(int i=0; i<this->used;i++){
                temp.get()[i]=this->array.get()[i];
            }
        }
        catch(int newSize){
                cout<<"max capacity reached!!!\n";
        }
    }
    template<class T>
    bool GtuSet<T>::empty()const{
        if(this->used==0){
            return true;
        }
        return false;
    }
    template<class T>
    int GtuSet<T>::size()const{
        return this->used;
    }
    template<class T>
    int GtuSet<T>::max_size()const{
        return this->max;
    }
    template<class T>
    void GtuSet<T>::insert(const T& x){
        int flag=true;
        if(this->used == this->capacity){expand();}
        else{
            for(int i=0;i<this->used;i++){
                if(this->array.get()[i]==x){
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                this->array.get()[this->used]=x;
                this->used++;
            }
        }
    }
    template<class T>
    void GtuSet<T>::erase(const T& value){ 
       int flag=false,i;
       for( i=0; i<this->used; i++){
           if(this->array.get()[i]==value){
               flag=true;
               break;
           }  
        }
        cout<<i<<endl;
        if(flag==true){
            for(int j=i; j<this->used;j++){
                this->array.get()[j]=this->array.get()[j+1];
            }
        }
        
        
    }
    template<class T>
    void GtuSet<T>::erase(T* pos){
        for(auto i = pos; i<this->end(); i++){
            *i=*(i+1);
        }
        this->used--;
    }
    template<class T>
    void GtuSet<T>::clear(){
        this->capacity=10;
        this->used=0;
        shared_ptr<T> temp(new T[this->capacity],[](T* ptr){delete[] ptr;});
        this->array=temp;
    }
    template<class T>
    T* GtuSet<T>::begin(){
        return &(*(this->array));
    }
    template<class T>
    T* GtuSet<T>::end(){
        return &(this->array.get()[this->used]);
    }
    template<class T>
    T& GtuSet<T>::operator[](int index){
        if(index>=this->used){
            cout<<"invalid index"<<endl;
        }
        return this->array.get()[index];
    }
}