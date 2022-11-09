#include"head.h"
Student::Student() 
{ 
  strcpy(name,"null"); 
  ID=0; 
  cgpa=0;
} 

Student::Student(char*d,int n,float f) 
{ 
  strcpy(name,d); 
  ID=n; 
  cgpa=f;
}

Student::Student(const Student &f) 
{ 
  strcpy(name,f.name); 
  ID=f.ID;
  cgpa=f.cgpa; 
}

int Student::getID()
{
  return ID;
}

void Student::dispDetails()
{
	  cout<<ID<<" \t "<<name<<" \t "<<cgpa;
}

Graph::Graph(int n)
{
  noOfVertices = n;
  vertices = new Student[noOfVertices];
  adjMatrix = new int*[noOfVertices];
  for( int i=0; i<noOfVertices; i++ )
    adjMatrix[i] = new int[noOfVertices];
  for( int i=0;i<noOfVertices ; i++)
    for( int j=0; j<noOfVertices ; j++)
      adjMatrix[i][j] = 0;
}

void Graph::getData()
{
  char name[20];
  int ID;
  float f;
  cout<<"\n Enter Student details : \n\n";
  for(int i=0;i<noOfVertices;i++)
  {
    cout<<"Vertices " << i <<"\n";
    cout<<"\n Enter the name of the Student : ";
    cin>>name;
    cout<<" Enter ID : ";
    cin>>ID ;
    cout<<" Enter CGPA: ";
    cin>>f;
    Student s(name,ID,f);
    vertices[i]= s;
  }
}

void Graph::createGraph()
{
  int edge,v,w;
  cout<<"\n Enter no of edges in the graph : ";
  cin>>edge;
  for(int i=0;i<edge;i++)
  {
     cout<<"\n Enter the adjacent vertices\n";
     cout<<"\n Enter v : ";
     cin>>v;
     cout<<"\n Enter w : ";
     cin>>w;
     adjMatrix[v][w] =1;
     adjMatrix[w][v] =1;
  }
}

void Graph :: displayAll()
{
  cout<<"\n ID \t Name \t CGPA \n";
  for(int i=0;i<noOfVertices;i++)
  {
    cout<<vertices[i].ID<<" \t "<<vertices[i].name<<" \t "<<vertices[i].cgpa<<" \t"<<"\n";
  }
}

void Graph :: showVertexData(int i)
{
  cout<<"\n Vertice : "<<i<<"\n";
  cout<<"\n ID \t Name \t CGPA\n";
  cout<<vertices[i].ID<<" \t "<<vertices[i].name<<" \t"<<vertices[i].cgpa<<"\n";
}

void Graph::performDFS()
{
  visited = new bool[noOfVertices];
  for( int i=0; i<noOfVertices; i++)
    visited[i] = false;
  for( int i=0; i<noOfVertices; i++)
  {
    if(!visited[i])
    DFS(i);
  }
}

void Graph::DFS(int i)
{
  showVertexData(i);
  visited[i] = true;
  for( int j=0; j<noOfVertices; j++)
  {
    if( adjMatrix[i][j] == 1){
      if(!visited[j])
      DFS(j);
    }
  }
}

void Graph::printAdjacent()
{
  for(int i=0;i<noOfVertices;i++)
    cout<<"\t"<<i;
  cout<<"\n";
  for(int i=0; i<noOfVertices ; i++)
    cout<<"________";
  cout<<"\n";
  for( int i=0;i<noOfVertices ; i++)
  {
    cout<<i<<" |\t";
    for( int j=0; j<noOfVertices ; j++)
      cout<<adjMatrix[i][j]<<"\t";
    cout<<"\n";
  }
}

void Graph::implementConnectedComponent()
{
  visited = new bool[noOfVertices];
  for( int i=0; i<noOfVertices; i++)
    visited[i] = false;
  int count = 0;
  for( int i=0; i<noOfVertices; i++)
  {
    if(!visited[i])
    {
      cout<<"Connected Component "<<++count<<endl;
      DFS(i);
    }
  }
}
