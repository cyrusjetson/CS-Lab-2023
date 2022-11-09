#include"head.h"
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
  char name[20];
  int id;
  float cgpa;
  BinHeap h;
  int ch=0;
  while(true){
   cout<<"\n 1.Insert an Student.";
   cout<<"\n 2.Delete an Student.";
   cout<<"\n 3.Find the first Student.";
   cout<<"\n 4.search an Student by id.";
   cout<<"\n 5.Display all the Student details.";
   cout<<"\n 6.exit.";
   cout<<"\n Enter your choice of interest : ";
   cin>>ch;
   switch(ch)
   {
     case 1:
     {
       cout<<"\n Enter the name of the Student: ";
       cin>>name;
       cout<<"\n Enter ID: ";
       cin>>id ;
       cout<<"\n Enter CGPA: ";
       cin>>cgpa;
       Student s(name,id,cgpa);
       if(h.enqueue(s)==1)
         cout<<"\n Student inserted.";
       else
         cout<<"\n List is full.";
       break;
     }
     case 2:
     {
       Student s=h.dequeue();
       if(s.getID()==0)
         cout<<"\n List is empty.";
       else
         s.dispDetails();
       break;
     }
     case 3:
     {
       Student temp=h.findMin();
       if(temp.getID()==0)
         cout<<"\n List is empty.";
       else
         temp.dispDetails();
       break;
     }
     case 4:
     {
       int id;
       cout<<"\n Enter the id of the Student to be searched.";
       cin>>id;
       if(h.search(id)==-1)
         cout<<"\n Student details missing.";
       else
         cout<<"\n Student details present.";
       break;
     }
     case 5:
     {
       cout<<"\n ID \t Name \t CGPA\n ";
       h.display();
       break;
     }
     case 6:
        exit(0);
     default:
        cout<<"\n Invalid input.\n";
    }
  }
}
