#include"book.h"
int main()
{int i;
printf("\nENETR THE NUMBER OF BOOKS\n");
int n;
scanf("%d",&n);
b p[n];
printf("\nENTER THE DETAILS\n");
printf("\n1.name 2.serial no 3.usage\n");
FILE *fp;
fp=fopen("xtx","wb+");
for(i=0;i<n;i++)
{
printf("\nbook %d:\n",i+1);
scanf("%s%d%s",p[i].name,&p[i].ser,p[i].usage);
fwrite(&p,sizeof(p),n,fp);
}
 show(fp,n,p);
}
