import Gtu.util.GTUIterator;

public class Driver {

    public static void main(String[] args) {

       { //Testing Gtuset
        GTUSet<Integer> obj=new GTUSet<Integer>();//creating obj
        //inserting values 
        obj.insert(5);
        obj.insert(10);
        obj.insert(15);
        GTUIterator<Integer> it=obj.iterator();//creatin iterator
        //printing elements using iterator
        while(it.hasNext()){ 
            System.out.println(it.next());
        }
        //erasing an element
        System.out.println("after erasing value 10");
        obj.erase(10);
        //printing elements again
        it=obj.iterator();
        while(it.hasNext()){ 
            System.out.println(it.next());
        }
        //will not insert same value again
        obj.insert(15);
        System.out.println("trying to insert 15 again ");
        it=obj.iterator();
        while(it.hasNext()){ 
            System.out.println(it.next());
        }

        //checking if the container is empty
        System.out.printf("container empty->");
        System.out.println(obj.empty());
        //checking if the container contains 5
        System.out.printf("container have (5)->");
        System.out.println(obj.contains(5));
        System.out.printf("container have (555)->");
        System.out.println(obj.contains(555));
        //clearing the container 
        obj.clear();
        //Now the container empty will be true
        System.out.printf("after clearing container empty->");
        System.out.println(obj.empty());
    }

        
        
        System.out.println("\n\nGtuVector section");
        { //Testing GTUVector
            GTUVector<Integer> obj=new GTUVector<Integer>();//creating obj
            //inserting values 
            obj.insert(5);
            obj.insert(10);
            obj.insert(15);
            GTUIterator<Integer> it=obj.iterator();//creatin iterator
            //printing elements using iterator
            while(it.hasNext()){ 
                System.out.println(it.next());
            }
            //erasing an element
            System.out.println("after erasing value 10");
            obj.erase(10);
            //printing elements again
            it=obj.iterator();
            while(it.hasNext()){ 
                System.out.println(it.next());
            }
            //will  insert same value 
            obj.insert(15);
            System.out.println("vector allows same value.inserting 15 again ");
            it=obj.iterator();
            while(it.hasNext()){ 
                System.out.println(it.next());
            }
    
            //checking if the container is empty
            System.out.printf("container empty->");
            System.out.println(obj.empty());
            //checking if the container contains 5
            System.out.printf("container have (5)->");
            System.out.println(obj.contains(5));
            System.out.printf("container have (555)->");
            System.out.println(obj.contains(555));
            //clearing the container 
            obj.clear();
            //Now the container empty will be true
            System.out.printf("after clearing container empty->");
            System.out.println(obj.empty());
        }
    }
}