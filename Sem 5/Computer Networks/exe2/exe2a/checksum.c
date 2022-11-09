#include<stdio.h>
#include<string.h>
void sum(int byte1[8],int byte2[8])
{
  int sum=0;
  int i,n1,n2;
  for(i=7;i>=0;i--)
  {
    n1=byte1[i];
    n2=byte2[i];
    byte1[i]=byte1[i]^byte2[i]^sum;
    if((n1+n2+sum)>1)
      sum=1;
    else
      sum=0;
  }
}

void checkSumSender(int n,int result[n+1][8])
{
  int byte[8];
  int resultant[8]={0,0,0,0,0,0,0,0};
  int i,k,l=0;
  printf("\n   ~~~~~ Checksum Sender ~~~~~\n");
  for(k=0;k<n;k++)
  {
    printf("\nEnter byte %d: ",(k+1));
    l=0;
   // ch=getchar();

    for(i=0;i<8;i++)
    {
      
      scanf("%d",&byte[i]);
      l++;
    }
    /*printf("%d",l);
    if(l>=8){
     printf("\n Enter valid data\n");
     k--;
     goto x;
    }
    if(l<8){
     
    }*/
    for(i=0;i<8;i++)
    {
      result[k][i]=byte[i];
    }
    sum(resultant,byte); 
  }
  printf("\n");
  int var; 
  for(i=0;i<8;i++)
  {
    if(resultant[i]==1)
      var=0;
    else
      var=1;
    result[k][i]=var;
  } 
}

int receiver(int n,int checkSum[8])
{
  int i,j;
  int byte[8];
  int resultantt[8]={0,0,0,0,0,0,0,0};
  printf("\n   ~~~~~ Checksum Receiver ~~~~~\n");
  printf("\n");
  for(i=0;i<n;i++)
  {
    printf("\nEnter received byte %d: ",(i+1));
    for(j=0;j<8;j++)
    {
      scanf("%d",&byte[j]);
    }
    sum(resultantt,byte);
  }
  sum(resultantt,checkSum);
  return isFullOne(resultantt);
}

int isFullOne(int byte[8])
{
  int i=0;
  for(i=0;i<8;i++)
  {
    if(byte[i]!=1)
      return 0;
  } 
  return 1;
}
 
int main()
{
  int i,j;
  int n;
  printf("\n   ~~~~~ Checksum ~~~~~\n");
  printf("\nEnter the number of bytes in your data: ");
  scanf("%d",&n);
  int resultant[n+1][8];
  checkSumSender(n,resultant);
  printf("\nSender Result: \n\n");
  for(i=0;i<=n;i++)
  {
    for(j=0;j<8;j++)
    {
      printf("%d ",resultant[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  int checkSum[8];
  printf("%d",n-1);
  for(i=0;i<8;i++)
  {
    checkSum[i]=resultant[n][i];
  }
  if(receiver(n,checkSum))
    printf("\nNo Error\n");
  else
    printf("\nError\n");
  return 0;
}
