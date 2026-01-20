#include <stdio.h>
union u 
{
  int x; 
  char ch;
};
int main()
{

  union u var;

  var.x = 0x12345678;
  var.ch = var.x;
  if ( var.ch == 0x78 )
  {
    printf("Its an Little Endian\n");
  }
  else {
    printf("Its An big Endian\n");
  }
}
