#include"avl.h"
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main()
{
 char name[20];
 int ID;
 float f;
 AVL t;
 int ch,t1=1;
 while(t1!=0)
 {
  cout<<"\n1. Insert an Student detail.";
  cout<<"\n2. Search an Student";
  cout<<"\n3. Display the Student details.(Inorder)";
  cout<<"\n4. Display the Student details.(Preorder)";
  cout<<"\n5. Display the Student details.(Postorder)";
  cout<<"\n6. Exit.";
  cout<<"\nEnter your choice : ";
  cin>>ch;
  switch(ch)
  {
     case 1:
        {
          cout<<"\nEnter the name of the Student: ";
          cin>>name;
          cout<<"Enter ID : ";
          cin>>ID ;
          cout<<"Enter CGPA : ";
          cin>>f;
          AvlNode *newNode=new
          AvlNode(name,ID,f);
          AvlNode *temp=t.getRoot();
          AvlNode *temp1=t.insert(temp,newNode);
          t.updateRoot(temp1);
          break;
        }
        case 2:
        {
          int id;
          cout<<"\n Enter the id of Student the to  searched : ";
          cin>>id;
          AvlNode *temp=t.getRoot();
          if(temp!=NULL)
          {
            AvlNode *temp1=t.search(temp,id);
            if(temp1!=NULL)
            {
              Student *b=temp1->getStudent(temp1);
              cout<<"\n ID   Name\t\tCGPA \n";
              b->dispDetails();
            }
            else
                cout<<"\n Student details not present.";
          }
          else
            cout<<"\n Tree is Empty.";
          break;
         }
         case 3:
         {
           AvlNode *temp=new AvlNode();
           temp=t.getRoot();
           if(temp!=NULL)
           {
             cout<<"\n ID   Name\t\tCGPA\n";
             t.inOrder(temp);
           }
           else
             cout<<"\n Tree is empty.";
           break;
         }
         case 4:
         {
           AvlNode *temp=new AvlNode();
           temp=t.getRoot();
           if(temp!=NULL)
           {
             cout<<"\n ID  Name\t\tCGPA\n";
             t.preOrder(temp);
           }
           else
             cout<<"\n Tree is empty.";
           break;
         }
         case 5:
         {
           AvlNode *temp=new AvlNode();
           temp=t.getRoot();
           if(temp!=NULL)
           {
             cout<<"\n ID   Name\t\tCGPA\n";
             t.postOrder(temp);
           }
           else
             cout<<"\n Tree is empty.";
           break;
         }
         case 6:
                exit(0);
  }
 }
 return 0;
}
