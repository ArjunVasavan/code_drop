#include <iostream>

using namespace std;
class test 
{
    int a;
    int b;

    void print(int a,int b)
    {
        cout<<a<<endl;

        cout<<a<<endl;
    }

    void swap(int& x,int& y)
    {
        x = x ^ y;
        y = x ^ y;
        x = x ^ y;

    }
};

int main()
{
    test obj(10,20);

    

    
}
