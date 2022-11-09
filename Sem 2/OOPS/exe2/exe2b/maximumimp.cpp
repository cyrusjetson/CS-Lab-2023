#include"maximum.h"
int Maxwith(int *a,int n)
{
  int i;
  long int l=a[0];
  for(i=0;i<n;i++)
     if(a[i]>l)
        l=a[i];
  return l;
}
int Maxout(int *a,int n)
{
  int i,*b;
  long int l=a[0];
  b=new int[n];
  for(i=0;i<n;i++)
     b[i]=a[i];
  for(i=0;i<n;i++)
    if(b[i]<0)
      b[i]=b[i]*(-1);
  for(i=0;i<n;i++)
     if(b[i]>l)
       l=b[i];
  return l;
}
