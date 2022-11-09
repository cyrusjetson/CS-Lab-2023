#include"occurence.h"
int findacc(int n,int acc[10],int b)
{
   int i,k=0;
    for(i=0;i<n;i++)
    {
	if(acc[i]==b)
      k++;
    }
return k;
}
