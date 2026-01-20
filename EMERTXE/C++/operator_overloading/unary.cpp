 #include<iostream>
 using namespace std;
 class Unary
 {
 private:
 int i;
 int i1;
 public:
 // required constructors
 Unary(int f=0,int i=0):i (f),i1 (i)
 {
 } 
void displayDistance()
 {
 cout<<"i:"<<i<<" i1:" <<i1<<endl;
 }
 // overloaded pre increment operator(prefix)
 void operator ++()
 {
 i+=2;
 i1+=2;
 }

// overloaded pre increment operator(postfix)
 void operator ++(int)
 {
 i+=2;
 i1+=2;
 }
 };
 int main()
 {
 Unary U1(11,10),U2(-5,11);
 ++U1;//pre increment
 U1.displayDistance();//display U1
 U1++; //post increment
 U1.displayDistance();//display U1
 U2++;//post increment
 U2.displayDistance();//display U2
 return 0;
 }

