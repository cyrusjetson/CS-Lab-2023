#include"car.h"
int main()
{
int n;
printf("enter no. of cars\n");
scanf("%d",&n);
car_details(n);
printf("details of car which cost more than 5lakhs\n");
car_recprint(n);
}
