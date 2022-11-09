#include"numericlib.h"
int Isprime(int n)
{
  int i,c=0;
  for(i=2;i<n;i++)
  {
    if(n%i==0)
      c++;
  }
  if(c==0)
    return 1;
  return 0;
}

int Mindigit(int n)
{
  int c,min=10;
  while(n>0)
  {
    c=n%10;
    if(c<min)
      min=c;
    n=n/10;
  }
  return min;
}

int Count(int n)
{
  int c=0;
  while(n>0)
  {
    n=n/10;
    c++;
  }
  return c;
}
