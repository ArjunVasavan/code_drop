#include<iostream>

using namespace std;

class Test
{
	int a; // declaring a
	int b; // declaring b
	int c; // declaring c

	public: // functions are putted public

	Test(int x,int y,int z) // an constructor which takes input x,y,z
	{
		cout<<"Parent constructor called\n"; // just to notice that parent is called
		a=x; // assigning x to a
		b=y; // assingning b to y
		c=z; // assigning z to c
	}

	void print() // print function
	{
		cout << a << endl <<b << endl << c << endl;
	}

	~Test() // an destryctor ~() 
	{
		cout<<"Parent destructor called\n";
	}
};


class Child : public Test
// this is an child whichs parent is test as public
{
	int d; // declaring d
	int e; // declaring e

	public: // public for user to access
	int add() // add function 
	{
		return d+e; // returning sum of d and e
	}

	Child(int m,int n,int o,int p,int q) : Test(o,p,q) // child consturctor which takes sum of parent and child inputs and were passing o p q which are read to test
    {
		cout<<"Child constructor called\n"; // to know that child constructor is called
		d=m; // assigning
		e=n;
	}
	~Child()
	{
		cout<<"Child destructor called\n";
	}
};

int main() // main function in cpp
{
	// Test op(10,20,30); // this is to call perent function
	// Child oc(1,2,3,4,5);
}

