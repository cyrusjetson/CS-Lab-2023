#include "menu.h"
int main()
{
 int ch,count=0;
 char str1[40],str2[40];
 do
 {
  printf("\nEnter the respective numbers for their respective functions ");
  printf("\n1.String Length\n2.String Copy");
  printf("\n3.String Concat\n4.String Reverse");
  printf("\n5.Exit\n");
  printf("\nEnter your choice\n");
  scanf("%d",&ch);

  switch (ch)
  {
   case 1:
    printf("\nEnter the string : ");
    scanf("%s",str1);
    count=len(str1);
    printf("Length = %d",count);
   break;
   case 2:
    printf("\nEnter String1:");
    scanf("%s",str1);
    printf("Enter String2:");
    scanf("%s",str2);
    copy(str1,str2);
    printf("\nThe copied string is : ");
    puts(str2);
   break;
   case 3:
    printf("\nEnter String1:");
    scanf("%s",str1);
    printf("Enter String2:");
    scanf("%s",str2);
    cat(str1,str2);
    printf("\nThe concatenated string is : ");
    puts(str1);
   break;
   case 4:
    printf("\nEnter the string : ");
    scanf("%s",str1);
    reverse(str1);
    printf("\nThe reversed string is :");
    puts(str1);
   break;
   case 5:
    exit(0);
  }
}
 while(ch<6);
}
