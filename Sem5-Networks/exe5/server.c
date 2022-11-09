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
   int cid,n,byte,resv,snt;
   char value[32],buf[32],value1[32];
   unsigned int len;
   int i=0,k=0;
   FILE *f1;
 //  f1 = fopen("table.txt","r");
   cid = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
   if(cid == -1)
       perror("socket error");
   else
   {
       printf("creation successful\n");
       cin.sin_family = AF_INET;
       cin.sin_port=htons(30103);
       cin.sin_addr.s_addr=inet_addr("127.0.0.1");
       if(bind(cid,(struct sockaddr *) &cin ,sizeof(cin)) == -1 )
       {
            printf("bind failed\n");
       }else
       {
            printf("binding successful\n");
            int listen1=listen(cid,0);
            if(listen1 == -1){
                 printf("Listen failed\n");
            }else
            {
                 printf("Listen successful\n");
                 int n=sizeof(ccin);
                 int asid = accept(cid,(struct sockaddr *) &ccin , &n);
                 if(asid == -1)
                    printf("not accepted\n");
                 else
                 {
                    printf("Accepted\n");
                    while(1)
                    {
                           k = 0;
                           f1 = fopen("ip.txt","r");
                           resv = recv(asid,buf,30,0);
                           if(strcmp(buf,"bye")==0)
                                  break;
                           do
                           {
                             fscanf(f1,"%s %s\n",value,value1);
                             if(strcmp(buf,value)==0)
                             {
                                 snt=send(asid,value1,30,0);
                                 printf("IP available\n");
                                 k++;
                             }
                           }while(!feof(f1));
                           fclose(f1);
                           if(k==0)
                           {
                                 printf("IP not available\n");
                                 snt=send(asid,"Mac not found",30,0);
                           }
                    }
                 }
             }
          }
      }
}
