#include <algorithm>
#include <iostream>
using namespace std;

class test{

    int x;
    int y;

public:
    test(int a = 0 , int b = 0 ){

        x = a;
        y = b;
    }

    void print(){

        std::cout <<x<<" "<<y<<" ";

    }

    test operator ! (){

        test temp;

        temp.x = !x;
        temp.y = !y;

        return temp;
    }

};

int main()
{

    test object(1,0);

    cout<<"Object now contains => ";

    object.print();

    object = !object;

    cout<<endl;

    cout<<"Object After operation contains => ";

    object.print();
    
}
