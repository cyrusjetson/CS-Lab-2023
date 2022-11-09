#include"findcalc.h"
int findcalc(int a,int b,char c)
{
if(c=='+')
return a+b;
else if(c=='-')
return a-b;
else if(c=='/')
return a/b;
else if(c=='*')
return a*b;
else if(c=='%')
return a%b; 
}
