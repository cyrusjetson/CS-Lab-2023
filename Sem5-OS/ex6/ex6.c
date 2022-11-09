#include<stdio.h>
#include<stdlib.h>

int* fifo(int frames,int n,int page[])
{
        int arr[frames],i,j;
        for(i=0;i<frames;i++)
                arr[i]=-99;
        int k=0,hit=0,miss=0;
        static int ret[2];
        for(i=0;i<n;i++)
        {
                int flag=1;
                for(j=0;j<frames;j++)
                {
                        if(arr[j]==page[i])
                        {
                                flag=0;
                                k--;
                                hit++;
                                break;
                        }
                }
                if(flag==1)
                {
                        arr[k%frames]=page[i];
                        miss++;
                }
                k++;
                for(j=0;j<frames;j++)
                {
                        if(arr[j]!= -99){
                                printf("%d\t",arr[j]);
				
			}
                }
                printf("\n");
        }
        ret[0]=hit;
        ret[1]=miss;
        return ret;
}

int* lru(int frames,int n,int page[])
{
        int arr[frames],i,j;
        for(i=0;i<frames;i++)
                arr[i]=-99;
        int k=0,hit=0,miss=0;
        int lru[frames];
        for(i=0;i<frames;i++)
        {
                lru[i]=frames-1;
        }
        static int ret[2];
        for(i=0;i<n;i++)
        {
                int flag=1;
                for(j=0;j<frames;j++)
                {
                        if(arr[j]==page[i])
                        {
                                flag=0;
                                hit++;
                                lru[j]=frames;
                                break;
                        }
                }
                if(flag==1)
                {
                        int min=frames+1,minimum;
                        for(j=0;j<frames;j++)
                        {
                                if(lru[j]<min)
                                {
                                        min=lru[j];
                                        minimum=j;
                                }
                        }
                        arr[minimum]=page[i];
                        lru[minimum]=frames;
                        miss++;
                }
                for(j=0;j<frames;j++)
                {
                        lru[j]--;
                        if(arr[j]!= -99)
                                printf("%d\t",arr[j]);
                }
                printf("\n");
        }
        ret[0]=hit;
        ret[1]=miss;
        return ret;
}

int* optimal(int frames,int n,int page[])
{
        int arr[frames],i,j;
        for(i=0;i<frames;i++)
                arr[i]=-99;
        int k=0,hit=0,miss=0;
        static int ret[2];
        for(i=0;i<n;i++)
        {
                int op[frames];
                int flag=1,flg=0;
                for(j=0;j<frames;j++)
                {
                        if(arr[j]==page[i])
                        {
                                flag=0;
                                hit++;
                                break;
                        }
                }
                if(flag==1)
                {
                        for(j=0;j<frames;j++)
                        {
                                for(k=i+1;k<n;k++)
                                {
                                        if(page[k]==arr[j])
                                        {
                                                op[j]=k;
                                                break;
                                        }
                                        else
                                                op[j]=99;
                                }
                                if(op[j]==99)
                                {
                                        arr[j]=page[i];
                                        miss++;
                                        flg=1;
                                        break;
                                }
                        }
                        if(flg!=1)
                        {
                                int max=-99,maximum;
                                for(j=0;j<frames;j++)
                                {
                                        if(op[j]>max)
                                        {
                                                max=op[j];
                                                maximum=j;
                                        }
                                }
                                arr[maximum]=page[i];
                                miss++;
                        }
                }
                for(j=0;j<frames;j++)
                {
                        if(arr[j]!= -99)
                                printf("%d\t",arr[j]);
                }
                printf("\n");
        }
        ret[0]=hit;
        ret[1]=miss;
        return ret;
}

int main()
{
        int i,j,frames,n,choice=0;
        int page[50];
        printf("\nEnter the number of frames:");
        scanf("%d",&frames);
        printf("\nEnter the number of pages:");
        scanf("%d",&n);
        printf("\nEnter the page reference string:\n");
        for(i=0;i<n;i++)
                scanf("%d",&page[i]);
        while(choice<=4)
        {
                printf("\n1.FIFO\n2.LRU\n3.Optimal\n4.Find the Best algorithm\n5.Exit\nEnter your choice:");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                {
                                        int *ret=fifo(frames,n,page);
                                        printf("\n\nPage Hit:%d\nPage fault:%d\n\n",ret[0],ret[1]);
                                        break;
                                }
                        case 2:
                                {
                                        int *ret=lru(frames,n,page);
                                        printf("\n\nPage Hit:%d\nPage fault:%d\n\n",ret[0],ret[1]);
                                        break;
                                }
                        case 3:
                                {
                                        int *ret=optimal(frames,n,page);
                                        printf("\n\nPage Hit:%d\nPage fault:%d\n\n",ret[0],ret[1]);
                                        break;
                                }
                        case 4:
                                {
                                        int *ret1=fifo(frames,n,page);
                                        int *ret2=lru(frames,n,page);
                                        int *ret3=optimal(frames,n,page);
                                        int minarr[3];
                                        minarr[0]=ret1[1];
                                        minarr[1]=ret2[1];
                                        minarr[2]=ret3[1];
                                        int best,min=99;
                                        for(i=0;i<3;i++)
                                        {
                                                if(minarr[i]<min)
                                                {
                                                        min=minarr[i];
                                                        best=i;
                                                }
                                        }
                                        if(best==0)
                                        {
                                                printf("\n\nFIFO is the best page replacement algorithm :)\n");
                                        }
                                        else if(best==1)
                                        {
                                                printf("\n\nLRU is the best page replacement algorithm :)\n");
                                        }
                                        else if(best==2)
                                        {
                                                printf("\n\nOptimal algorithm is the best page replacement algorithm\n");
                                        }
                                        break;
                                }
                }
        }
        return 0;
}


