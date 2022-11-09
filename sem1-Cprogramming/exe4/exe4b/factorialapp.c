#include"factorial.h"
int main()
{int n;
long r;
printf("Enter the number\n");
scanf("%d",&n);
r= find_factorial(n);
printf("The factorial of the given number is : %ld\n",r);
}
