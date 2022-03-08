public class swap{
    protected int a;
    protected int b;
     public swap(int a,int b){this.a=a;this.b=b;}
     public void swap(swap x){
         int temp=x.a;a=x.b;x.b=temp;
     }
 }