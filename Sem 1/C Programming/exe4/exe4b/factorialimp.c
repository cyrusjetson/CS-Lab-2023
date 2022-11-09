#include"factorial.h"
long find_factorial(int n)
{
if (n==0)
return 1;
return n*find_factorial(n-1);
}
