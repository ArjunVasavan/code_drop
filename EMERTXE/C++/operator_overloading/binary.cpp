#include<iostream>
using namespace std;
class Binary
{
private:
    int i;
    int i1;
public:
    // required constructors
    Binary(int f=0,int i=0):i(f),i1(i)
    {

    } 
    void displayDistance()
    {
        cout<<"i:" <<i <<" i1:" <<i1 <<endl;
    }
    void operator +(int a)
    {
        i+=a;
        i1+=a;
    }
    void operator +(Binary b)
    {
        i+=b.i;
        i1+=b.i1;
    }
};
int main()
{
    Binary B1(11, 10),B2(-5,11);
    int a=10;
    B1+a;           
    B1.displayDistance();
    B1+B2;      
    B1.displayDistance();
    B2.displayDistance();
    return 0;
}

