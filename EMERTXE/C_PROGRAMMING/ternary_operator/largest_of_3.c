#include<stdio.h>
int main()
{
  printf("Enter 3 number : ");
  int n1,n2,n3;
  scanf("%d %d %d",&n1,&n2,&n3);

  int large = n1 > n2 ? n1 > n3 ? n1 : n3 : n2 > n3 ? n2 : n3;

  printf("Largest is %d\n",large);
}
