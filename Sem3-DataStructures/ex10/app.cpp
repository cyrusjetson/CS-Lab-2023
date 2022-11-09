#include"head.h"
int main()
{
  int n,ch;
  cout<<"\n Enter no of vertices : ";
  cin>>n;
  Graph g(n);
  g.getData();
  g.createGraph();
  while(true)
  {
    cout<<"\n 1.Perform DFS traversal";
    cout<<"\n 2.Print adjacent matrix";
    cout<<"\n 3.Find connected component";
    cout<<"\n 4.Display all Student details";
    cout<<"\n 5.Exit";
    cout<<"\n Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
      case 1:
      {
        cout<<"\n DFS traversal : \n";
        g.performDFS();
        break;
      }
      case 2:
      {
          cout<<"\n Adjacent matrix : \n";
          g.printAdjacent();
          break;
      }
      case 3:
      {
         g.implementConnectedComponent();
         break;
      }
      case 4:
      {
         g.displayAll();
         break;
      }
      case 5:
          exit(0);
      default:
         cout<<"\n Invalid choice\n";
    }
  }
}
