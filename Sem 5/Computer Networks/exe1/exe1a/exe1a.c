

// Name: Jetson Cyrus J
// RollNo: 19bcs150
// sec: cse c
// computer Networks lab
// exe 1a: Bitstuff and Bit Destuff

#include<stdio.h>
#include<stdlib.h>

// function definition
void printt(int a[50],int);

// function for bitstuff and bit destuff
int bitsource(int arr[50],int n)
{
  int count,k,temp,m,j,i,temp2;
  int flag[8]={0,1,1,1,1,1,1,0};
  int a[50];

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
  
//  Adding intermediate 0ss
  for(i=8;i<n;i++)
  {
     count=0;
     temp=i;
     if( a[temp]==0 )
     {
       i++;
       for(k=i;k<i+5;k++)
       {
         if(a[k]==1)
         {
           count++;
         }
       }
       
       // if count 5 1ss
       if(count==5)
       {
         n++;
         i=i+5;
         k=i;
         temp=a[i];

         // adding 0 if count of 1ss was 5
         a[i]=0;
         for(j=n;j>k;j--)
         {
           a[j+1] = a[j];  
         }
         a[i+1]=temp;
      }
    }  
  }
  
//  Adding ending flag
    j=0;
    for(i=n;i<n+8;i++)
    {
      a[i]=flag[j];
      j++;
    }
 
  n=n+8;
  printf("\n After Bitstuff : ");
  printt(a,n);


//                 ------------------- bit Destuff --------------------
   int b[50];
   j=0;

// removing flags from both sideS
   for(i=8;i<n-8;i++)
   {
        b[j]=a[i];
        j++;
   }
   n=n-16;
   
// removing Escape 0ss
   for(i=0;i<n;i++)
   {
     count=0;
     temp=i;
     if( b[temp]==0 )
     {
       i++;
       for(k=i;k<i+5;k++)
       {
         if(b[k]==1)
         {
           count++;
         }
       }

       // if count 5 1ss
       if(count==5)
       {
         
         i=i+5;
         k=i;

         // removing intermediate 0ss
         for(j=k+1;j<n;j++)
         {
             b[j-1] = b[j];
         }
         n--;
       }
     }
   }
     printf("\n\n After Bit Destuff: ");
     printt(b,n);
     printf("\n");
}


// PriNT function FoR PriNting arrAys
void printt(int a[50],int n)
{
  int m;
  printf("\n   ");
  for (m=0;m<n;m++)
  {
    printf("%d ",a[m]);
  }
  printf("\n");
}


//    MaiN
int main()
{ 
   int n,i;
   printf("\n  ~~~~~~ Bitstuff and Bit Destuff ~~~~~~\n");
   printf("\nEnter total no digits ( Max:25 ): \n");
   scanf("%d",&n);
   int a1[50];
   printf("\nEnter input digits: ");

// GettinG input fRoM UseR
   for( i=0;i<n;i++ )
   {
     scanf("%d",&a1[i]);
   }

//  CaLLinG bit FuNctioN
   bitsource(a1,n);  
   return 0;
}


