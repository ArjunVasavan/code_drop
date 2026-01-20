#include<iostream>

using namespace std;


class Test // naming class with Test
{
	 int x; // declaring int x
	 int y; // delcaring integer y
	public: // public mode so others can access like the external ones
	 int *ptr; // creating an pointer which will point to integer


	 Test() // consrtuctor "Default constructor"
	 {
		 cout<<"Default cnstructor\n";
		 x=0; // x = 0
		 y=0; // y = 0
		 ptr=(int *) malloc(4); // 4 byte dma is created
		 *ptr=0; // putting zero there
	 }

	 Test(int a,int b,int c) // paramterized constructor
	 {
		 cout<<"Paramterized constructor\n";
		 x=a; // assinging value of input a to x
		 y=b; // b to y
		 ptr=(int *)malloc(4); // also creating another pointer
		 *ptr=c; // putting c value to that pointer
	 }

	 Test(Test & oref) // creating an reference of type test inside constructor to do copy constructor
	 {
		 cout<<"Copy constructor called\n";
		 x=oref.x; // 
		 y=oref.y;
		 ptr=(int *)malloc(4);
		 *ptr=*oref.ptr;
	 }

	 void print()
	 {
		 cout<<x<<endl<<y<<endl<<*ptr<<endl;
	 }

	 ~Test()
	 {
		 free(ptr);
	 }
};

int main()
{
	{
		Test o1; // creating an object from class test

	}

	//1000 lines codes
}

