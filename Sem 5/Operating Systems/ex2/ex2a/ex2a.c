#include<stdio.h>
 
int main()
{
    int bt[20],p[20],wt[20],tat[20],pri[20],i,j,n,pos,temp;
    float avgwt=0.0,avgtat=0.0;
    printf("\n ~~~~~ priority ~~~~~\n\nEnter Total Number of Processes: ");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&bt[i]);
        printf("Priority:");
        scanf("%d",&pri[i]);
        p[i]=i+1;
    }

    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pri[j]<pri[pos])
                pos=j;
        }
 
        temp=pri[i];
        pri[i]=pri[pos];
        pri[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;    
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
        avgwt+=wt[i];
    }
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i]; 
        avgtat+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }

    avgwt=avgwt/n;
    avgtat=avgtat/n;   
    printf("\n\nAverage Waiting Time=%f",avgwt);
    printf("\nAverage Turnaround Time=%f\n",avgtat);
    printf("\n");

    for(i=0;i<n;i++)
    {
                printf("__________");
    }
     printf("\n");

       for(i=0;i<n;i++)
        {
                if(i==0)
                printf(" |  P%d  |",p[i]);
                else
                printf("    P%d  |",p[i]);
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


