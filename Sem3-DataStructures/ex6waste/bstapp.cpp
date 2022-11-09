#include"bst.h"
int main()
{
  int ch;
  Student p,data; BST bst;
  while(1)
  {
    cout<<"	";
    cout<<"\n     Menu\n";
    cout<<"	";
    cout<<"\n1.Insert an Student";
    cout<<"\n2.Search for a Student Details";
    cout<<"\n3.Inorder";
    cout<<"\n4.Preorder";
    cout<<"\n5.Postorder";
    cout<<"\n6.Delete a Student\n";
    cout<<"7.exit\n";
    cout<<"\n Enter choice:";
    cin>>ch;
    switch(ch)
    {
      case 1:
      {
        cout<<"\nEnter data:"; 
        cin>>p;
        TreeNode* newNode = new TreeNode(p,NULL,NULL);
        if(bst.insertElt(newNode) == NULL)
          cout<<"\n Student can't be inserted\n";
        else
          cout<<"\n Student inserted\n";
        break;
      }
      case 2:
      {
        char nm[20];
        int r;
        float f;
        cout<<"\nEnter the Name of Student: ";
        cin>>nm;
        cout<<"Enter the ID of the Student: ";
        cin>>r;
        cout<<"Enter CGPA: ";
        cin>>f;
        Student p1(nm,r,f);
        Student p;
        if(!bst.isEmpty())
        {
          if(bst.search(p1) == p)
             cout<<"\nNo Student available\n";
          else
          {
              cout<<"\n Student Found!!\n";
              Student p2=bst.search(p1);
              cout<<p2;
              cout<<"\n";
          }
        }
       else
          cout<<"\n Empty tree\n";
          break;
      }
      case 3:
      {
         cout<<"\nDisplaying by inorder traversal\n";
         bst.inorder(bst.getRoot());
         cout<<"\n"; break;
      }
      case 4:
      {
         cout<<"\nDisplaying by preorder traversal\n";
         bst.preorder(bst.getRoot());
         cout<<"\n"; break;
      }
      case 5:
      {
         cout<<"\nDisplaying by post traversal\n";
         bst.postorder(bst.getRoot());
         cout<<"\n"; break;
      }
      case 6:
      {
         cout<<"\nEnter Student data:\n";
         cin>>data;
         bst.deleteElt(data);
         cout<<"\nStudent removed\n";
         cout<<"\nExisting BST elements:\n";
         bst.inorder(bst.getRoot());
         cout<<"\n";
         break;
      }
      case 7: return 0;
          break;
    }
  }
}

