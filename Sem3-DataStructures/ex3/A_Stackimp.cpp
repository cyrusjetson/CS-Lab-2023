#include<iostream>
using namespace std;
#include"A_Stack.h"
Student :: Student()
{
  name = "NULL";
  rollNo = 0;
  cgpa = 0.0;
}

Student :: Student (string nameTemp,int rollNoTemp,float cgpaTemp)
{
  name = nameTemp;
  rollNo = rollNoTemp;
  cgpa = cgpaTemp;
}

Student Student :: operator=(Student temp)
{
  name = temp.name;
  rollNo = temp.rollNo;
  cgpa = temp.cgpa;
  return *this;
}

Student Student :: operator=(int temp)
{
  name = "NULL";
  rollNo = temp;
  cgpa = temp*0.1;
  return *this;
}

ostream& operator<<(ostream& myout,Student &temp)
{
  myout<<"\nName : "<<temp.name;
  myout<<"\nRollNo : "<<temp.rollNo;
  myout<<"\nCGPA : "<<temp.cgpa<<"\n";
  return myout;
}

istream& operator>>(istream& myin,Student &temp)
{
  cout<<"Enter name: ";
  myin>>temp.name;
  cout<<"Enter rollNo: ";
  myin>>temp.rollNo;
  cout<<"Enter CGPA: ";
  myin>>temp.cgpa;
  return myin;
}

A_Stack :: A_Stack()
{
  top = -1;
  capacity = 5;
  stackArr = new Student[capacity];
  for(int i = 0;i < 5;i++)
    stackArr[i] = -1;
}

A_Stack :: A_Stack(Student* a,int t,int c)
{
  top = t;
  capacity = c;
  stackArr = new Student[capacity];
  for(int i = 0;i <= top;i++)
     stackArr[i] = a[i];
  for(int i = top+1;i < capacity;i++)
     stackArr[i] = -1;
}

A_Stack :: A_Stack(const A_Stack &ref)
{
  top = ref.top;
  capacity = ref.capacity;
  stackArr = new Student[capacity];
  for(int i = 0;i <= top;i++)
    stackArr[i] = ref.stackArr[i];
  for(int i = top + 1;i < capacity;i++)
    stackArr[i] = -1;
}

A_Stack :: ~A_Stack()
{
  top = -1;
  capacity = 0;
  delete [] stackArr;
  stackArr = NULL;
}

int A_Stack :: isFull()
{
  if(top + 1 == capacity)
    return 1;//Stack is full
  else
    return 0;//Stack is not full
}

int A_Stack :: isEmpty()
{
  if(top == -1)
    return 1;//Stack is empty
  else
     return 0;//Stack is not empty
}

int A_Stack :: push(Student x)
{
  if(!isFull())
  {
    top++;
    stackArr[top] = x;
    return 1;
  }
  else
    return 0;
}

Student A_Stack :: pop()
{
  Student deletedElt = stackArr[top];
  stackArr[top] = -1;
  top--;
  return deletedElt;
}

int A_Stack :: displayStack()
{
  if(!isEmpty())
  {
    for(int i = top;i >= 0 ;i--)
    {
      cout<<stackArr[i];
    }
    cout<<"\n";
    return 1;
 }
 else
   return 0;
}

int A_Stack :: makeStackEmpty()
{
  while(!isEmpty())
    Student deletedElt = pop();
  return 1;
}

Student A_Stack :: peak()
{
  return stackArr[top];
}

