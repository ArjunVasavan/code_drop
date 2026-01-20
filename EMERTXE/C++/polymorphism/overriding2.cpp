#include<iostream>
using namespace std; 
class BaseClass
{ 
public: 
    void disp()
    { 
        cout<<"Function of Parent Class"; 
    } 
}; 
class DerivedClass: public BaseClass
{ 
public: 
    void disp() 
    { 
        cout<<"Function of Child Class"; 
    } 
};
int main() 
{ 
    BaseClass*obj= new DerivedClass(); 
    obj->disp(); 
    return 0; 
}

