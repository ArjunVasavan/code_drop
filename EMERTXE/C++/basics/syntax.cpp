#include <iostream>
#include <string>
using namespace std;

class employee
{
private:
    int id;
    string name;
    string address;
public:
    void get_data(){
        
        cout<<"Enter id : ";
        cin>>id;

        cout<<"Enter Name : ";
        cin>>name;

        cout<<"Enter address : ";
        cin>>address;
    }

    void print_data(){
        
        cout<<id<<endl;

        cout<<name<<endl;

        cout<<address<<endl;
    }

};
int main()
{
    employee arjun;

    arjun.get_data();
    
    arjun.print_data();
}
