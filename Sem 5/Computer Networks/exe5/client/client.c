#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

int main()
{
   struct sockaddr_in ccin;
   int i=0;
   int len;
   char buf[30];
   char sent[30];
   int ccid = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
   if(ccid == -1)
       printf("creation failed \n");
   else
   {
      ccin.sin_family=AF_INET;
      ccin.sin_port=htons(30103);
      ccin.sin_addr.s_addr=inet_addr("127.0.0.1");
      printf("creation successful\n");
      int cnct=connect(ccid,(struct sockaddr * ) &ccin, sizeof(ccin));
      if(cnct == -1)
         printf("Connection failed\n");
      else
      {
         printf("Connection successful\n");
         do{
                printf("IP address : ");
                scanf("%s",&sent);
                if(strcmp(sent,"bye")==0)
                    break;
                int snt = send(ccid,sent,30,0);
                if(snt == -1)
                        printf("Transmitted failed\n");
                int resv=recv(ccid,buf,30,0);
                if(resv == -1)
                        printf("msg not received\n");
                else
                        printf("Mac adress : %s\n",buf);
                for(i=0;i<30;i++)
                   buf[i]=' ';
           }while(1);
       }
   }
   int status = close(ccid);
   if(status == 0)
      printf("closed\n");
}
