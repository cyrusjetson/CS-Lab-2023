#include"head.h"
Student::Student()
{
  name = "Null";
  rollNo = 0;
  cgpa = 0;
}

Student::Student(int r,string name,float cgpa)
{
  this->name = name;
  this->rollNo = r;
  this->cgpa = cgpa;
}

Student::Student(const Student &stud)
{
   name = stud.name;
   rollNo=stud.rollNo;
   cgpa = stud.cgpa;
}

Student::~Student()
{
  name="";
  rollNo=0;
  cgpa=0;
}

void Student::dispDetails()
{
  cout<<" Name: "<<name<<endl;
  cout<<" Rollno: "<<rollNo<<endl;
  cout<<"CGPA: "<<cgpa<<endl;
}
void Student::operator=(Student s)
{
	name=s.name;
	rollNo=s.rollNo;
	cgpa=s.cgpa;
}

TreeNode::TreeNode()
{
  left=NULL; right=NULL;
}

TreeNode::TreeNode(Student* S,TreeNode *l,TreeNode *r)
{
  s=S;
  left=l;
  right=r;
}

Student * TreeNode::getStudent(TreeNode *temp)
{
  return temp->s;
}

BST::BST()
{
  root=NULL;
}

bool BST::isEmpty()
{
  if(root==NULL)
     return true;
  else
     return false;
}

TreeNode * BST::getRoot()
{
  return root;
}

bool BST::insert(TreeNode *temp,TreeNode *newNode)
{
  if(root==NULL)
  {
     root=newNode; return true;
  }
  else
  {
     if(temp->s->rollNo < newNode->s->rollNo)
     {
        if(temp->right==NULL)
       {
           temp->right=newNode; return true;
        }
        else
           insert(temp->right,newNode);
      }
      else if(temp->s->rollNo > newNode->s->rollNo)
     {
     if(temp->left==NULL)
    {
        temp->left=newNode; return true;
     }
     else
        insert(temp->left,newNode);
   }
   else
      return false;
  }
}

TreeNode * BST::search(TreeNode *temp,int r)
{
  if(temp == NULL || temp->s->rollNo==r) 
     return temp;
  else if(temp->s->rollNo <r)
      search(temp->right,r);
  else if(temp->s->rollNo >r)
      search(temp->left,r);
}

TreeNode * BST::findMin(TreeNode *temp)
{
   if(temp->left!=NULL)
      findMin(temp->left);
   else
      return temp;
}

TreeNode * BST::findMax(TreeNode *temp)
{
   if(temp->right!=NULL)
       findMax(temp->right);
   else
       return temp;
}

Student * BST::deletecgpa(int r)
{
  TreeNode *parent = NULL; TreeNode *temp=root; while(temp!=NULL)
  {
     if(temp->s->rollNo==r)
    {
       Student *delElt=temp->s;
       if(temp->left==NULL && temp->right==NULL)
      {
          if(temp==root)
          {
             delete temp; temp=NULL;
              root=NULL;
              return delElt;
          }
          else
         {
         if(parent->left == temp)
             parent->left=NULL;
         else
             parent->right=NULL;
          delete temp;
          temp=NULL;
          return delElt;
       }
   }
   else if(temp->left!=NULL && temp->right!=NULL)
  {
      TreeNode *temp1=temp->right;
      if(temp1->left==NULL)
      {
         temp->s=temp1->s;
         temp->right=temp1->right;
         delete temp1; 
         temp1=NULL;
      }
      else
     {
         while(temp1->left!=NULL)
         {
             parent=temp1;
             temp1=temp1->left;
         }
         temp->s=temp1->s;
         if(temp1->right!=NULL) 
            parent->left=temp1->right;
         else
             parent->left=NULL;
        delete temp1;
        temp1=NULL;
     }
     return delElt;
  }
  else
  {
   if(temp==root)
  {
     if(temp->left!=NULL && temp->right==NULL)
         root=temp->left;
     else
         root=temp->right;
      delete temp;
      temp=NULL; 
      return delElt;
  }
  else
  {
     if(parent->right==temp)
    {
        if(temp->right!=NULL && temp->left==NULL)
           parent->right=temp->right;
        else 
            parent->right=temp->left;
    }
    else
   {
       if(temp->left!=NULL && temp->right==NULL)
           parent->left=temp->left;
       else
           parent->left=temp->right;
   }
   delete temp; temp=NULL;
   return delElt;
 }
 }
}
else if(temp->s->rollNo > r)
{
  parent=temp;
  temp=temp->left;
}
else if(temp->s->rollNo < r)
{
  parent=temp;
  temp=temp->right;
}
}
}

void BST::preOrder(TreeNode *temp)
{
  if(temp!=NULL)
  {
     temp->s->dispDetails();
     preOrder(temp->left);
     preOrder(temp->right);
  }
}
 
void BST::inOrder(TreeNode *temp)
{
   if(temp!=NULL)
   {
       inOrder(temp->left);
       temp->s->dispDetails();
       inOrder(temp->right);
   }
}

void BST::postOrder(TreeNode *temp)
{
  if(temp!=NULL)
  {
     postOrder(temp->left); postOrder(temp->right);
     temp->s->dispDetails();
   }
}
