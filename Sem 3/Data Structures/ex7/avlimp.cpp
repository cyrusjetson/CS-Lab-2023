#include"avl.h"
#include<iostream>
#include<stdlib.h>
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
  cgpa = f;
  ID=n; 
} 

Student::Student(const Student &f) 
{ 
  strcpy(name,f.name); 
  ID=f.ID; 
  cgpa=f.cgpa;
}

void Student::dispDetails()
{
 cout<<ID<<" \t "<<name<<"\t"<<cgpa<<"\n";
}

AvlNode :: AvlNode()
{
 left=NULL;
 right=NULL;
 height=0;
}
AvlNode :: AvlNode(char* name,int ID,float f) 
{
 b=new Student(name,ID,f);
 left=NULL;
 right=NULL;
 height=0;
} 

Student * AvlNode :: getStudent(AvlNode *temp)
{
 return temp->b;
}

int AvlNode::getId(AvlNode *temp)
{
 return temp->b->ID;
}

AVL::AVL()
{
 root=NULL;
}

AVL::~AVL()
{
 root=NULL;
}

int AVL::findHeight(AvlNode *myNode)
{
 if(myNode==NULL)
        return -1;
 return myNode->height;
}

int AVL::getBalance(AvlNode *myNode)
{
 if(myNode==NULL)
        return -1;
 return findHeight(myNode->left)-findHeight(myNode->right);
}

AvlNode * AVL ::getRoot()
{
 return root;
}

void AVL::updateRoot(AvlNode *newRoot)
{
 root=newRoot;
}

AvlNode * AVL::LLRotate(AvlNode *k3)
{
 AvlNode *k2=k3->left;
 AvlNode *temp=k2->right;
 k2->right=k3;
 k3->left=temp;
 k3->height=max(findHeight(k3->left),findHeight(k3->right))+1;
 k2->height=max(findHeight(k2->left),findHeight(k2->right))+1;
 return k2;
}
AvlNode * AVL::RRRotate(AvlNode *k1)
{
  AvlNode *k2=k1->right;
  AvlNode *temp=k2->left;
  k2->left=k1;
  k1->right=temp;
  k1->height=max(findHeight(k1->left),findHeight(k1->right))+1;
  k2->height=max(findHeight(k2->left),findHeight(k2->right))+1;
  return k2;
}

AvlNode * AVL::LRRotate(AvlNode *k3)
{
  k3->left=RRRotate(k3->left);
  return LLRotate(k3);
}

AvlNode * AVL::RLRotate(AvlNode *k1)
{
  k1->right=RRRotate(k1->right);
  return RRRotate(k1);
}
void AVL::preOrder(AvlNode *temp)
{
  if(temp!=NULL)
  {
    temp->b->dispDetails();
    preOrder(temp->left);
    preOrder(temp->right);
  }
}

void AVL::inOrder(AvlNode *temp)
{
  if(temp!=NULL)
  {
   inOrder(temp->left);
   temp->b->dispDetails();
   inOrder(temp->right);
  }
}

void AVL::postOrder(AvlNode *temp)
{
  if(temp!=NULL)
  {
    postOrder(temp->left);
    postOrder(temp->right);
    temp->b->dispDetails();
  }
}

AvlNode * AVL :: insert(AvlNode *temp,AvlNode *newNode)
{
  if(temp==NULL)
  {
    root=newNode;
    cout<<"\n Insertion successful.";
    return root;
  }
  else if (temp->b->ID > newNode->b->ID)
  {
    if(temp->left==NULL)
    {
        temp->left=newNode;
        cout<<"\n Insertion successful.";
    }
    else
       temp->left=insert(temp->left,newNode);
  }
  else if(temp->b->ID < newNode->b->ID)
  {
    if(temp->right==NULL)
    {
        temp->right=newNode;
        cout<<"\n Insertion successful.";
    }
  else
        temp->right=insert(temp->right,newNode);
 }
 else 
        cout<<"\n Insertion is not successful.";
temp->height=max(findHeight(temp->left),findHeight(temp->right))+1;
 int balance = getBalance(temp);
 if(balance > 1)
 {
  if(newNode->b->ID < temp->left->b->ID)
        return LLRotate(temp);
  else
        return LRRotate(temp);
 }
 if(balance < -1)
 {
  if(newNode->b->ID > temp->right->b->ID)
        return RRRotate(temp);
  else
        return RLRotate(temp);
 }
 return temp;
}
AvlNode * AVL::search(AvlNode *temp,int id)
{
 if(temp == NULL || temp->b->ID==id)
        return temp;
 else if(temp->b->ID < id)
        search(temp->right,id);
 else if(temp->b->ID > id)
        search(temp->left,id);
}
