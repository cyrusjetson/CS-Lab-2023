#include"struc.h"
int main()
{
int i,n,ch;
char b[20];
em emp[10];
printf("enter how many employee\n");
scanf("%d",&n);
printf("enter the record of employee\n");
for(i=0;i<n;i++)
{
printf("\n name :");
scanf("%s",emp[i].name);
printf("\n eployee Id :");
scanf("%d",&emp[i].empId);
printf("\n desigination:");
scanf("%s",emp[i].design);
printf("\n enter branch :");
scanf("%s",emp[i].branch);
printf("\n enter basic pay :");
scanf("%d",&emp[i].baspay);
emp[i].netsal=((emp[i].baspay+1000)-0.12*emp[i].baspay);
}
do
{
printf("\nenter\n");
printf("1 for highest salary holder\n");
printf("2 for salary  b/w 3lakh to 6lakhs\n");
printf("3 for display all managers\n");
printf("4 for emplyee in branch\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
high_sal(emp,n);
break;
case 2:
sal_range(emp,n);
break;
case 3:
designation(emp,n);
break;
case 4:
printf("enter the place\n");
scanf("%s",b);
branch(emp,n,b);
break;
default:
printf("invalid input\n");
}}while(ch>=1&&ch<=4);
}

