#include"ap.h"
int sum(int *a[10],int c,int ch)
{
int i,c1=0;
for(i=0;i<c;i++)
c1+=*(a[ch-1]+i);
return c1;
}
