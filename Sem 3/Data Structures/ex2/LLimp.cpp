#include"LL.h"
#include<iostream>
#include<cstring>
using namespace std;
Node::Node()
{
  data.name="";
  data.rollNo=-1;
  data.cgpa=-1;
}

Node::Node(string Name,int RollNo,float Cgpa)
{
  data.name=Name;
  data.rollNo=RollNo;
  data.cgpa=Cgpa;
  next=NULL;
}

string Student::getName()
{
  return name;
}

int Student::getRoll()
{
  return rollNo;
}

float Student::getCgpa()
{
  return cgpa;
}

L_List::L_List()
{
  first=NULL;
}

bool L_List::isEmpty()
{
  if(first==NULL)
    return true;
  else
    return false;
}

bool L_List::insertAtFirst(Node *NewNode)
{
  if(isEmpty())
  {
    first=NewNode;
    return true;
  }
  NewNode->next=first;
  first=NewNode;
  return true;
}

bool L_List::insertAtLast(Node *NewNode)
{
  if(isEmpty())
  {
    first=NewNode;
    return true;
  }
  Node *temp=first;
  while(temp->next!=NULL)
  {
    temp=temp->next;
  }
  temp->next=NewNode;
   return true;
}

bool L_List::insertByPosition(int pos,Node *NewNode)
{
  Node *temp=first;
  int i=1;
  if(pos==1)
  { 
    insertAtFirst(NewNode);
    return true;
  }
  while(i<pos-1)
  {
    if(temp->next==NULL)
    break;
    cout<<" ";
    temp=temp->next;
    i=i+1;
  }
  if(i==pos-1)
  {
    NewNode->next=temp->next;
    temp->next=NewNode;
    return true;
  }
  return false;
}

bool L_List::deleteAtFirst()
{
  if(!isEmpty())
  {
  Node *temp=first;
  first=first->next;
  delete temp;
  return true;
  }
  return false;
}

bool L_List::deleteAtLast()
{
  if(!isEmpty())
  {
    if(first->next==NULL)
    {
      deleteAtFirst();
      return true;
    }
    Node *temp1=first;
    Node *temp2=temp1;
    while(temp1->next!=NULL)
    {
      temp2=temp1;
      temp1=temp1->next;
    }
    temp2->next=NULL;
    delete temp1;
    return true;
  }
  else
  return false;
}

bool L_List::deleteByPosition(int pos)
{
  Node *temp=first;
  int i=1;
  if(pos==1)
  {
    deleteAtFirst();
    return true;
  }
  Node *temp2=temp;
  while(i<pos)
  {
    if(temp->next==NULL)
    break;
    temp2=temp;
    temp=temp->next;
    i=i+1;
  }
  cout<<"value "<<i<<" ";
  if(i==pos)
  {
    temp2->next=temp->next;
    delete temp;
    return true;
  }
    return false;
}

bool L_List::makeListEmpty()
{
  if(!isEmpty())
  {
    while(first!=NULL)
    deleteAtFirst();
    return true;
  }
  else
     return false;
}

int L_List::getPositionOfElement(int pos)
{
  if(!isEmpty())
  {
    int i=0;
    Node *temp=first;
    while(temp->next!=NULL && temp->data.getRoll()!=pos )
    {
      temp=temp->next;
      i=i+1;
    }
    if(temp->data.getRoll()==pos)
    {
      return i+1;
    }
  }
  else
    return -1;
}

int L_List::displayAll()
{
  Node *temp=first;
  if(temp==NULL)
  {
    cout<<" List is empty \n";
    return 0;
  }
  cout<<"\nStudent Details:\n";
  cout<<"\nRollNo\tCGPA\t Name\n";
  while(temp!=NULL)
  {
    cout<<temp->data.getRoll()<<"\t"<<temp->data.getCgpa()<<"\t"<<temp->data.getName()<<"\n";
    temp=temp->next;
  }
  return 1;
}

