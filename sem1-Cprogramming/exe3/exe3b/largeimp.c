#include"large.h"
int big(int n)
{
  int a,i,big;
  i = 1;
  big = -99999;
  do
  {
    scanf("%d",&a);
    if(big<a)
      {
        big=a;
      }
    i=i+1;
  }
  while(i<=n);
  return big;
}
