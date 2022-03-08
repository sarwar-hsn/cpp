import Gtu.util.GTUIterator;

public class GTUVector<T> extends AbstractContainer<T> {

    //returns true if the container is empty
    public boolean empty(){
        if(used==0)return true;
        else return false;
    }
    //returns the size of the container 
    public int size(){
        return used;
    }
    //returns the max size of the container
    public int max_size(){
        return max;
    }
    //insert a element at the end of the container . returns true if success .returns false for failure
    public boolean insert(T element){
        if(used==capacity){
            capacity+=10;
            if(capacity>max){
                if(max-capacity==0)
                    return false;
                else
                    capacity=max-capacity;
            }
            T[] temp=(T[]) new Object[capacity];
            for(int i=0; i<used; i++){
                temp[i]=array[i];
            }
            array=(T[]) new Object[capacity];
            for(int i=0; i<used; i++){
                array[i]=temp[i];
            }
        }
        try {
            array[used++]=element;
            return true;
        } catch (Exception e) {
            System.out.println("error while inserting element");
        }
        return false;
    }
    //erase an element from container if presents in the container.returns true if success .returns false for failure
    public boolean erase(T element){
        try {
            if(isPresent(element)){
                int i;
                for( i=0; i<used; i++){
                    if(array[i]==element)
                        break;
                }
                for(int j=i; j<used; j++){
                    array[j]=array[j+1];
                }
                used-=1;
                return true;
            }
            throw new Exception("invalid element to erase");
        } catch (Exception e) {
            System.out.println(e);
            return false;
        }
    }
    //empty the content of the container
    public void clear(){
        used=0;
        capacity=10;
        array=(T[])new Object[capacity];
    }
    //returns a boolean value based on if a object is present int the container 
    public boolean contains(Object o){
        for(int i=0; i<used; i++){
            if((Object)array[i]==o){
                return true;
            }
        }
        return false;
    }
    //inner iterator class
    public class vectorIter<T> implements GTUIterator<T>{

        private int index;
        public vectorIter(){
            index=0;
        }
        public boolean hasNext() {
            if(index < used){
                return true;
            }
            return false;
        }
        public T next() {
            return (T) array[index++];
        }

    }
    //returns an iterator to a postion 
    public GTUIterator<T> iterator(){
        return new vectorIter<T>();
    }
    //private within contex and checks if a value is present in the container and returns boolean value depending on that
    private boolean isPresent(T key){
        for(int i=0; i<used; i++){
            if(array[i]==key){
                return true;
            }
        }
        return false;
    }
}