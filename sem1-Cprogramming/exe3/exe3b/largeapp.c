#include"large.h"
int main()
{
  int n,b;
  printf("Enter the number of terms\n");
  scanf("%d",&n);
  printf("Enter the elements in the list\n");
  b = big(n);
  printf("The biggest of the given numbers is %d\n",b);
}
