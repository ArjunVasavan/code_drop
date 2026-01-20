#include <iostream>
using namespace std;

class test
{

    int x;
    int y;

public:
    void print()
    {
        cout<<x<<endl<<y<<endl;
    }

    test(int a = 0 , int b = 0){

        x = a;
        y= b;

    }
 // for --object
    test operator -- (){

        --x;
        --y;

        return *this;

    }

// for object--
    test operator -- (int){

        test temp;

        temp.x = x;
        temp.y = y;

        x-=1;
        y-=1;

        return temp;
    }



};

int main()
{

    cout<<"Pre decrement\n";

    test object1(10,20);

    cout<<"Initially object1 contains\n";

    object1.print();

    test object2 = --object1;
    

    cout<<"Value inside object2\n";

    object2.print();


    cout<<"Value inside object1\n";

    object1.print();

    cout<<"Now Post decrement\n";

    object1 = {10,20};

    cout<<"Initially object1 contains\n";

    object1.print();

    object2 = object1--;

    cout<<"Value inside object2\n";

    object2.print();

    cout<<"Value inside object1\n";

    object1.print();


}
