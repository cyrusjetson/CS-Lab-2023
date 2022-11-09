#include <stdio.h>
#include <iostream>
#include "LL.h"
#include<cstring>
using namespace std;
int main()
{
  int ch,ele,pos;
  float cgpaTemp;
  bool val;
  string nameTemp;
  L_List obj;
  int end=0;
  do
  {
     cout<<"\n\t~~~ Student Details Management System ~~~ \n\nSelect which operation you like to perform...\n1.insertAtFirst\n2.insertAtLast\n3.insertByPosition\n4.deleteAtFirst\n5.deleteAtLast\n6.deleteByPosition\n7.makeListEmpty\n8.GetPosition\n9.displayAll\n10.Exit\nEnter your choice: ";
     cin>>ch;
     end=0;
     if(ch==1)
     {
       cout<<"\nEnter the name: ";
       cin>>nameTemp;
       cout<<"Enter the rollNo Number: ";
       cin>>ele;
       cout<<"Enter the CGPA: ";
       cin>>cgpaTemp;
       Node *NewNode=new Node(nameTemp,ele,cgpaTemp);
       val=obj.insertAtFirst(NewNode);
       if(val==true)
         cout<<"Insertion Is Successfull\n";
       else
         cout<<"Insertion is not possible\n";
     }
     if(ch==2)
     {
       cout<<"Enter the name: ";
       cin>>nameTemp;
       cout<<"Enter the rollNo Number: ";
       cin>>ele;
       cout<<"Enter the CGPA: ";
       cin>>cgpaTemp;
       Node *NewNode=new Node(nameTemp,ele,cgpaTemp);
       val=obj.insertAtLast(NewNode);
       if(val==true)
          cout<<"Insertion Is Successfull\n";
       else
          cout<<"Insertion is not possible\n";
     }
     if(ch==3)
     {
       cout<<"Enter the name: ";
       cin>>nameTemp;
       cout<<"Enter the rollNo Number: ";
       cin>>ele;
       cout<<"Enter the CGPA: ";
       cin>>cgpaTemp;
       Node *NewNode=new Node(nameTemp,ele,cgpaTemp);
       cout<<"\nEnter the position to be inserted: ";
       cin>>pos;
       val=obj.insertByPosition(pos,NewNode);
       if(val==true)
           cout<<"Insertion Is Successfull\n";
       else
          cout<<"Insertion is not possible\n";
     }
     if(ch==4)
     {
       val=obj.deleteAtFirst();
       if(val==true)
          cout<<"Deletion Is Successfull\n";
       else
          cout<<"Deletion is not possible\n";
      }
      if(ch==5)
      {
        val=obj.deleteAtLast();
        if(val==true)
          cout<<"Deletion Is Successfull\n";
        else
       cout<<"Deletion is not possible\n";
     }
     if(ch==6)
     {
        cout<<"\nEnter the position to be deleted: ";
        cin>>pos;
        val=obj.deleteByPosition(pos);
        if(val==true)
           cout<<"Deletion Is Successfull\n";
        else
           cout<<"Deletion is not possible\n";
     }
     if(ch==7)
     {
        val=obj.makeListEmpty();
        if(val==true)
          cout<<"Deletion Is Successfull\n";
       else
          cout<<"List is Already Empty\n";
     }
     if(ch==8)
     {
        int a;
        cout<<"\nEnter the roll number to find position: ";
        cin>>pos;
        a=obj.getPositionOfElement(pos);
        if(a!=-1)
          cout<<"\nThe Position of Given rollNo Number is "<<a<<"\n";
        else
          cout<<"The roll Number is not present\n";
     }
     if(ch==9)
     {
       obj.displayAll();
     }
     if(ch==10)
     {
       end=1;
     }
     if(ch<1 || ch>10)
     {
       cout<<"Enter a valid Input\n";
     }
   }while(end!=1);
 cout<<"\n\tThank You!\n\n";
}

