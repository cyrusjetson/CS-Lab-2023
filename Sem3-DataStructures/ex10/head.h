#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class Student 
{  
  char name[20]; 
  int ID; 
  float cgpa;
  friend class Graph;
  public:
    Student(); 
    Student(char*,int,float); 
    Student(const Student&);
    int getID();
    void dispDetails(); 
};

class Graph
{
  public:
    Graph(int);
    void getData();
    void createGraph();
    void displayAll();
    void performDFS();
    void DFS(int);
    void showVertexData(int);
    void printAdjacent();
    void implementConnectedComponent();
  private:
    Student * vertices;
    int noOfVertices;
    bool *visited;
    int **adjMatrix;
};
