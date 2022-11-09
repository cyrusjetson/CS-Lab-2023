
// Name: Jetson Cyrus J
// Rollno: 19bcs150
// sec: cse c
// computer networks lab
// exe1b : Bytestuff and Byte Destuff

#include<stdio.h>
#include<stdlib.h>

// funtion definition
void printt(int a[80],int);

// Funtion for Bytestuff and byte destuff 
int bytesource(int arr[80],int n)
{
  int count,k,temp,m,x,j,i,temp2;
  x=0;
  int flag[8]={0,1,1,1,1,1,1,0};
  int escape[8]={0,1,1,1,1,1,0,1};
  int a[80];

//  ----- ByteStuff -----
// Adding flag at front
   for(i=0;i<8;i++)
   {
        a[i]=flag[i];
   }
   j=0;
   for(i=8;i<n+8;i++)
   {
       a[i]= arr[j];
       j++;
   }
   n=n+8;

//  Adding Escape
  for(i=8;i<n;x++)
  {
     count=0;
     temp=i;
     if( a[temp]==0 )
     {
       for(k=i+1;k<i+6;k++)
       {
         if(a[k]==1)
         {
           count++;
         }
       }

//  checking count of 1ss 
       if(count==5)
       {
         k=i+6;
         if( ( a[k]==0 && a[k+1]==1 ) || ( a[k]==1 && a[k+1]==0 ))
         {
            for(j=n;j>i-1;j--)
            {
               a[j+8]= a[j];
            }
            temp2=0;

// Adding escape if pattern occurs
            for(j=i;j<i+8;j++)
            {
               a[j]=escape[temp2];
               temp2++;
            }
	    i=i+8;
	    n=n+8;
         }
       }
    }
	i=i+8;
  }

// Addding ending flag
    j=0;
    for(i=n;i<n+8;i++)
    {
      a[i]=flag[j];
      j++;
    }

  n=n+8;
  printf("\n After Bytestuff : ");
  printt(a,n);

// removinG flags at both sideS
   int b[80];
   j=0;
   for(i=8;i<n-8;i++)
   {
        b[j]=a[i];
        j++;
   }
   n=n-16;

//  removing Escape 
  for(i=0;i<n;x++)
  {
     count=0;
     temp=i;
     if( b[temp]==0 )
     {
	   
       for(k=i+1;k<i+6;k++)
       {
         if(b[k]==1)
         {
           count++;
         }
       }
       if(count==5)
       {
	 k=i+6;
         if( b[k]==0 && b[k+1]==1 )
         {
            for(j=i;j<n;j++)
            {
	      b[j]=b[j+8];
            }
            n=n-8;
         }
       }
    }
    i=i+8;
  }

     printf("\n\n After Byte Destuff: ");
     printt(b,n);
     printf("\n");
}

//  printing funtion for arrays
void printt(int a[80],int n)
{
  int count=0,m;
  printf("\n   ");
  for (m=0;m<n;m++)
  {
    printf("%d ",a[m]);
	count++;
	if (count==8)
	{
	   count=0;
	   printf ("\n   ");
	}
  }
}


//  MaiN funtioN
int main()
{
   int n,i;
   printf("\n  ~~~~~  Bytestuff and Byte Destuff  ~~~~~\n");
   printf("\nEnter total no bytes ( Max:7 ): ");
   scanf("%d",&n);
   int a[80];
   n=n*8;
   printf("\nEnter input digits: ");

// getting input from useR
   for( i=0;i<n;i++ )
   {
     scanf("%d",&a[i]);
   }

// calling function
   bytesource(a,n);
   return 0;
}
