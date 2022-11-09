#include"matrix.h"
void readmat(int M[5][5],int r,int c)
{
 int i,j;
 for(i=0;i<r;i++)
     for(j=0;j<c;j++)
        scanf("%d",&M[i][j]);
}
void displaymat(int M[5][5],int r,int c)
{
 int i,j;
 for(i=0;i<r;i++)
   {
     for(j=0;j<c;j++)
     {
      printf("%d ",M[i][j]);   
     }
     printf("\n");
  }
}
void mulmat(int a[5][5],int b[5][5],int c[5][5],int r1,int c1,int c2)
{
 int i,j,k;
  for(i=0;i<r1;i++)
     for(j=0;j<c2;j++)
     {
       c[i][j]=0;
       for(k=0;k<c1;k++)
             c[i][j]+=a[i][k]*b[k][j];
     }
}
