#include <iostream>
using namespace std;

class details
{

    int id;
    string name;
    string address;
    
    public:

    void input()
    {
        
        cout<<"Enter ID No:";
        cin>>id;
        cout<<endl<<"Enter Name:";
        cin>>name;
        cout<<endl<<"Enter Address:";
        cin>>address;
    }
    void output()
    {
        cout<<"\n"<<"The ID is: "<<id;
        cout<<endl<<"The Name is: "<<name;
        cout<<'\n'<<"The Address is: "<<address;
    }

};
int main()
{
    details obj;

    obj.input();
    obj.output();


    
}
