package Gtu.util;

public interface GTUIterator<T> {
    //returns boolean value based on if a container has more element 
    boolean hasNext();
    //returns the element of the container
    T next();
}