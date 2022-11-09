#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main()
{
  int s_id=socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
  if(s_id==-1)
  {
   printf("\nsocket creation failed program terminated");
   return 0;
  }
  printf("\nsocket created successfully");
  struct sockaddr_in foreign_addr;
  foreign_addr.sin_family=AF_INET;
  foreign_addr.sin_port=htons(30150);
  foreign_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
  int n=sizeof(foreign_addr);
  int status=connect(s_id,(struct sockaddr *)&foreign_addr,n);
  if(status==-1)
  {
    printf("\nconnection unsuccessful program terminated!..");
    return 0;
  }
  char filename[50];
  printf("\nEnter the file name: ");
  scanf("%s",filename);
  int count=send(s_id,filename,sizeof(filename),0);
  if(count==-1)
  {
   printf("\nrequest unsuccessful program terminated!");
   return 0;
  }
  printf("\nRequest for %s is successful",filename);
  printf("\nEnter the name to the file received : ");
  scanf("%s",filename);
  FILE *ptr=fopen(filename,"w");
  char buffer[2048];
  count=recv(s_id,buffer,sizeof(buffer),0);
  if(count==-1)
  {
          printf("\nfile recemption failed program terminated");
          return 0;
  }
  else if(!strcmp(buffer,"File Not Found"))
  {
          printf("\nServer throws error message as:\n%s\nfor your file request\n",buffer);
          return 0;
  }
  while(strcmp(buffer,"Bye")!=0)
  {
          fputs(buffer,ptr);
          count=recv(s_id,buffer,sizeof(buffer),0);
          if(count==-1)
          {
                  printf("\nfile recemption failed intermediately program terminated\n");
                  return 0;
          }
  }
  printf("\nfile received successfully\n");
}

