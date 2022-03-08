import Gtu.util.GTUIterator;
public abstract class AbstractContainer<T> {

    protected T[]array;
    protected int used;
    protected int capacity;
    protected int max;
    //constructor takes no parameter and initial capacity is 10 and maximum is 100
    public AbstractContainer(){
        used=0;
        capacity=10;
        max=100;
        array=(T[]) new Object[capacity];
    }
    //this function takes an index  and return the value at that index
    public T get(int index) {
        
        T value = (T) array[index];
        return value;
    }
    public abstract boolean empty();
    public abstract int size();
    public abstract int max_size();
    public abstract boolean insert(T element);
    public abstract boolean erase(T element);
    public abstract void  clear();
    public abstract GTUIterator<T> iterator();
    public abstract boolean contains(Object o);

}