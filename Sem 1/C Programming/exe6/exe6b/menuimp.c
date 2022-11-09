#include"menu.h"
int len(char str1[])
{
        int i=0;
        while(str1[i]!='\0')
                i++;
        return i;
}
void copy(char str1[],char str2[])
{
        int i,n=0;
        while(str1[n]!='\0')
        n++;
        for(i=0;i<n;i++)
                str1[i]=str2[i];
}
void cat(char str1[],char str2[])
{
        int i,n=0;
        while(str1[n]!='\0')
        n++;
        for(i=0;i<n;i++)
                str1[n+i]=str2[i];
}
void reverse(char str1[])
{
        int i,n=0,j;
        char temp[30];
        while(str1[n]!='\0')
                n++;
        for(i=0;i<n;i++)
                temp[i]=str1[i];
        for(i=--n,j=0;i>=0;i--,j++)
                str1[j]=temp[i];
}
