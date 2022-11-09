#include<stdio.h>
 int main()

{
    int n,bt[20],wt[20],tat[20],i,j;
    float avwt=0.0,avtat=0.0;
    printf("\n   ~~~~~ FCFS ~~~~~\n\nEnter total number of processes: ");
    scanf("%d",&n);

    printf("\nEnter Process Burst Time of processes\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]: ",i+1);
        scanf("%d",&bt[i]);
    }

    wt[0]=0;

    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }


    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }
    printf("\n");

    avwt/=n;
    avtat/=n;
    printf("\nAverage Waiting Time:%f",avwt);
    printf("\nAverage Turnaround Time:%f\n",avtat);
    printf("\n");
 for(i=0;i<n;i++)
        {
                printf("__________");
        }
   printf("\n");


    for(i=0;i<n;i++)
        {
                if(i==0)
                printf(" |  P%d  |",i+1);
                else
                printf("    P%d  |",i+1);
        }
        printf("\n");
for(i=0;i<n;i++)
        {
                printf("__________");
        }
   printf("\n");


        for(i=0;i<n;i++)
        {
                if(i==0)
                printf(" 0      %d ",tat[i]);
                else
                printf("       %d ",tat[i]);
        }
   printf("\n");
	
    return 0;
}

