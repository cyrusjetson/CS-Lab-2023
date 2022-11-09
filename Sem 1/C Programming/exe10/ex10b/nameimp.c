#include"name.h"
int get_name()
{
FILE *n=fopen("name.txt","w");
char name[20];
int cnt=0;
do
{
printf("enter \n");
scanf("%s",name);
fprintf(n,"%s\n",name);
cnt=cnt+1;
}while(strcmp(name,"end")!=0);
fclose(n);
n=fopen("name.txt","r");
printf("\n     the names are\n");
fgets(name,20,n);
while(!feof(n))
{
printf("%s\n",name);
fgets(name,20,n);
}
printf("there are %d number of name\n",cnt-1);
}
