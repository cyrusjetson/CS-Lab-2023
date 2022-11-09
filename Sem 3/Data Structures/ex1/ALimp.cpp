#include"AL.h"
#include<iostream>
using namespace std;Student::Student()
{
  rollNo=0;
  name=" ";
  cgpa=0.1;
}

Student::Student(int rollNoTemp,string nameTemp,float cgpaTemp)
{
  rollNo=rollNoTemp;
  name=nameTemp;
  cgpa=cgpaTemp;
}

void display(Student S1)
{
  cout<<"\n RollNo = "<<S1.rollNo;
  cout<<"\n Name = "<<S1.name;
  cout<<"\n CGPA = "<<S1.cgpa;
  cout<<"\n";
}

Student::Student(const Student& ref)
{
  rollNo=ref.rollNo;
  name=ref.name;
  cgpa= ref.cgpa;
}

void Student::getDetails(int rollNoTemp,string nameTemp,float cgpaTemp)
{
  rollNo=rollNoTemp;
  name=nameTemp;
  cgpa=cgpaTemp;
}

A_List::A_List()
{
  capacity=0;
  size=0;
  studentsArray =new Student[capacity];
}

A_List::A_List(Student* arr,int capacityTemp,int sizeTemp)
{
  int i;
  capacity=capacityTemp;
  size=sizeTemp;
  for(i=0;i<size;i++){
    studentsArray[i]=arr[i];
  }
}

A_List::A_List(const A_List& ref)
{
  int j;
  capacity=ref.capacity;
  size=ref.size;
  for(j=0;j<ref.size;j++)
  {
    studentsArray[j]=ref.studentsArray[j];
  }
}

int A_List:: isFull()
{
  if(capacity== size)
    return 1;
  else
    return 0;
}

int A_List:: isEmpty()
{
  if(size==0)
    return 1;
  else
    return 0;
}

int A_List:: insertAtFirst(Student element)
{
  if(isFull()==0)
  {
    if(isEmpty()==1)
    {
      studentsArray[size++] = element;
    }
    else
    {
      for(int i=size-1; i>=0; i--)
      {
        studentsArray[i+1] = studentsArray[i];
      }
      studentsArray[0] = element;
      size++;
    }
    return 1;
  }
  else
    return 0;
}

int A_List:: insertAtLast(Student element)
{
  if(isFull()==0)
  {
    studentsArray[size++] = element;
    return 1;
  }
  else
    return 0;
}

int A_List::insertByPos(Student element, int pos)
{
  int i;
  if(isFull()==0)
  {
    if(pos > size+1)
      return -2;
    else
    {
      if((isEmpty()==1) && pos == 1)
      {
         insertAtFirst(element);
      }
      else if((isEmpty()==1) && pos!=1)
        return -3;
      else
      {
        for(i = size; i>pos-2;i--)
        studentsArray[i+1] = studentsArray[i];
        studentsArray[i+1] = element;
        size++;
      }
      return 1;
    }
  }
  else
     return 0;
}

void A_List::setDetails(Student* arr,int capacityTemp,int sizeTemp)
{
  capacity=capacityTemp;size=sizeTemp;
  studentsArray= new Student[capacity];
  for(int i=0;i<size;i++)
  {
    studentsArray[i]=arr[i];
  }
}

int A_List::deleteAtFirst()
{
  if(isEmpty()==0)
  {
    for(int i=0; i<size;i++)
      studentsArray[i] = studentsArray[i+1];
    size--;
    return 1;
  }
  else
     return -13;
}

int A_List::deleteAtLast()
{
  if(isEmpty()==0)
  {
    studentsArray[size-1].name="";
    studentsArray[size-1].rollNo=0;
    studentsArray[size-1].cgpa=0.1;
    size=size-1;
    return 1;
  }
  else
     return -1;
}

int A_List::displayList()
{
  if(isEmpty()==0)
  {
    cout<<"\nStudent details:\nRollno\t CGPA\t\t Name\n";
    for(int i=0; i<size; i++)
    {
        cout<<studentsArray[i].rollNo<<"\t"<<studentsArray[i].cgpa<<"\t\t"<<studentsArray[i].name<<"\n";
    }
    cout<<"\n";
    return 1;
  }
  else
    return -1;
}

int A_List::makeListEmpty()
{
  while(isEmpty()==0)
  {
     deleteAtFirst();
  }
  return 1;
}

int A_List::searchAtFirst()
{
  if(isEmpty()==0)
  {
     display(studentsArray[0]);
     return 1;
  }
  else
     return -1;
}

int A_List::searchAnElt(int key)
{
  if(isEmpty()==0)
  {
    for(int i= 0; i<size; i++)
    {
      if(studentsArray[i].rollNo==key)
      {
         display(studentsArray[i]);
         return i;
      }
    }
    return -2;
  }
  else
    return -1;
}

