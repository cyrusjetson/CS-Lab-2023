#include"colour.h"
void main()
{
  char ch;
  int ans;
  printf("Enter the colour(r,g,b,y,w)\n");
  scanf("%c",&ch);
  ans=findcolour(ch);
  if (ans==1)
  printf("Red\n");
  else if (ans==2)
  printf("Green\n");
  else if (ans==3)
  printf("Blue\n");
  else if (ans==4)
  printf("Yellow\n");
  else if (ans==5)
  printf("White\n");
  else
  printf("Enter the valid input\n");
}
