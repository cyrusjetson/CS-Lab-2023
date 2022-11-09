#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define size 2048
int main()
{
  int s_id=socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
  if(s_id==-1)
  {
   printf("\nsocket creation failed.. program terminated..");
   return 0;
  }
  printf("\nsocket created successfully");
  struct sockaddr_in addrport;
  addrport.sin_family=AF_INET;
  addrport.sin_port=htons(30150);
  addrport.sin_addr.s_addr=inet_addr("127.0.0.1");
  int status=bind(s_id,(struct sockaddr*)&addrport,sizeof(addrport));
  if(status==-1)
  {
   printf("\nbinding unsuccessful..program terminated");
   return 0;
  }
  printf("\nbinded successfully");
  status=listen(s_id,0);
  if(status==-1)
  {
   printf("\nlistening unsuccessful..program terminated");
   return 0;
  }
  printf("\nlistening..");
  struct sockaddr client_addr;
  int n=sizeof(client_addr);
  status=accept(s_id,&client_addr,&n);
  if(status==-1)
  {
    printf("\ncannot accept program terminated");
    return 0;
  }
  printf("connection request accepted");
  char filename[50];
  int count=recv(status,filename,sizeof(filename),0);
  if(count==-1)
  {
          printf("\nData request unsuccessful..program terminated");
          return 0;
  }
  printf("\nRequested file %s from client",filename);
  FILE *ptr;
  ptr=fopen(filename,"r");
  if(ptr==NULL)
  {
     char errorMessage[50];
     strcpy(errorMessage,"File Not Found");
     count=send(status,errorMessage,sizeof(errorMessage),0);
     if(count==-1)
     {
        printf("\nError while sending error ,program terminated");
        return 0;
     }
     printf("\nError");
     return 0;
  }
  
  printf("\nsending in progress");
  char stream[size];
  while(fgets(stream,size,ptr))
  {
         count=send(status,stream,sizeof(stream),0);
         if(count==-1)
         {
           printf("\nsend operation failed intermediately..program terminated");
           return 0;
         }
  }
  char bye[4]={'B','y','e'};
  if(send(status,bye,sizeof(bye),0)==-1)
  {
    printf("\nfile sent but failure in closing program terminated");
    return 0;
  }
  printf("\nfile sent successfully");
  close(status);
}
