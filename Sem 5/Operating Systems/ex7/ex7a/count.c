#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main()
{
        int pipeEle[2];
        int returnStatus;
        int pid,i,n;
        int words[20];
        int readWord[20];
        int length,sum=0,cnt=0;
        printf("\nEnter the no. of elements :");
        scanf("%d",&n);
        returnStatus=pipe(pipeEle);
        if(returnStatus==-1)
        {
                printf("Pipe not created...");
                return 0;
        }
        else
        {
                pid=fork();
                if(pid==0){
                        printf("\nReading characters from CHILD Process");
                        read(pipeEle[0],readWord,sizeof(readWord));
                        for(i=0;i<n;i++)
                        {
                                if(readWord[i]%2 == 0) {
                                        sum = sum +readWord[i];
					cnt++;
				}
                      }
			printf("\n");
                        printf("\nSum of Even numbers =  %d\n",sum);
			printf("\nCount of Even numbers = %d\n",cnt);
                }
                else
                {
                    printf("\nEnter the numbers : ");
                    for(i=0;i<n;i++)
                        scanf("%d",&words[i]);
                    printf("\nWriting into Pipe from PARENT process\n");
                    write(pipeEle[1],words,sizeof(words));
                }
        }
}

