#include "A_Stack.h"
#include <iostream>
using namespace std;
int main()
{
  int ch,top,temp,capacity;
  Student ele1;
  cout<<"\n\t~~~~~ Student details Management System in Stack Data structure using Arrays~~~~\n";
  cout<<"\nEnter the max no of student details U like to insert: ";
  cin>>capacity;
  cout<<"\nEnter how many students details you like to insert now: ";
  cin>>temp;
  top=temp-1;
  cout<<"\n";
  Student ele[capacity];
  for(int i = 0;i < top + 1;i++)
  {
    cout<<"\nEnter Student "<<i+1<<" details:\n";
    cin>>ele[i];
  }
  A_Stack a(ele,top,capacity);
  while(1)
  {
    cout<<"\n\nMenu:\n";
    cout<<"\n1.Insert a student detail";
    cout<<"\n2.Delete the recently uploaded student's details";
    cout<<"\n3.Display the recently uploaded student's details";
    cout<<"\n4.Display all student's details";
    cout<<"\n5.Delete all uploaded details";
    cout<<"\n6.Exit\n";
    cout<<"\nEnter your choice: ";
    cin>>ch;
    switch(ch)
    {
      case 1:
      {
        cout<<"\nEnter student details:\n";
        cin>>ele1;
        if(a.push(ele1))
          cout<<"\n Student detail is successfully uploaded\n";
        else
        {
          cout<<"\n Insertion operation is failed. Because, stack is full\n";
        }
        break;
      }
      case 2:
      {
        cout<<"\nThe below Student detail is poped out from the stack\n";
        Student p = a.pop();
        cout<<p;
        break;
      }
      case 3:
      {
        cout<<"\nRecently added student's details:\n";
        Student s1 = a.peak();
        cout<<s1;
        break;
      }
      case 4:
      {
         cout<<"\n----------------------------";
         cout<<"\n Uploaded student details\n";
         cout<<"----------------------------\n";
         a.displayStack();
         break;
      }
      case 5:
      {
        a.makeStackEmpty();
        cout<<"\n All the uploaded student details are successfully deleted\n";
        break;
      }
      case 6: return 0;
    }
  }
}
