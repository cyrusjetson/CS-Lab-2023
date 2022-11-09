#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
int main()
{
 char data[20];
 int sid,cid,bid,len,pid;
 struct sockaddr_in sin,cin;
 sid=socket(AF_INET,SOCK_STREAM,0);
 if(sid==-1)
 {
  perror("\n Error in socket connection..\n");
  exit(0);
 }
 printf("\n Socket Created successfully..");
 sin.sin_family=AF_INET;
 sin.sin_port=htons(3155);
 sin.sin_addr.s_addr=htonl(INADDR_ANY);
 bid=bind(sid,(struct sockaddr *)&sin,sizeof(sin));
 if(bid==-1)
 {
  perror("\n Error in binding..\n");
  exit(0);
 }
 printf("\n Binded successfully..\n");
 if(listen(sid,5)<0)
 {
  perror("\n Error in listening..\n");
  exit(0);
 }
     printf("\n Listening....\n");
     printf("waiting for client connection..\n");
     while(1){
     len=sizeof(cin);
     cid=accept(sid,(struct sockaddr*)&cin,&len);
     if(cid==-1)
	 {
	  perror("\n Error in accepting...\n");
	  exit(0);
	 }
	 printf("\n Accepting..client \n");
	 int abc,bcd;
	 char msg[100],buf[100];
	 pid=fork();
	 if(pid==0){
		while(1){
			 abc=recv(cid,msg,sizeof(msg),0);
			 if(abc>0){
				printf("\nMSG from Client :%s ",msg);
				}
			 else if(abc==-1)
                                {printf("cant receive msg from client\n");
				break;}
			 if(strcmp(msg,"bye")==0){printf("\nBye\n");
				break;}
			 printf("\nType a msg to client\n");
			 scanf("%s",buf);
			 bcd=send(cid,buf,sizeof(buf),0);
			 if(bcd==-1){printf("cant send msg!\n");}
}}
}
close(cid);
close(sid);
printf("program terminated\n");}


