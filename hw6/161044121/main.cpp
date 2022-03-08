#include <iostream>
#include <memory>
#include "GTUContainer.h"
#include "GTUContainer.cpp"
#include "GTUVector.h"
#include "GTUVector.cpp"
#include "GTUSet.h"
#include "GTUSet.cpp"
using namespace std;
template<class T, class U>
T find_if (T first, T last, U func)
{
  while (first!=last){
    if (func(*first))
        return first;
    ++first;
  }
  return last;
}
template<class T, class U>
T find (T first, T last, const U& val)
{
  while (first!=last) {
    if (*first==val) return first;
    ++first;
  }
  return last;
}
template<class T, class U>
U for_each(T first, T last, U func)
{
  while (first!=last){
    func (*first);
    ++first;
  }
  return func;      
}
void myfunction (int i) { 
  std::cout << ' ' << i;
}
bool IsOdd(int i) 
{ 
    return i % 2; 
} 
int main(){
  {
    cout<<"\t\tTest for GTUVector int type"<<endl;
      swr::GtuVector<int> x;//create a vector object with default constructor
      cout<<"Vector size and maximum size are: "<<x.size()<<" "<<x.max_size()<<endl;
      //inserting 5 object
      x.insert(5);
      x.insert(10);
      x.insert(15);
      x.insert(20);
      x.insert(25);

      
      cout<<"After inserting 5 object new size of the vector is: "<<x.size()<<endl;
      cout<<"Printing the vector object with iterator overload\n";
      cout<<"With auto pointer\n";
      for(auto i=x.begin(); i!=x.end(); i++){
        cout<<*i<<" ";
      }
      cout<<endl;
      cout<<"With iterator\n";
      swr::GtuVector<int>::GtuIterator ptr(x.begin());
      for(ptr=x.begin(); ptr!=x.end(); ptr++){//ptr++ 
        cout<<*ptr<<" ";
      }
      cout<<"\nsame way we can do it with prefix. let's check from end to begin"<<endl;
      for(ptr=x.end()-1; ptr!=x.begin(); --ptr){
        cout<<*ptr<<" ";
      }
      cout<<endl;
      cout<<"\t\tGlobal functions\n";
      cout<<"find_if\n";
      swr::GtuVector<int>::GtuIterator it =find_if (x.begin(), x.end(), IsOdd);
      cout << "The first odd value is " << *it << '\n';
      cout<<"find\n";
      ptr = find (x.begin(), x.end(), 100);
      if (ptr != x.end())
        cout << "Element found in myvector: " << *it << '\n';
      else
        cout << "Element not found in myvector\n";
      cout<<"for_each\n";
      for_each (x.begin(), x.end(), myfunction);
      cout << '\n';
      
      cout<<"\nlet's see the == overload\n";
      cout<<"begin==end is "<<(ptr==x.end())<<endl;
      cout<<"begin==begin is "<<(ptr==x.begin())<<endl;
      cout<<"Let's say we want to delete the 2nd element(counts 0 as first object)\n";
      x.erase(1);//deleting the second object
      cout<<"Printing the vector again this time with [] overload after deleting\n";
      for(int i=0; i<x.size(); i++){
        cout<<x[i]<<" ";
      }
      cout<<endl;
      cout<<"The object is not empty now . Let's check it with empty() function\n";
      cout<<"Empty state should be false(0): "<<x.empty()<<endl;
      cout<<"Now let's clear the vector and see it's size and empty state\n";
      x.clear();
      cout<<"Empty state should be true(1): "<<x.empty()<<endl;
      cout<<"vector size after clearing: "<<x.size()<<endl;

  }
  cout<<"Same thing with vector of type string\n";
  {
    cout<<"\t\tTest for GTUVector string type"<<endl;
      swr::GtuVector<string> x;//create a vector object with default constructor
      cout<<"Vector size and maximum size are: "<<x.size()<<" "<<x.max_size()<<endl;
      //inserting 5 object
      x.insert("Welcome");
      x.insert("to");
      x.insert("Gtu");
      x.insert("CSE");
      x.insert("241");
      cout<<"After inserting 5 object new size of the vector is: "<<x.size()<<endl;
      cout<<"Printing the vector object with iterator overload\n";
      cout<<"With auto pointer\n";
      for(auto i=x.begin(); i!=x.end(); i++){
        cout<<*i<<" ";
      }
      cout<<endl;
      cout<<"With iterator\n";
      swr::GtuVector<string>::GtuIterator ptr(x.begin());
      for(ptr=x.begin(); ptr!=x.end(); ptr++){//ptr++ 
        cout<<*ptr<<" ";
      }
      cout<<"\nsame way we can do it with prefix. let's check from end to begin"<<endl;
      for(ptr=x.end()-1; ptr!=x.begin(); --ptr){
        cout<<*ptr<<" ";
      }
      cout<<endl;
      cout<<"let's see the == overload\n";
      cout<<"begin==end is "<<(ptr==x.end())<<endl;
      cout<<"begin==begin is "<<(ptr==x.begin())<<endl;
      cout<<"Let's say we want to delete the 2nd element(counts 0 as first object)\n";
      x.erase(1);//deleting the second object
      cout<<"Printing the vector again this time with [] overload after deleting\n";
      for(int i=0; i<x.size(); i++){
        cout<<x[i]<<" ";
      }
      cout<<endl;
       cout<<"The object is not empty now . Let's check it with empty() function\n";
       cout<<"Empty state should be false(0): "<<x.empty()<<endl;
       cout<<"Now let's clear the vector and see it's size and empty state\n";
       x.clear();
      cout<<"Empty state should be true(1): "<<x.empty()<<endl;
      cout<<"vector size after clearing: "<<x.size()<<endl;
  }

  cout<<"\n\t\tGTUSet class\n";
  {
    swr::GtuSet<int> x;
    x.insert(1);
    x.insert(2);
    x.insert(3);
    x.insert(4);
    x.insert(5);
    //creating iterator 
    swr::GtuSet<int>::GtuIterator ptr=x.begin();
    //printing elements with iterator 
    for(ptr; ptr!=x.end(); ptr++){
      cout<<*ptr<<" ";
    }
    cout<<endl;
    //with [] overload
    for (int i=0; i<x.size(); i++){
      cout<<x[i]<<" ";
    } 
    cout<<endl;
    //erasing the 2nd element.count starts with 0
    auto p=x.begin()+1;
    x.erase(p);
    cout<<"after deleting 2nd elment\n";
    for(int i=0; i<x.size(); i++){
      cout<<x[i]<<" ";
    }
    cout<<endl;
    //let's insert it back
    x.insert(2);
    cout<<"after inserting the elment\n";
    for(int i=0; i<x.size(); i++){
      cout<<x[i]<<" ";
    }
    cout<<endl;
    //if we try to insert same element then it will not accept
    x.insert(1);
    cout<<"trying to  insert same elment\n";
    for(int i=0; i<x.size(); i++){
      cout<<x[i]<<" ";
    }
    cout<<endl;
    cout<<"empty state should be false(0): "<<x.empty()<<endl;
    cout<<"\t\tGlobal functions\n";
    cout<<"find_if\n";
    swr::GtuVector<int>::GtuIterator it =find_if (x.begin(), x.end(), IsOdd);
    cout << "The first odd value is " << *it << '\n';
    cout<<"find\n";
    ptr = find (x.begin(), x.end(), 4);
    if (ptr != x.end())
      cout << "Element found in myvector: " << *it << '\n';
    else
      cout << "Element not found in myvector\n";
    cout<<"for_each\n";
    for_each (x.begin(), x.end(), myfunction);
    cout << '\n';
    //clearing the set
    x.clear();
    cout<<"After clearing size: "<<x.size()<<endl;
    cout<<"empty state should be false(1): "<<x.empty()<<endl;
  }

    cout<<endl<<endl;
    cout<<"\n\t\tGTUSet class\n";
  {
    swr::GtuSet<string> x;
    x.insert("Hi");
    x.insert("Wlc");
    x.insert("To");
    x.insert("the");
    x.insert("gtu family");
    //creating iterator 
    swr::GtuSet<string>::GtuIterator ptr=x.begin();
    //printing elements with iterator 
    for(ptr; ptr!=x.end(); ptr++){
      cout<<*ptr<<" ";
    }
    cout<<endl;
    //with [] overload
    for (int i=0; i<x.size(); i++){
      cout<<x[i]<<" ";
    } 
    cout<<endl;
    //erasing the 2nd element.count starts with 0
    auto p=x.begin()+1;
    x.erase(p);
    cout<<"after deleting 2nd elment\n";
    for(int i=0; i<x.size(); i++){
      cout<<x[i]<<" ";
    }
    cout<<endl;
    //let's insert it back
    x.insert("wlc");
    cout<<"after inserting the elment\n";
    for(int i=0; i<x.size(); i++){
      cout<<x[i]<<" ";
    }
    cout<<endl;
    //if we try to insert same element then it will not accept
    x.insert("wlc");
    cout<<"trying to  insert same elment\n";
    for(int i=0; i<x.size(); i++){
      cout<<x[i]<<" ";
    }
    cout<<endl;
    cout<<"empty state should be false(0): "<<x.empty()<<endl;
    //clearing the set
    x.clear();
    cout<<"After clearing size: "<<x.size()<<endl;
    cout<<"empty state should be false(1): "<<x.empty()<<endl;
  }


}