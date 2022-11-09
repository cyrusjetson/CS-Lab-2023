#include <iostream>
using namespace std;
#include "L_Stack_L_Queue.h"
Student :: Student()
{
  name = "NULL";
  rollNo = 0;
  cgpa = 0.0;
}

Student :: Student (string n,int r,float ra)
{
  name = n;
  rollNo = r;
  cgpa = ra;
}

Node :: Node()
{
  data = 0;
  next = NULL;
}

Node :: Node(Student d,Node* n)
{
  data = d;
  next = n;
}

Node :: Node(const Node &ref)
{
  data = ref.data;
  next = ref.next;
}

Node :: ~Node()
{
  data = 0;
  next = NULL;
}

void Node :: getDetails()
{
  cout<<"Enter details:";
  cin>>data;
}

void Node :: displayDetails()
{
  cout<<data;
}

Student Student :: operator=(Student x)
{
  name = x.name;
  rollNo = x.rollNo;
  cgpa = x.cgpa;
  return *this;
}

Student Student :: operator=(int x)
{
  name = "NULL";
  rollNo = x;
  cgpa = x * 0.1;
  return *this;
}

istream& operator>>(istream& myin,Student& p)
{
  cout<<"\nEnter name: ";
  myin>>p.name;
  cout<<"Enter rollNo: ";
  myin>>p.rollNo;
  cout<<"Enter CGPA: ";
  myin>>p.cgpa;
  return myin;
}

ostream& operator<<(ostream& myout,Student& p)
{
  myout<<"\nName: "<<p.name;
  myout<<"\nRollNo: "<<p.rollNo;
  myout<<"\nCGPA: "<<p.cgpa<<"\n";
  return myout;
}

L_Stack :: L_Stack()
{
  top = NULL;
}

L_Stack :: L_Stack(Node* f)
{
  top = f;
}

L_Stack :: L_Stack(const L_Stack& ref)
{
  top = ref.top;
}

L_Stack :: ~L_Stack()
{
  top = NULL;
}

int L_Stack :: isEmpty()
{
  if(top == NULL)
    return 1;
  else
    return 0;
}

int L_Stack :: push(Node *newNode)
{
  if(isEmpty())
  {
    top = newNode;
  }
  else
  {
    newNode->next = top;
    top = newNode;
  }
  return 1;
}

int L_Stack :: pop()
{
  if(!isEmpty())
  {
    cout<<"\nThe below student's details are suceessfully deleted\n ";
    Node *temp = top;
    Student deletedElt = temp->data;
    top = top->next;
    delete temp;
    temp = NULL;
    cout<< deletedElt;
    return 1;
  }
  cout<<"\n Stack is Empty\n";
  return 0;
}

int L_Stack :: peak()
{
  if(!isEmpty())
  {
    cout<<"\nRecently inserted student detail:\n";
    cout<< top->data;
    return 1;
  }
  cout<<"\n Stack is empty\n";
  return 0;
}

void L_Stack :: displayStack()
{
  if(!isEmpty())
  {
    cout<<"\nAll Details:\n";
    Node *temp = top;
    while(temp->next != NULL)
    {
      cout<<temp->data<<"\n";
      temp = temp->next;
    }
    cout<<temp->data<<"\n";
  }
  else
    cout<<"\n Stack is empty \n";
}

int L_Stack :: makeStackEmpty()
{
  Node *temp= top;
  while(temp!=NULL)
  {
    temp = top;
    top = top->next;
    delete temp;
    temp=top;
  }
  top= NULL;
}

L_Queue :: L_Queue()
{
  first = NULL;
}

L_Queue :: L_Queue(Node* f)
{
  first = f;
}

L_Queue :: L_Queue(const L_Queue& ref)
{
  first = ref.first;
}

L_Queue :: ~L_Queue()
{
  first = NULL;
}

int L_Queue :: isEmpty()
{
  if(first == NULL)
    return 1;
  else
    return 0;
}

int L_Queue :: enqueue(Node *newNode)
{
  if(isEmpty())
  {
    first = newNode;
  }
  else
  {
    Node *temp = first;
    while(temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newNode;
  }
  return 1;
}

int L_Queue :: dequeue()
{
  if(isEmpty()!=1)
  {
    Node *temp = first;
    Student deletedElt = temp->data;
    first = first->next;
    delete temp;
    temp = NULL;
    cout<< deletedElt;
  }
  else
    cout<<"\n Queue is Empty\n";
}

int L_Queue :: peak()
{
  if(isEmpty()!=1)
  {
    cout<<"The first student's details:";
    cout<< first->data;
    return 1;
  }
  cout<<"\n Queue is empty\n";
  return 0;
}

int L_Queue:: recent()
{
  cout<<"\nRecently added student's details:\n";
  if(isEmpty()!=1)
  {
    Node *temp= first;
    while(temp->next!=NULL)
    {
       temp= temp->next;
    }
    cout<< temp->data;
  }
}

void L_Queue :: displayQueue()
{
  if(isEmpty()!=1)
  {
    cout<<"\nAll details:\n";
    Node *temp = first;
    while(temp->next != NULL)
    {
      cout<<temp->data<<"\n";
      temp = temp->next;
    }
    cout<<temp->data<<"\n";
  }
  else
    cout<<"\n Queue is Empty\n";
}

int L_Queue :: makeQueueEmpty()
{
  Node *temp = first;
  while(temp != NULL)
  {
    temp = first;
    first = first->next;
    delete temp;
    temp = first;
  }
  first = NULL;
  return 1;
}
