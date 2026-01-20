#include <iostream>
template<class T> 

class MyTemplate
{ 
    T element; 
public: 
    MyTemplate(T arg) 
    {
        element=arg;
    } 
    T divideBy2 () 
    {
        return element/2;
    } 
};
int main()
{
    MyTemplate<int>m(10);
    std:: cout<<"division: "<< m.divideBy2()<<std::endl;
    MyTemplate<float>m1(10.50f);
    std::cout<<"division: "<< m.divideBy2()<< std::endl;
    return 0;
}

