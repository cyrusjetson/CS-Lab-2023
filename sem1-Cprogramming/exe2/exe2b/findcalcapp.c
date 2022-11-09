#include"findcalc.h"
int main()
{
int a,b;
int ans;
char c;
printf("Enter the operation to be perform\n");
printf("Add(+)\n");
printf("Sustract(-)\n");
printf("Divide(/)\n");
printf("Multiplication(*)\n");
printf("Modulas(%)\n");
scanf("%c",&c);
printf("Enter the numbers\n");
scanf("%d%d",&a,&b);
ans=findcalc(a,b,c);
printf("Answer is %d\n",ans);
}
