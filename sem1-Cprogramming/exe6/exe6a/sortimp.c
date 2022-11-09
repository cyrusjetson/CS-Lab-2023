#include"sort.h"
void sort(char n[][10],int na)
{
char t[10];
int i,j;
for(i=0;i<na-1;i++)
for(j=i+1;j<na;j++)
if(strcmp(n[i],n[j])<0)
{
strcpy(t,n[i]);
strcpy(n[i],n[j]);
strcpy(n[j],t);
}
}
