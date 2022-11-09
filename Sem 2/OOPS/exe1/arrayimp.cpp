#include"arraylib.h"
int FindMax(int *p,int n)
{
  int i,max=*(p+0);
  for(i=0;i<n;i++)
  {
    if(max<*(p+i))
      max=*(p+i);
  }
  return max;
}

int Occu(int *p,int n,int x)
{
  int i,c=0;
  for(i=0;i<n;i++)
  {
    if(x==*(p+i))
      c++;
  }
  return c;
}

int Sum(int *p,int n)
{
  int i,sum=0;
  for(i=0;i<n;i++)
  {
    sum+=*(p+i);
  }
  return sum;
}
