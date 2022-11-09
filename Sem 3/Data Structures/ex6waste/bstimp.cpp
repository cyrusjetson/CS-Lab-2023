#include"bst.h"
#include<iostream>
#include<string.h>
using namespace std;
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
  cgpa= f.cgpa;
}

Student Student::operator=(Student D)
{
strcpy(name,D.name) ;
cgpa=D.cgpa;
ID=D.ID;
return *this;
}
Student Student::operator=(int x)
{
strcpy(name,"null");
ID=x;
cgpa=0;
}

bool Student::operator==(Student emp)
{
  if(strcmp(name,emp.name)&&(ID==emp.ID)&&(cgpa==emp.cgpa))
     return 1;
  else
     return 0;
}

ostream& operator<<(ostream &myout,Student &emp)
{
  cout<<"\nName: ";
  myout<<emp.name;
  cout<<"\nID: ";
  myout<<emp.ID;
  cout<"CGPA: ";
  myout<<emp.cgpa;
}

istream& operator>>(istream &myin,Student &emp)
{
  cout<<"\nEnter the Name of Student: ";
  myin>>emp.name;
  cout<<"Enter the Student ID: ";
  myin>>emp.ID;
  cout<<"Enter student's CGPA: ";
  myin>>emp.cgpa;
}

bool operator<(Student x,Student y )
{
  if(x.ID < y.ID)
     return true;
  else
    return false;
}

bool operator>(Student x,Student y)
{
  if(x.ID > y.ID)
     return true;
  else
     return false;
}

bool BST :: isEmpty()
{
  if(root == NULL)
     return true;
  else
     return false;
}

TreeNode* BST :: insertElt(TreeNode* newNode)
{
  if(root == NULL)
  {
     root = newNode;
  }
  else
  {
     TreeNode* temp = root;
     TreeNode* parent;
     while(temp != NULL)
     {
       if(temp->data < newNode->data)
       {
         parent = temp;
         temp = temp->right;
       }
       else if(temp->data > newNode->data)
       {
         parent = temp;
         temp = temp->left;
       }
       else if(temp->data == newNode->data)
          return NULL;
     }
     if(parent->data < newNode->data)
        parent->right = newNode;
     else if(parent->data > newNode->data)
        parent->left = newNode;
     else if(parent->data == newNode->data)
        return NULL;
  }
  return root;
}


TreeNode* BST :: deleteElt(Student Elt)
{
 TreeNode *parent = NULL;
 TreeNode *temp = root;
 while(temp != NULL)
 {
 if(temp->data == Elt) //Element to be deleted is found
 {
 if(temp->left==NULL && temp->right==NULL)
 { // Leaf Node deletion
 if(temp == root) // node to be deleted is root
 {
 root = NULL;
 }
 else // node to be deleted is leaf
 {
 if(parent->left == temp)
 parent->left = NULL;
 else
 parent->right = NULL;
 }
 delete temp;
 temp = NULL;
 }
else if(temp->left != NULL && temp->right != NULL)
{ //Deletion of a node having two child
 //to find smallest element in right subtree. Inorder successor
  TreeNode* temp1;
   temp1 = temp->right;
    while(temp1->left != NULL)
     { //Inorder successor will be the left most element in right subtree
     parent = temp1;
       temp1 = temp1->left;
        }
        temp->data = temp1->data;
         if(temp1->right != NULL) //Successor node has single right child
          parent->left = temp1->right;
            else //node to be deleted is a leaf node
            {
             parent->left = NULL;
            delete temp1;
               temp1 = NULL;
                }
                }
 
                 else //node to be deleted is having single child
                 {
                   if(temp == root) //Node to be deleted is a root
                    {
                     if(temp->left!= NULL && temp->right==NULL)
                      { // root with one left child
                       root = temp->left;
                        }
                         else // root with one right child
                         {
                           root = temp->right;
                            }
                             delete temp;
                              temp = NULL;
                               } //end of if
 
                               else //Node to be deleted is not a root
                               {
                                if(parent->right == temp)
                                 { //Node to be deleted is right child of its parent
                                  if (temp->right != NULL && temp->left == NULL)
                                   //it has single right child
                                    parent->right = temp->right;
                                     else //it has single left child
                                      parent->right = temp->left;
                                      }
                                       else
                                        { //Node to be deleted is left child of its parent
                                         if (temp->right != NULL && temp->left == NULL)
                                          //it has single right child
                                           parent->left = temp->right;
                                            else //it has single left child
                                             parent->left = temp->left;
                                              }
                                               delete temp;
                                                temp = NULL;
                                                } //end of else
                                                 }
                                                  }
                                                  else if( temp->data > Elt)
                                                  { //Search for element to be deleted in left subtree
                                                   parent = temp;
                                                     temp = temp->left;
                                                      } 
                                                       else //Search for element to be deleted in right subtree
                                                        {
                                                         parent = temp;
                                                          temp = temp->right;
                                                           }
                                                            } //end-of while
                                                             return root;
                                                             } //end-of function definition
 





/*TreeNode* BST :: deleteElt(Student Elt)
{
  TreeNode *parent = NULL;
  TreeNode *temp = root;
  while(temp != NULL)
  {
    if(temp->data == Elt)
     //Element to be deleted is found
    {
      if(temp->left==NULL && temp->right==NULL)
      {
  //Leaf Node deletion
        if(temp == root) // node to be deleted is root
        {
          root = NULL;
        }
        else // node to be deleted is leaf
        {
          if(parent->left == temp)
            parent->left = NULL;
          else 
            parent->right = NULL;
        }
        delete temp;
        temp = NULL;
      }
      else if(temp->left != NULL && temp->right != NULL)
      {
//Deletion of a node having two child
//to find smallest element in right subtree. Inorder successor
        TreeNode* temp1;
        temp1 = temp->right;
        while(temp1->left != NULL)
        { 
       //Inorder successor will be the left most element in right subtreeparent = temp1;
          temp1 = temp1->left;
        }
        temp->data = temp1->data;
        if(temp1->right != NULL) //Successor node has single right child
          parent->left = temp1->right;
        else
    //node to be deleted is a leaf node
        {
           parent->left = NULL;
           delete temp1;
           temp1 = NULL;
        }
      }
      else //node to be deleted is having single child
      {
        if(temp == root) //Node to be deleted is a root
        {
          if(temp->left!= NULL && temp->right==NULL)
          {
// root with one left child
            root = temp->left;
          }
          else // root with one right child
          {
            root = temp->right;
          }
          delete temp;
          temp = NULL;
        } //end of ifelse
 //Node to be deleted is not a root
        if(parent->right == temp)
        {
//Node to be deleted is right child of it’s parent
          if (temp->right != NULL && temp->left == NULL)
//it has single right child
            parent->right = temp->right;
          else
//it has single left child
            parent->right = temp->left;
        }
        else
        {
//Node to be deleted is left child of it’s parent
          if (temp->right != NULL && temp->left == NULL)
//it has single right child
            parent->left = temp->right;
         else
//it has single left child
           parent->left = temp->left;
        }
        delete temp;
        temp = NULL;
      } //end of else
    }
  }
  else if( temp->data > Elt)
  {
//Search for element to be deleted in left subtree
    parent = temp;
    temp = temp->left;
  }
  else //Search for element to be deleted in right subtree
  {
    parent = temp;
    temp = temp->right;
  }
} //end-of while
return root;
} //end-of function definition
*/

Student BST :: search(Student key)
{
  Student p;
  TreeNode* n = root;
  while(n != NULL)
  {
    if(n->data == key)
       return n->data;
    if(key < n->data)
      n = n->left; 
    else
       n = n->right;
  }
  return p;
}

void BST :: inorder(TreeNode* temp)
{
  if(temp != NULL)
  {
    inorder(temp->left);
    cout<<temp->data;
    inorder(temp->right);
  }
}

void BST :: preorder(TreeNode* temp)
{
  if(temp != NULL)
  {
    cout<<temp->data;
    preorder(temp->left);
    preorder(temp->right);
  }
}
 
void BST :: postorder(TreeNode* temp)
{
  if(temp != NULL)
  {
    postorder(temp->left);
    postorder(temp->right);
    cout<<temp->data;
  }
}

TreeNode :: TreeNode()
{
  data = 0;
  left = NULL;right = NULL;
}

TreeNode :: TreeNode(Student d,TreeNode* l,TreeNode* r)
{
  data = d;
  left = l;
  right = r;
}

TreeNode :: TreeNode(const TreeNode &ref)
{
  data = ref.data;
  left = ref.left;
  right = ref.right;
}

TreeNode :: ~TreeNode()
{
  data = 0;
  left = NULL;
  right = NULL;
}

BST :: BST()
{
  root = NULL;
}

BST :: BST(TreeNode* r)
{
  root = r;
}
 
BST :: BST(const BST &ref)
{
  root = ref.root;
}

BST :: ~BST()
{
  delete root;
}
  
TreeNode* BST :: getRoot()
{
  return root;
}
