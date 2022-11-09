#include<stdio.h>
#include<stdlib.h>

int absolute(int a,int b)
{
 int c;
 c=b-a;
 if(c<0)
  return -c;
 else
  return c;
}
int main()
{
   int option,m,n,x,start,i,j,pos,min,a[15],count;
   count=0;

   printf("\nEnter disk size      : ");
   scanf("%d",&m);
   printf("\nEnter no of requests : ");
   scanf("%d",&n);
   printf("\nEnter Request queue  : ");

   for(i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
       if(a[i]>=m)
       {
           printf("\ninvalid input");
           scanf("%d",&a[i]);
       }
   }
   printf("\nEnter R/W head position : ");
   scanf("%d",&start);
   printf("\nFCFS Scheduling Algorithm \n");
   printf("\n%d\t",start);
   for(i=0;i<n;i++)
   {
       x-=a[i];
       if(x<0)
            x=-x;
       count+=x;
       x=a[i];
       printf("%d\t",x);
   }
   printf("\nTotal Seek time :%d\n",count);
   printf("\nSSTF Scheduling Algorithm \n");
   printf("\n%d\t",start);
   for(i=0;i<n;i++)
   {
       min=absolute(a[i],x);
       pos=i;
       for(j=i;j<n;j++)
            if(min>absolute(x,a[j]))
            {
                     pos=j;
                    min=absolute(x,a[j]);
            }
      count+=absolute(x,a[pos]);
      x=a[pos];
      a[pos]=a[i];
      a[i]=x;
      printf("%d\t",x);
   }
   printf("\nTotal Seek time : %d\n",count);
   printf("\nSCAN Scheduling Algorithm \n");
   count=0;
   pos=0;
   for(i=0;i<n;i++)
      for(j=0;j<n-i-1;j++)
         if(a[j]>a[j+1])
         {
            x=a[j];
            a[j]=a[j+1];
            a[j+1]=x;
         }
   for(i=0;i<n;i++)
      if(a[i]<start)
          pos++;
   for(i=0;i<pos;i++)
      for(j=0;j<pos-i-1;j++)
         if(a[j]<a[j+1])
         {
             x=a[j];
             a[j]=a[j+1];
             a[j+1]=x;
         }
   x=start;
   printf("%d\t",x);
   for(i=0;i<pos;i++)
   {
         count+=absolute(a[i],x);
         x=a[i];
         printf("%d\t",x);
   }
   count+=absolute(x,0);
   x=0;
   printf("%d\t",x);
   for(i=pos;i<n;i++)
   {
         count+=absolute(a[i],x);
         x=a[i];
         printf("%d\t",x);
   }
   printf("\nTotal Seek time : %d\n",count);

   printf("%d\t",start);
   count=0;
   pos=0;
   for(i=0;i<n;i++)
      for(j=0;j<n-i-1;j++)
          if(a[j]>a[j+1])
             {x=a[j];
              a[j]=a[j+1];
              a[j+1]=x;
             }
   for(i=0;i<n;i++)
      if(a[i]<start)
          pos++;
      x=start;
   for(i=pos;i<n;i++)
   {
       count+=absolute(x,a[i]);
       x=a[i];
       printf("%d\t",x);
   }
   for(i=0;i<pos;i++)
   {count+=absolute(x,a[i]);
    x=a[i];
    printf("%d\t",x);
   }
   printf("\nTotal Seek time : %d\n\n",count);
}

