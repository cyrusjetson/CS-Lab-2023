#include"acc.h"
void main()
{
cust *p;
cust c[10];
int i,n,acno;
char s[20];
printf("Enter the no of customers:");
scanf("%d",&n);
p=&c[n];
printf("Enter cust details:\n");
for(i=0;i<n;i++)
{
printf("\n Enter name:");
scanf("%s",c[i].cname);
printf("\n Enter the accno");
scanf("%d",&c[i].accno);
printf("\nEnter the balance ");
scanf("%d",&c[i].balance);
printf("\n Enter the address");
scanf("%s",c[i].add);
}
printf("\n Enter the name to be searched:");
scanf("%s",s);
searchnames(c,n,s);
printf("\n Enter the accno to be searched:");
scanf("%d",&acno);
p=searchAcno(c,n,acno);
displayrecord(p);
}
