import Gtu.util.GTUIterator;

public class GTUSet<T> extends AbstractContainer<T> {
    public boolean empty(){
        if(used==0) return true;
        else return false;
    }
    
    public int size(){
        return used;
    }
    public int max_size(){
        return max;
    }
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
            if(isPresent(element)==false){
                array[used++]=element;
                return true;
            }
        } catch (Exception e) {
            System.out.println("error while inserting element");
        }
        return false;
    }
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
    public void clear(){
        used=0;
        capacity=10;
        array=(T[])new Object[capacity];
    }
    public boolean contains(Object o){
        for(int i=0; i<used; i++){
            if((Object)array[i]==o){
                return true;
            }
        }
        return false;
    }
    public class setIter<T> implements GTUIterator<T>{

        private int index;
        public setIter(){
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
    public GTUIterator<T> iterator(){
        return new setIter<T>();
    }
    private boolean isPresent(T key){
        for(int i=0; i<used; i++){
            if(array[i]==key){
                return true;
            }
        }
        return false;
    }
}