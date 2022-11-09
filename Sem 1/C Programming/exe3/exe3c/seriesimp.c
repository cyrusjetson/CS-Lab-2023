#include"series.h"
void series()
{
int n,a,b,c,i;
printf("Enter the number of terms\n");
scanf("%d",&n);
printf("The elements of fibanacci series is\n");
a=-1;b=1;
for(i=1;i<=n;i++)
{
c=a+b;
printf("%d\n",c);
a=b;
b=c;
}
}
