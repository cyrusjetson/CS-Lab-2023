#include"matrix.h"
void main()
{ 
  int m1[5][5],m2[5][5],m[5][5],r1,r2,c1,c2;
  printf("Multiplication of Matrix\n");
  printf("Enter the size of row and column in first matrix:\n");
  scanf("%d%d",&r1,&c1);
  printf("Enter the size of row and column in Second matrix:\n");
  scanf("%d%d",&r2,&c2);
  if(c1==r2)
  {
    printf("Enter the Element of first matrix\n");
    readmat(m1,r1,c1);
    printf("Enter the Element of Second  matrix\n");
    readmat(m2,r2,c2);
    mulmat(m1,m2,m,r1,c1,c2);
    printf("First matrix :\n");
    displaymat(m1,r1,c1);
    printf("Second matrix :\n");
    displaymat(m2,r2,c2);
    printf("Result matrix :\n");
    displaymat(m,r1,c2);
  }
  else
     printf("Can not be a multiply\n");
}
