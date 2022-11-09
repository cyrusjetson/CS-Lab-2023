#include"head.h"
#include<iostream>
#include<string.h>
#include<stdio.h>
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
  cgpa=f.cgpa;
}

int Student::getID()
{
 return ID;
}

void Student::dispDetails()
{
  cout<<ID<<" \t "<<name<<" \t "<<cgpa;
}

BinHeap::BinHeap()
{
  hsize=0;
  capacity=20;
  s=new Student[capacity+1];
}

int BinHeap::isEmpty()
{
  return(hsize==0);
}

int BinHeap::isFull()
{
  return(capacity==hsize);
}

int BinHeap::enqueue(Student emp)
{
  if(isFull())
    return -1;
  else
  {
    int ctnode =++hsize;
    while(ctnode!=1 && s[ctnode/2].ID>emp.ID)
    {
      s[ctnode]=s[ctnode/2];
      ctnode/=2;
    }
    s[ctnode]=emp;
    return 1;
  }
}

Student BinHeap::dequeue() //remove an element (delete min)
{
  if(isEmpty())
  {
    Student s;
    return s;
  }
  else{
    Student temp=s[1];
    Student last=s[hsize--];
    int low_child=2;
    int ctnode=1;
    while(low_child <= hsize)
    {
      if(low_child<hsize && s[low_child].ID>s[low_child+1].ID)
      low_child++;
      if(last.ID<=s[low_child].ID) //last element replaced is the min element
        break;
      s[ctnode]=s[low_child];
      ctnode=low_child;
      low_child=ctnode*2;
    }
    s[ctnode]=last;
    return temp;
  }
}

Student BinHeap::findMin() //find minimum element
{
  if(!isEmpty())
    return s[1];
  else
  {
    Student temp;
    return temp;
  }
}

int BinHeap::search(int id) //search an element by id
{
  int i;
  for(i=1;i<=hsize;i++)
    if(s[i].ID==id)
      {
        s[i].dispDetails(); 
        return 1; //Student found
      }
  return -1; //Student not found
}

void BinHeap::display() //display the heap
{
  if(isEmpty())
    cout<<"List is Empty\n";
  else
  {
    int i;
    for(i=1;i<=hsize;i++)
      s[i].dispDetails();
  }
}
