#include"head.h"
int main()
{
  string name;
  int rollNo,ch,c=1;
  float cgpa;
  BST t;
  cout<<"\n       BINARY SERACH TREE      ";
  while(c!=0)
  {
     cout<<"\n       ";
     cout<<"\n Enter 1 to add a student.\n Enter 2 to search a student.\n Enter 3 to find minimum.";
     cout<<"\n Enter 4 to find maximum.\n Enter 5 to delete student.";
     cout<<"\n Enter 6 to display student details (inOrder).\n Enter 7 to display student details (preOrder).";
     cout<<"\n Enter 8 to display student details (postOrder).\n Enter 9 to exit.";
     cout<<"\n       ";
     cout<<"\n Enter your choice : "; cin>>ch;
     switch(ch)
    {
       case 1:
       {
           cout<<" Enter the name of the Student : ";
           cin>>name;
           cout<<" Enter Roll number : "; cin>>rollNo;
           cout<<" Enter the CGPA : "; cin>>cgpa;
	   Student* s=new Student(rollNo,name,cgpa);
           TreeNode *newNode=new TreeNode(s,NULL,NULL);
           TreeNode *temp=t.getRoot(); 
           int flag; flag=t.insert(temp,newNode); 
           if(flag==1)
               cout<<"\n Insertion successfull.";
           else
               cout<<"\n Insertion not successfull.";
           break;
       }
       case 2:
       { 
          int r;
          cout<<"\n Enter the Roll number of the student to be searched : ";
          cin>>r;
          cout<<"\n";
          TreeNode *temp=t.getRoot();
          if(temp!=NULL)
          {
             TreeNode *temp1=t.search(temp,r);
             if(temp1!=NULL)
             {
                 Student *s=temp1->getStudent(temp1);
                 s->dispDetails();
             }
             else
                 cout<<"\n Student not present.";
          }
         else
             cout<<"\n Tree is Empty.."; break;
         }
        case 3:
        {
             TreeNode *temp=t.getRoot();
             if(temp!=NULL)
             {
                TreeNode *temp1=t.findMin(temp);
                Student *s=temp1->getStudent(temp1);
                s->dispDetails();
             }
             else
                 cout<<"\n Tree is empty.";
             break;
          }
         case 4:
         {
             TreeNode *temp=t.getRoot();
             if(temp!=NULL)
             {
                 TreeNode *temp1=t.findMax(temp);
                 Student *s=temp1->getStudent(temp1);
                 s->dispDetails();
             }
             else
                 cout<<"\n Tree is empty.";
             break;
          }
          case 5:
          {
             int r;
             cout<<"\n Enter the roll number of the student to be deleted :";
             cin>>r;
             TreeNode *temp=t.getRoot();
             if(t.search(temp,r)!=NULL)
            {
                Student *temp1=t.deletecgpa(r);
                cout<<"\n Deletion is successfull"; 
                cout<<"\n Deleted Element is : ";
                temp1->dispDetails();
             }
             else
                  cout<<"\n Student not present";
             break;
         }
         case 6:
         {
             TreeNode *temp=new TreeNode(); 
             temp=t.getRoot();
             if(temp!=NULL)
             {
                 t.inOrder(temp);
             }
            else
                cout<<"\n Tree is empty."; 
            break;
         }
         case 7:
         {
             TreeNode *temp=new TreeNode();
             temp=t.getRoot();
             if(temp!=NULL)
            {
                t.preOrder(temp);
             }
             else
                  cout<<"\n Tree is empty.";
            break;
         }
         case 8:
         {
              TreeNode *temp=new TreeNode();
              temp=t.getRoot();
              if(temp!=NULL)
             {
                t.postOrder(temp);
              }
             else
                 cout<<"\n Tree is empty.";
             break;
         }
         case 9:
                 exit(0);
         default:
               cout<<"\n Enter a valid option.";
      }
   }
       return 0;
}
