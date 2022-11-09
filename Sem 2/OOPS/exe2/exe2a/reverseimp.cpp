#include"reverse.h"
int Reverse(int n)
{
  int r,sum=0;
  while(n!=0)
  {
     r=n%10;
     sum=sum*10+r;
     n=n/10;
  }
  return sum;
}
char* Reverse(char* x,int n)
{
    char *a=new char[n+1];
    int i,j;
    j=n-1;
    for(i=0;i<n;i++)
    {
       a[i]=x[j];
       j--;
    }
    a[i]='\0';
    return a;
}
