#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main()
{
    struct sockaddr_in cin;
    struct sockaddr_in ccin;
    char buf[40],value[40],value1[40];
    int i,j,k;
    FILE *f1;
    int cid=socket(PF_INET,SOCK_DGRAM,IPPROTO_UDP);
    if(cid == -1){
        perror("creation failed\n");
    }
    else{
        printf("Socket Created\n");
        cin.sin_family=AF_INET;
        cin.sin_port=htons(30161);
        cin.sin_addr.s_addr=INADDR_ANY;
        if(bind(cid,(struct sockaddr*)&cin,sizeof(cin)) == -1){
            close(cid);
            perror("Binding Failed\n");
        }
        else{
            printf("Binding Completed.\n");
            while(1)
            {
               k = 0;
               f1 = fopen("IP.txt","r");
               int len = sizeof(ccin);
               int n=recvfrom(cid,buf,sizeof(buf),MSG_WAITALL,(struct sockaddr*)&ccin,&len);
               if(strcmp(buf,"bye")==0)
                    break;
               do
               {
                   fscanf(f1,"%s %s\n",value,value1);
                   if(strcmp(buf,value)==0)
                   {
                        int snt = sendto(cid,value1,sizeof(value1),MSG_CONFIRM,(struct sockaddr*)&ccin,len);
                        printf("host you have entered is identified\n");
                        k++;
                   }
               }while(!feof(f1));
               fclose(f1);
               if(k==0)
               {
                     printf("host cannot be identfied\n");
                     int snt = sendto(cid,"IP Not Found",sizeof("IP Not Found"),MSG_CONFIRM,(struct sockaddr*)&ccin,len);
               }
            }

        }
        }
    int status = close(cid);
    if(status == -1){
        perror("close failed\n");
    }else{
        printf("Connection Closed\n");
    }
}
