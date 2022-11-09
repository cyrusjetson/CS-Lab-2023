#include"occurence.h"
int main()
{
int i,acc[10],n,b,ans;
printf("Enter How Many Elements Do U Want :\n");
scanf("%d",&n);
printf("Enter The Elements:\n");
for(i=0;i<n;i++)
scanf("%d",&acc[i]);
printf("Which Number Do U Want To Find Occurance :\n");
scanf("%d",&b);
ans=findacc(n,acc,b);
printf("The number is in %d times\n",ans);
}

