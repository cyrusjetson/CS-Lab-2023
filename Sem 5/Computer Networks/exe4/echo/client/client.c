#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
int main()
{
   struct sockaddr_in ccin;
   int i=0;
   char buf[30];
   int ccid = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
   if(ccid == -1)
       printf("Socket Failure \n");
   else
   {
      ccin.sin_family=AF_INET;
      ccin.sin_port=htons(30150);
      ccin.sin_addr.s_addr=inet_addr("127.0.0.1");
      printf("socket created\n");
      int cnct=connect(ccid,(struct sockaddr * ) &ccin, sizeof(ccin));
      if(cnct == -1)
         printf("Connection failed\n");
      else
      {
         printf("Connection successful\n");
         char sent_msg[30];
         while(1)
         {
             printf("Message : ");
             scanf("%s",&sent_msg);
             if(strcmp(sent_msg,"Bye")==0)
                  break;
             int snt = send(ccid,sent_msg,sizeof(sent_msg),0);
            if(snt == -1)
                printf("Message not transmitted\n");
             int resv=recv(ccid,buf,30,0);
             if(resv == -1)
                 printf("Message not recieved\n");
             else
                 printf("Echo : %s \n",buf);            
         }
       }
       int status = close(ccid);
       if(status == 0)
          printf("closed\n");
   }
}

