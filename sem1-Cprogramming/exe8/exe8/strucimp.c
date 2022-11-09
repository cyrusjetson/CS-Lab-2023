#include"struc.h"
void high_sal(em emp[10],int n)
{
int i;
float max=0;
for(i=0;i<n;i++)
{
if(emp[i].netsal>max)
max=emp[i].netsal;
}
for(i=0;i<n;i++)
if(max==emp[i].netsal)
display(emp[i]);
}
void display(em emp)
{
printf("\n Name :");
printf("%s",emp.name);
printf("\n Empid :");
printf("%d",emp.empId);
printf("\n Desig :");
printf("%s",emp.design);
printf("\n  Branch :");
printf("%s",emp.branch);
printf("\n Bpay :");
printf("%d",emp.baspay);
printf("\n Netsal is :");
printf("%f",emp.netsal);
}
void sal_range(em emp[10],int n)
{
int i;
for(i=0;i<n;i++)
{
if(emp[i].netsal>300000&&emp[i].netsal<600000)
display(emp[i]);
}
}
void designation(em emp[10],int n)
{
int i;
for(i=0;i<n;i++)
{
if(strcmp(emp[i].design,"manager")==0)
display(emp[i]);
}
}
void branch(em emp[10],int n,char b[20])
{
int i;
for(i=0;i<n;i++)
{
if(strcmp(emp[i].branch,b)==0)
display(emp[i]);
}
}
