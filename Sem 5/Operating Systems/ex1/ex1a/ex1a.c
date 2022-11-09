#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
     int pid,pid1,e;
     pid  = fork();
     if(pid==0)
     {
         printf(" Child id: %d  %d   ( from child )\n",getpid(),getppid());
         pid1 = fork();
         if(pid1 == 0)
         {
            printf(" Grandchild id: %d  %d  ( from grand child )\n",getpid(),getppid());
         }
      }
      else
      {
           printf(" Parent id: %d  %d  ( From parent )\n",getpid(),getppid());
      }
}
