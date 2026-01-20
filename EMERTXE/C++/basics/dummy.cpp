class Parent
 {
 int id;
 protected:
 float f;
 public:
 Parent()
 {
 id=0;
 f=10.05;
 }
 void display()
 {
 cout<<id<<endl<<f<<endl;
 }
 };
 class Child:publicParent
 {
 public:
 void ch()
 {
 cout<<f<<endl;
 }
 };
 };
 int main()
 {
 Parent p;
 p.display();
 Child c;
 c.ch();
 return 0;
 }

