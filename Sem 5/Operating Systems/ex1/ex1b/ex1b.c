#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
   int pid,pid1;
   pid = fork();
   if( pid == 0 )
   {
       printf(" Child1 id: %d  %d \n",getpid(),getppid());
   }
   else
   {
       printf(" Parent id: %d  %d \n",getpid(),getppid());
       pid1 = fork();
       if(pid1 == 0)
       {
           printf(" Child2 id: %d  %d\n",getpid(),getppid());
       }
   }
}
