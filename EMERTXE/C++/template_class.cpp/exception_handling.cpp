#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cout<< "Enter two values: ";
    cin>> a >> b;
    try
    {
        if (b != 0) {
            cout << "Res: " << a / b << endl;
        }
        else {
            throw b;
        }
    }
    catch(int x)
    {
        cout<< "Caught DIVIDE_BY_ZERO ERROR" << "b: "<< x << endl;
    }
}

