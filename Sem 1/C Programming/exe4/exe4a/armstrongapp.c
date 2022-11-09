#include"armstrong.h"
void main()
{
 int n,num;
 printf("Enter the number\n");
 scanf("%d",&n);
 num=armstrong(n);
 if (num==n)
{
 printf("The number is armstrong\n");
}
 else
{
 printf("The number is not a armstrong\n");
}
}
