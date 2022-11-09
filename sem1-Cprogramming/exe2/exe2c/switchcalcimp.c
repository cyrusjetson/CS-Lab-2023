#include"switchcalc.h"
int op(int a,int b,int c)
{
switch(c)
{
case 1:
return a+b;
case 2:
return a-b;
case 3:
return a*b;
case 4:
return a/b;
case 5:
return a%b;
}
}
