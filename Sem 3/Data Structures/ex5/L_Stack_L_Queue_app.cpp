#include<iostream>
#include<string>
using namespace std;
#include "L_Stack_L_Queue.h"
int main()
{
  int ch,ch1,ch2,n;
  Student data,data1;
  Node *newNode;
  L_Stack l;
  L_Queue q;
  cout<<"\n1.Linked List implementation of Stack ADT";
  cout<<"\n2.Linked List implementation of Queue ADT\n";
  cout<<"\nEnter choice:";
  cin>>ch;
  if(ch == 1)
  {
    cout<<"\nEnter number of student details you like to upload: ";
    cin>>n;
    for(int i = 0;i<n;i++)
    {
      cout<<"Enter data:\n";
      cin>>data1;
      cout<<"\n";
      newNode = new Node(data1,NULL);
      l.push(newNode);
    }
    while(1)
    {
      cout<<"\n---------------------------------\n";
      cout<<"\tMenu for Stack ADT";
      cout<<"\n---------------------------------";
      cout<<"\n1.Insert new student detail";
      cout<<"\n2.Delete the recently uploaded student's details";
      cout<<"\n3.Display the recently uploaded student's details";
      cout<<"\n4.Display all details";
      cout<<"\n5.Delete all details\n";
      cout<<"6.Exit\n";
      cout<<"\nEnter your choice:";
      cin>>ch1;
      switch(ch1)
      {
        case 1:
        {
          cout<<"Enter Student details:\n";
          cin>>data;
          cout<<"\n";
          newNode = new Node(data,NULL);
          if(l.push(newNode)==1)
            cout<<"\n Successfully pushed into stack\n";
          else
            cout<<"\n Stack is full\n";
          break;
       }
       case 2:
       {
         l.pop();
         break;
       }
       case 3:
       {
         l.peak();
         break;
       }
       case 4:
       {
         l.displayStack();
         break;
       }
       case 5:
       {
         cout<<"\n All details are successfully deleted\n";
         l.makeStackEmpty();
         break;
       }

       case 6:return 0;
    }
  }
}
else if(ch == 2)
{
   cout<<"\nEnter how many student details you like to insert: ";
   cin>>n;
   for(int i = 0;i<n;i++)
   {
     cout<<"Enter data:\n";
     cin>>data1;
     cout<<"\n";
     newNode = new Node(data1,NULL);
     q.enqueue(newNode);
   }
   while(1)
   {
     cout<<"\n---------------------------------\n";
     cout<<" Menu for Queue ADT";
     cout<<"\n---------------------------------";
     cout<<"\n1.Insert a student detail";
     cout<<"\n2.Delete the first student details";
     cout<<"\n3.show the first student's details";
     cout<<"\n4.Display all details";
     cout<<"\n5.Delete all details";
     cout<<"\n6.Show the recently added student's details";
     cout<<"\n7.Exit\n";
     cout<<"\nEnter your choice: ";
     cin>>ch2;
     switch(ch2)
     {
     case 1:
     {
       cout<<"Enter Student details:\n";
       cin>>data;
       cout<<"\n";
       newNode = new Node(data,NULL);
       q.enqueue(newNode);
       cout<<"\nSuccessfullly inserted the given student's details\n";
       break;
     }
     case 2:
     {
       q.dequeue();
       break;
     }
     case 3:
     {
       q.peak();
       break;
     }
     case 4:
     {
       q.displayQueue();
       break;
     }
     case 5:
     {
       cout<<"\n All details are deleted successfully\n";
       q.makeQueueEmpty();
       break;
     }
     case 6: 
     {
       q.recent();
       break;
     }
     case 7: return 0;
   }
 }
}
}

