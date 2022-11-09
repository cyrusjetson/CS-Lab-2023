#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define initial 1
#define visited 2
#define finished 3

int n,m;    
int rag[MAX][MAX];
void create_graph( );

int state[MAX];

void DF_Traversal();
void DFS(int v);

int main()
{
	create_graph();
	DF_Traversal();
	return 0;
}

void DF_Traversal()
{
	int v;
	for(v=0; v<n; v++)
		state[v] = initial;
	DFS(0);
	for(v=0; v<n; v++)
	{
		if(state[v]==initial)
			DFS(v);
	}
	printf("\nNo DEADLOCK detected\n");
}

void DFS(int v)
{
	int i;
	state[v] = visited;
	for(i=0; i<n; i++)
	{
		if(rag[v][i]==1)
		{
			if(state[i]==initial)
				DFS(i);
			else if(state[i]==visited)
			{
				printf("\nDEADLOCK is due to the edge %d--->%d\n",v,i);
				printf("\nDEADLOCK detected\n");
				exit(1);
			}
		}
	}
	state[v] = finished;
}

void create_graph()
{
	int i,max_edges,origin,destin;
	printf("Enter number of vertices : ");
	scanf("%d",&n);
a1:
	printf("Enter number of edges  : ");
	scanf("%d",&m);
	printf("\n");
	if(m>n*(n-1))
		goto a1;
	for(i=1;i<=m;i++)
	{
		printf("Enter edge %d's source and destination  : ",i);
		scanf("%d %d",&origin,&destin);
		if( origin >= n || destin >= n || origin<0 || destin<0)
		{
			printf("\nInvalid edge!\n");
			i--;
		}
		else
		{
			rag[origin][destin] = 1;
                }
        }
}


