#include"acc.h"
cust* searchAcno(cust c[10],int n,int acno)
{
int i,o=0;
for(i=0;i<n;i++)
{
 if(c[i].accno==acno)
 {  
  return &c[i];
  o++;
 }
}
if(o==0)
 printf("there is no record for this acc no.\n");
}
void searchnames(cust c[10],int n,char na[20])
{
int i,m=0;
for(i=0;i<n;i++)
{
 if(strcmp(c[i].cname,na)==0)
   {
    displayrecord(c);
    m++;
   }
}
if(m==0)
 printf("there is no record \n");
}
void displayrecord(cust *c)
{
printf("Customer Name:%s\n",c->cname);
printf("Accno:%d\n",c->accno);
printf("Balance:%d\n",c->balance);
printf("Address:%s\n",c->add);
}
