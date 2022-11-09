#include"sum.h"
int main()
{
  int n,s;
  printf("Enter the number of terms\n");
  scanf("%d",&n);
  s = sum(n);
  printf("Sum of the given term is %d\n",s);
}
