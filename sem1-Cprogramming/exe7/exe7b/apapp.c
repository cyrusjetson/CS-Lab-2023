#include"ap.h"
void main()
{
int *p[10],i,j,r,c,ch,k=0;
printf("\n Enter the row and Column size \n");
scanf("%d",&r);
scanf("%d",&c);
for(i=0;i<r;i++)
p[i]=(int *)malloc(c*sizeof(int));
printf("\n Enter the matrix :\n");
for(i=0;i<r;i++)
for(j=0;j<c;j++)
scanf("%d",p[i]+j);
printf("\n Enter the row number to sum :\n");
scanf("%d",&ch);
k=sum(p,c,ch);
printf("\n The sum of %d row is :%d\n",ch,k);
}
