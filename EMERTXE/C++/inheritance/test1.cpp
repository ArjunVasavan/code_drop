#include <iostream>
#include <ostream>
using namespace std;

class parent
{
protected:
    int variable_1;
    int variable_2;
    int variable_3;

public:
    void print()
    {
        cout<<variable_1<<endl<<variable_2<<endl<<variable_3<<endl;

    }

    parent(int a,int b,int c )
    {
        cout<<"Parent constructor is called\n";

        variable_1 = a;
        variable_2 = b;
        variable_3 = c;


    }

    ~parent()
    {
        cout<<"Destructor of parent is called is called\n";
    }


};


class child : public parent
{

    int variable_4;
    int variable_5;


public:
    void print(){

        cout<<variable_1<<endl<<variable_2<<endl<<variable_3<<endl<<variable_4<<endl<<variable_5<<endl;
    }

    child (int a,int b,int c,int d,int e) : parent(a,b,c){

        cout<<"Child constructor is called\n";

        variable_4 = d;
        variable_5 = e;
    }
    

    ~child(){

        cout<<"Child destructor is called\n";
    }

};


int main()
{

    parent object1(1,2,3);

    object1.print();


    child object2(1,2,3,4,5);

    object2.print();

}
