#include"guest.h"
int fact(int n)
{
  int i,sum=1;
  for(i=1;i<=n;i++)
  {
   sum=sum*i;
  }  
  return sum;}
int fibo(int n)
{ 
  int a,b,c=0;
  int i=0;
    a=-1;
    b=1;
 while(i<n)
  {
    c=a+b;
    a=b;
    b=c;
    i=i+1;
   }
return b;}
 void compute(int n)
{  int ch,r,r1;
   char f;
  do{ 
   printf("\n enter 1.for factorial,2.for fiboseries\n");
   scanf("%d",&ch);
 switch(ch)
  {
    case 1:  r1=fact(n);
             printf("\n factorial: %d\n",r1);
              break;
    case 2:  r=fibo(n); 
              printf("\n nth fiboseries: %d\n",r);
              break;
   }}while(ch>=1&&ch<=1);
   
}

