#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
int main()
{
int i;
void* shared_memory;
char buffer[100];
int shmid;
char arr[100];
shmid=shmget((key_t)173,1024,0666);
printf("Shared memory ID:%d\n",shmid);
shared_memory=shmat(shmid,NULL,0); //process attached to shared memory segment
strcpy(buffer,(char *)shared_memory);
int k=0;
int len=strlen(buffer);
for(i=len-1;i>=0;i--)
arr[k++]=buffer[i];
arr[k]='\0';
printf("Process attached at %p\n",shared_memory);
printf("The reversed data from memory is: %s\n",arr);
}

