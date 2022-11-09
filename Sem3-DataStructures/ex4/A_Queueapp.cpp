#include "A_Queue.h"
#include <iostream>
using namespace std;
int main()
{
  int ch,rear,capacity,temp;
  int front=0;
  Student ele1;
  cout<<"\n\t~~~~~~ Student Details Management System Using Circular Queue ADT using arrays Data Structure ~~~~~~\n\n";
  cout<<"Enter max no of student details you like to store: ";
  cin>>capacity;
  cout<<"\nEnter how many student details you like to insert now: ";
  cin>>temp;
  rear=temp;
  cout<<"\n";
  Student ele[capacity];
  for(int i = 0;i < temp;i++)
  {
    cout<<"\nEnter student "<<i+1<<" details:\n";
    cin>>ele[i];
  }
  A_Queue a(ele,rear,front,capacity);
  while(1)
  {
    cout<<"\n\n\tMenu:\n";
    cout<<"\n1.Insert new student detail";
    cout<<"\n2.Delete very first uploaded student's details";
    cout<<"\n3.Show the first Student detail in Queue";
    cout<<"\n4.Number of available student details";
    cout<<"\n5.Display all student details";
    cout<<"\n6.Delete all student details";
    cout<<"\n7.Display the recently added student detail";//NOTE: new implement
    cout<<"\n8.Exit\n";
    cout<<"\nEnter your choice:";
    cin>>ch;
    switch(ch)
    {
      case 1:
      {
        cout<<"\nEnter student details to perform Enqueue operation:\n";
        cin>>ele1;
        if(a.enqueue(ele1)==1)
          cout<<"\n Student details is sucessfully pushed into the queue\n";
       else
       {
          cout<<"\n Insertion is failed. Because Queue is full\n";
       }
       break;
     }

     case 2:
     {
       cout<<"\nThe below Student detail is poped out\n";
       Student p = a.dequeue();
       cout<<p;
       break;
     }
     case 3:
     {
       cout<<"\nFirst student detail in the Queue is,\n";
       Student p1 = a.peak();
       cout<<p1;
       break;
     }
     case 4:
     {
       cout<<"\nQueue has "<<a.size()<<" Student details";
       break;
     }

     case 5:
     {
       cout<<"\n-----------------------------";
       cout<<"\n\tStudent Details\n";
       cout<<"-----------------------------\n";
       a.displayQueue();
       break;
     }
     case 6:
     {
       cout<<"\n None of the student details are available in Queue\n";
       a.makeQueueEmpty();
       break;
     }
     case 7:
     {
       cout<<"Recently added student's detail:\n";
       Student p1 =a.recent();
       cout<<p1;
       break;
     }
     case 8:return 0;
   }
 }
}

