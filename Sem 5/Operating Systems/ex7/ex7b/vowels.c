#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>

int main()
{
        int pipeEle[2];
        int returnStatus;
        int pid,i;
        char words[100];
        char readWord[100];
        int length,c=0;
        returnStatus=pipe(pipeEle);
        if(returnStatus==-1)
        {
                printf("Pipe not created\n");
                return 0;
        }
        else
        {
                pid=fork();
                if(pid==0)
                { 
			read(pipeEle[0],readWord,sizeof(readWord));
                        length=strlen(readWord);
			printf("\nReading from pipe...\n");
                        printf("\nNumber of characters : %d",length);
		 
        		while (readWord[i] != '\0') {
             			readWord[i] = tolower(readWord[i]);
             			i++;
        		}
        			

                        for(i=0;i<length;i++)
                        {
                                if(readWord[i]=='a'|| readWord[i]=='e' || readWord[i] =='i' || readWord[i] == 'o' || readWord[i] =='u')
                                        c++;
                        }
                        printf("\nNo.of vowels =  %d\n",c);
                }
                else
               {
                  	printf("\nEnter characters: "); 
                        gets(words);
                        printf("\n\nWriting into Pipe...\n");
                        write(pipeEle[1],words,sizeof(words));
                }
        }
}


