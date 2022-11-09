#include"sort.h"
void main()
{
char names[10][10];
int i,n;
printf("\tSorting Of Names\n");
printf("\nEnter the no of names you want to enter\n");
scanf("%d",&n);
printf("Enter the names\n");
for(i=0;i<n;i++)
scanf("%s",names[i]);
sort(names,n);
printf("The names after sorted are:\n");
for(i=0;i<n;i++)
printf("%s ",names[i]);
printf("\n");
}
