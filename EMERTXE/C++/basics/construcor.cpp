#include <iostream>
using namespace std;
class test
{
    int a;
    int b;

    public:
    void print()
    {
        cout<<a<<endl;
        cout<<b<<endl;
    }

    test(int val1,int val2)
    {
        a = val1;
        b = val2;
    }
};
int main()
{
    test obj1(10,20);
    obj1.print();
    test obj2(10,20);
    obj1.print();
}
