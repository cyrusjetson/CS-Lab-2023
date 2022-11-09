#include"switchcalc.h"
int main()
{
int a,b,c,n;
printf("Enter the two numbers\n");
scanf("%d%d",&a,&b);
printf("1.Add\n2.Substract\n3.Multiply\n4.Divition\n5.Modulas\n");
printf("Enter the operation to be perform\n");
scanf("%d",&c);
n=op(a,b,c);
printf("Answer is %d\n",n);
}
