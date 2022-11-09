#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
        int pid;
        int n,i,cnt,sum = 0;
        int *arr;
        printf("\n Enter no of elements: ");
        scanf("%d",&n);
        arr = (int*)malloc(n * sizeof(int));
        printf("\n Enter elements: ");
        for(i = 0;i<n;i++)
                scanf("%d",&arr[i]);
        pid = fork();
        if(pid > 0)
        {
                for(i=0;i<n;i++){
                        if(arr[i] % 2 != 0)
                                cnt = cnt + 1;
                }
                printf(" Count: %d\n",cnt);
        }
        else if(pid == 0) {
                for(i=0;i<n;i++){
                        sum = sum + arr[i];
                }
                printf(" Sum: %d\n\n",sum);
        }
}
