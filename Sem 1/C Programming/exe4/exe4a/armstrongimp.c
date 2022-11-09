#include"armstrong.h"
int armstrong(int n)
{
 int a,b,q,r,c,s;
 a=n; 
 s=0;
 c=0;
 while(a>0)
{
 a=a/10;
 c++;
}
 while(n!=0)
{
 q=n/10;
 r=n%10; 
 b=pow(r,c);
 s=s+b;
 n=q;
}
 return s;
}
