#include"pointer.h"
void main()
{
int *p,n,i,k=0;
float a=0;
printf("\n Enter the number of elements \n");
scanf("%d",&n);
p=(int *)malloc(n*sizeof(int));
printf("Enter the elements\n");
for(i=0;i<n;i++)
scanf("%d",p+i);
k=sum(p,n);
a=avg(p,n);
printf("\n The Sum is : %d",k);
printf("\n The average is : %f\n",a);
}
