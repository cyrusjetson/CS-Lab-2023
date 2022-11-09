#include <iostream>
using namespace std;
#include "A_Queue.h"
Student :: Student()
{
  name = "NULL";
  rollNo = 0;
  cgpa = 0.0;
}

Student :: Student (string tempName,int roll,float tempCgpa)
{
  name = tempName;
  rollNo = roll;
  cgpa = tempCgpa;
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
  cgpa = 0;
  return *this;
}

ostream& operator<<(ostream& myout,Student &p)
{
  myout<<"\nName : "<<p.name;
  myout<<"\nRollNo : "<<p.rollNo;
  myout<<"\nCGPA : "<<p.cgpa;
  return myout;
}

istream& operator>>(istream& myin,Student &p)
{
  cout<<"Enter name: ";
  myin>>p.name;
  cout<<"Enter rollNo: ";
  myin>>p.rollNo;
  cout<<"Enter cgpa: ";
  myin>>p.cgpa;
  return myin;
}

A_Queue :: A_Queue()
{
  front = -1;
  rear = -1;
  capacity = 5;
  queueArr = new Student[capacity];
  for(int i = 0;i < 5;i++)
    queueArr[i] = -1;
} 

A_Queue :: A_Queue(Student* a,int r,int s,int c)
{
  rear = r -1;
  front = s;
  capacity = c;
  queueArr = new Student[capacity];
  for(int i = 0;i <= rear;i++)
   queueArr[i] = a[i];
  for(int i = rear + 1;i < capacity;i++)
   queueArr[i] = -1;
}

A_Queue :: A_Queue(const A_Queue &ref)
{
  rear = ref.rear;
  front = ref.front;
  capacity = ref.capacity;
  queueArr = new Student[capacity];
  for(int i = 0;i <= rear;i++)
    queueArr[i] = ref.queueArr[i];
  for(int i = rear + 1;i < capacity;i++)
    queueArr[i] = -1;
}

A_Queue :: ~A_Queue()
{
  front = -1;
  rear = -1;
  capacity = 0;
  delete [] queueArr;
  queueArr = NULL;
}

int A_Queue :: isFull()
{
  if((rear+1)%capacity==front)
    return 1;//Queue is full
  else
   return 0;//Queue is not full
}

int A_Queue :: isEmpty()
{
  if((front == -1 && rear == -1) ||(front > rear))
    return 1;//Queue is empty
  else
    return 0;//Queue is not empty
}

int A_Queue :: enqueue(Student x)
{
  if(!isFull())
  {
    if(front == -1 && rear == -1)
    {
      front = 0;
      rear = 0;
      queueArr[rear] = x;
    }
    else
    {
      rear=(rear+1)%capacity;
      queueArr[rear] = x;
      cout<<"\nhai\n";
    }
    return 1;
  }
  else
    return 0;
}

Student A_Queue :: dequeue()
{
  if(!isEmpty())
  {
    Student deletedElt = queueArr[front];
    if(front == rear)
    {
      front = -1;
      rear = -1;
    }
    else
    {
      front=(front+1)%capacity;
    }
    return deletedElt;
  }
}

int A_Queue :: displayQueue()
{
  int j=0;
  if(!isEmpty())
  {
    int i = front;
    cout<<"Student details:\n";
    while(i!=rear)
    {
      j=j+1;
      cout<<"\nStudent "<<j<<" details:\n";
      cout<<queueArr[i]<<"\n";
      i=(i+1)%capacity;
    }
    cout<<"\nStudent "<<j+1<<" details:\n";
    cout<<queueArr[i];
    cout<<"\n";
    return 1;
  }
  else
     cout<<"\n Queue is empty\n";
  return 0;
}

int A_Queue :: makeQueueEmpty()
{
  while(!isEmpty())
  {
    Student deletedElt = dequeue();
  }
  return 1;
}

Student A_Queue :: peak()
{
  if(!isEmpty())
  {
    return queueArr[front];
  }
}

Student A_Queue :: recent()
{
  if(!isEmpty())
  {
    return queueArr[rear];
  }
}

int A_Queue :: size()
{
  if(!isEmpty())
  {
    int i = front;
    int count = 0;
    while(i!=rear)
    {
      count++;
      i=(i+1)%capacity;
    }
    count++;
    return count;
  }
  else
    return 0;
}

