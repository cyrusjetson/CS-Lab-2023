#include"sum.h"
int sum(int n)
{
  int s,i;
  i = 1;
  s = 0;
  while(i<=n)
  {
     s=s+i;
     i=i+1;
  }
  return s;
}
