#include"book.h"
void display(b p)
{
 printf("\nname:  serial no:  usage:\n");
 printf("\n%s    %d    %s\n",p.name,p.ser,p.usage);
}
void show( FILE *fp, int n ,b p[20]) 
{
 printf("\nenter the substring to be searched\n");
 int i,a,c=0;
 char s[15];
 scanf("%s",s);
 for(i=0;i<n;i++) 
{ fread(&p,sizeof(p),1,fp);
  a=strstr(p[i].name,s);
  if(a)
  { c++;
   display(p[i]);
}
  if(c==0)
 printf("\nthere is no book with this substring\n");
   
}
}
