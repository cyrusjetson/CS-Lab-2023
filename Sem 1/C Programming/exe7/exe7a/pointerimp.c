#include"pointer.h"
int sum(int *p,int n)
{
int i,s=0;
for(i=0;i<n;i++)
if(*(p+i)>=0)
s+=*(p+i);
return s;
}
float avg(int *p,int n)
{
float s=0.0;
int s1=0,i,c=0;
for(i=0;i<n;i++)
{
if(*(p+i)<0)
{
s1+=*(p+i);
c++;
}
}
s=(1.0*s1)/c;
return s;
}
