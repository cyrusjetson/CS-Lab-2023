
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
struct directory
{
  int start;
  int end;
  char filename[50];
};

int continuous(int s_blocks[],int n_blocks,int file_size,int *start,int *end)
{
    int i,j,count=0;
    for(i=0;i<n_blocks;i++)
    {
       if(s_blocks[i]==1)
         count++;
       else
         count=0;
       if(count==file_size)
       {
           *start=(i-file_size+1)+1;
           *end=i+1;
           for(j=*start-1;j<*end;j++)
             s_blocks[j]=0;
           return 1;
       }
    }
    return 0;
}
int is_free(int s_blocks[],int n)
{
 int i;
 for(i=0;i<n;i++)
  if(s_blocks[i]==1)
    return 1;
 return 0;
}
void print_dir_structure(struct directory dir)
{
  printf("\n*****directory****");
  printf("\nFileName: %s",dir.filename);
  printf("\nStart: %d",dir.start);
  printf("\nEnd: %d",dir.end);
  printf("\n");
}
int main()
{
  printf("\nEnter the total number of blocks in secondary storage: ");
  int n,i;
  scanf("%d",&n);
  int s_blocks[n];
  for(i=0;i<n;i++)
   s_blocks[i]=0;
  printf("\nEnter the number of free blocks: ");
  int m;
  scanf("%d",&m);
  int j;
  for(i=0;i<m;i++)
  {
      printf("\nFree Block %d: ",i+1);
      scanf("%d",&j);
      s_blocks[j-1]=1;
  }
  struct directory dir;
  int choice=1;
  while(1)
  {
   char filename[50];
   printf("\nEnter the file name: ");
   scanf("%s",filename);
   printf("\nEnte the size of file in blocks: ");
   int f_size;
   scanf("%d",&f_size);
   int start,end;
   if(continuous(s_blocks,n,f_size,&start,&end))
   {
     strcpy(dir.filename,filename);
     dir.start=start;
     dir.end=end;
     printf("\nThe blocks allocated is from %d to %d\n",start,end);
     print_dir_structure(dir);
   }
   else
     printf("\nNo free space continuously to allocate file of size %d blocks\n",f_size);
   if(!is_free(s_blocks,n))
   {
    printf("\nNo more free space!\n");
    //printf("\nIt is meaningless to continue let me close the program!\n");
    exit(0);
   }
   printf("\nEnter 1 to continue... ");
   scanf("%d",&choice);
   if(choice!=1)
    break;
  }
}

