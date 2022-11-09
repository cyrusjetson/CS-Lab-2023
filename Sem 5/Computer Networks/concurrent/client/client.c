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
 char data[20],date[80];
 int sid,i,j,cid,bid,len;
 struct sockaddr_in cin;
 sid=socket(AF_INET,SOCK_STREAM,0);
 if(sid==-1)
 {
  perror("\n Error in socket connection..\n");
  exit(0);
 }
 printf("\n Socket Created successfully..");
 cin.sin_family=AF_INET;
 cin.sin_port=htons(3155);
 cin.sin_addr.s_addr=htonl(INADDR_ANY);
 cid=connect(sid,(struct sockaddr *)&cin,sizeof(cin));
 if(cid==-1)
 {
  perror("\n Error in connection..\n");
  exit(0);
 }
 printf("\n Connection established..\n");
 while(1){
 char msg[100],buf[100];
 printf("\n Type msg to server\n");
 scanf("%s",buf);
 i=send(sid,buf,sizeof(buf),0);
 if(strcmp(buf,"bye")==0)
	break;
 if(i==-1)
   {printf("cant send msg\n");  
   break;}
 if(j==-1){
 printf("cant receive msg\n");
 break;}
 j=recv(sid,msg,sizeof(msg),0);
 printf("\n msg from server :%s" ,msg);
}close(sid);
 printf("program terminated\n");
}

