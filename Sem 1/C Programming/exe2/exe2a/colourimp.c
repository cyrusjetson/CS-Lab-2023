#include"colour.h"
int findcolour(char ch)
{
if(ch=='r')
return 1;
else if(ch=='g')
return 2;
else if(ch=='b')
return 3;
else if(ch=='y')
return 4;
else if(ch=='w')
return 5;
else
return 0;
}
