#include"matrix.h"
int** Slice(int **ar,int r,int c)
{
int **b,i,j;
b=new int*[r];
for(i=0;i<r;i++)
b[i]=new int[c];
for(i=0;i<r;i++)
{
  for(j=0;j<c;j++)
  {
    b[i][j]=ar[i][j];
  }
}
return b;
}
