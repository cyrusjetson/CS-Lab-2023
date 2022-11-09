#include"car.h"
void car_details(int n)
{
FILE *p;
char name[20];
int speed;
long cost;
p=fopen("car.txt","w");
int i;
for(i=0;i<n;i++)
{
printf("\n Enter the name of car:");
scanf("%s",name);
printf("\n Enter the speed:");
scanf("%d",&speed);
printf("\n Enter the price:");
scanf("%ld",&cost);
fprintf(p,"%s  %d %ld\n",name,speed,cost);
}
fclose(p);
}
void car_recprint(int n)
{
FILE *p;
int i,c=0;
char name[20];
int speed;
long cost;
p=fopen("car.txt","r");
for(i=0;i<n;i++)
{
fscanf(p,"%s %d %ld\n",name,&speed,&cost);
if(cost>=500000)
printf("%s %d %ld\n",name,speed,cost);
else
c++;
}
if(c==n)
printf("\n no records are above 500000\n");
fclose(p);
}
