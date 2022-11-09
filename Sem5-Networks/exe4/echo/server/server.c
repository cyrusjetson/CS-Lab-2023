#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>

int main()
{
   struct sockaddr_in cin;
   struct sockaddr_in ccin;
   int cid,n,byte;
   char echobuf[32],buf[32];
   int m,i=0;
   cid = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
   if(cid == -1)
       perror("Socket Not Created");
   else
   {
       printf("Socket Successful\n");
       cin.sin_family = AF_INET;
       cin.sin_port=htons(30150);
       cin.sin_addr.s_addr=inet_addr("127.0.0.1");
       if(bind(cid,(struct sockaddr *) &cin ,sizeof(cin)) == -1 )
       {
            printf("Binding Failure\n");
       }else
       {
            printf("Binding successful\n");
            int listen1=listen(cid,0); 
            if(listen1 == -1){
                 printf("Listening Failure....\n");
            }else
            {
                 printf("Listening\n");
                 int n=sizeof(ccin);
                  int asid = accept(cid,(struct sockaddr *) &ccin , &n);
                 if(asid == -1)
                    printf("Accept failed\n");
                 else
                 {
                    printf("Accepted    ");
                   while(1){
                        int resv = recv(asid,buf,30,0);
                        if(resv == -1)
                            printf("connection closed\n");
                        printf("%s\n",buf);
                        int snt=send(asid,buf,30,0);
                    }
                }
             }
        }
   }
}
