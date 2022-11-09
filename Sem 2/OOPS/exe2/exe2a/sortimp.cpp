#include"sort.h"
int* Sort(int *a,int n)
{
   int i,j,temp;
   int *b=new int[n];
   for(i=0;i<n;i++)
       b[i]=a[i];
   for(i=0;i<n-1;i++)
   {
     for(j=i+1;j<n;j++)
     {
        if(b[i]>b[j])
        {
            temp=b[j];
            b[j]=b[i];
            b[i]=temp;      
        }     
     }
   }
   return b;
}
float* Sort(float *a,int n)
{
   int i,j;
   float temp;
   float *b=new float[n];
   for(i=0;i<n;i++)
       b[i]=a[i];
   for(i=0;i<n-1;i++)
   {
     for(j=i+1;j<n;j++)
     {
        if(b[i]>b[j])
        {
            temp=b[j];
            b[j]=b[i];
            b[i]=temp;
        }
     }
   }
   return b;
}
char* Sort(char *a,int n)
{
   int i,j;
   char temp;
   char *b=new char[n];
   for(i=0;i<n;i++)
       b[i]=a[i];
   for(i=0;i<n-1;i++)
   {
     for(j=i+1;j<n;j++)
     {
        if(b[i]>b[j])
        {
            temp=b[j];
            b[j]=b[i];
            b[i]=temp;
        }
     }
   }
   return b;
}
