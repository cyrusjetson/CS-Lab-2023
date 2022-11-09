#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

char*revc(char[10]);

struct mesg_buffer
{
    long mesg_type;
    char mesg_text[100];
}message;

int main()
{
    int msgid,i,m,j,fid;
    char temp;
    char arr[100],buffer[100];
    fid = fork();
    if(fid==0)
    {
         msgid = msgget(3163,0666|IPC_CREAT);
         message.mesg_type = 1;
         msgrcv(msgid, &message, sizeof(message), 1, 0);
         j = strlen(message.mesg_text);
         strcpy(buffer,message.mesg_text);
         int k=0;
         int len=strlen(buffer);
         for(i=len-1;i>=0;i--)
             arr[k++]=buffer[i];
         arr[k]='\0';
         printf("Recived Message : %s\n",arr);
    }
    else
    {
       msgid = msgget(3163,0666|IPC_CREAT);
       printf("Enter   Message : ");
       scanf("%s",&message.mesg_text);
       message.mesg_type = 1;
       msgsnd(msgid, &message, sizeof(message), 0);
    }
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}
