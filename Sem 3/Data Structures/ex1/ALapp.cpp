#include"AL.h"
#include<iostream>
using namespace std;
int main()
{
  int noOfStudents,count,rollNo,capacity,size,option;
  float cgpa;
  string name;
  cout<<"\t ~~~~~ Student Details Management System ~~~~~\n";
  cout<<"\nEnter maximum student Details you like to store(NOTE: you can't store more than this maximum)\n";
  cin>>capacity;
  cout<<"\nEnter how many student details have to upload(NOTE: It must be less than the above entered value or equal to that value):\n ";
  cin>>noOfStudents;
  size = noOfStudents;
  Student *studentArray= new Student[noOfStudents];
  for(int i = 0;i < noOfStudents; i++)
  {
    cout<<"\nEnter "<< i+1<<"student's details( Name,RollNo,CGPA ):\n";
    cin >> name;
    cin >> rollNo;
    cin >> cgpa;
    studentArray[i].getDetails(rollNo,name,cgpa);
  }
  A_List listOfDetails;
  listOfDetails.setDetails(studentArray,capacity,size);
  do
  {
    cout<<"\n\nSelect which operation you like to perform...\n 1.isFull\n 2.isEmpty\n 3.insertAtFirst\n";
    cout<<" 4.insertAtLast\n 5.insertByPosition\n 6.deleteAtFirst\n 7.deleteAtLast\n ";
    cout<<"8.displayList\n 9.MakeListEmpty\n 10.searchAtFirst\n 11.searchAnElement\n 12.Exit\n ";
    cout<<"Enter your choice: ";
    cin>>option;
    {
      if(option==1){
      if( listOfDetails.isFull() == 1)
         cout<<"\n ~~ isFull ~~ \n List is full\n";
      else
         cout<<"\n ~~ isFull ~~ \n List is not full\n";
      }
      else if(option==2){
        if( listOfDetails.isEmpty() == 1)
           cout<<"\n ~~ isEmpty ~~ \n List is Empty\n";
        else
           cout<<"\n ~~ isEmpty ~~ \n List is not Empty\n";
      }
      else if (option==3) { 
         cout<<"\nEnter student's details to perform insertAtFirst operation( RollNo,Name,CGPA ):\n ";
         cin >> rollNo;
         cin >> name;cin >> cgpa;
         Student tempStudent;
         tempStudent.getDetails(rollNo,name,cgpa);
         if(listOfDetails.insertAtFirst(tempStudent)==1)
           cout<<"\n Successfully inserted at first\n";
         else
           cout<<"\n Insertion at first operation is failed because U exeeds the maximum\n";
     }
     else if(option==4){ 
       cout<<"\nEnter student's details to perform insertAtLast operation( RollNo,Name,CGPA ):\n ";
       cin >> rollNo;
       cin >> name;
       cin >> cgpa;
       Student tempStudent1;
       tempStudent1.getDetails(rollNo,name,cgpa);
       if(listOfDetails.insertAtLast(tempStudent1)==1)
          cout<<"\n Successfully inserted at last\n";
       else
         cout<<"\n Insertion at last operation is failed because U exeeds the maximum\n";
    }
    else if(option==5)
    { 
      cout<<"\nEnter student's details to perform insertByPosition operation( RollNo,Name,CGPA ):\n ";
      cin >> rollNo;
      cin >> name;
      cin >> cgpa;
      cout << "Enter At which position you like to insert\n";
      cin >> count;
      Student tempStudent2;
      tempStudent2.getDetails(rollNo,name,cgpa);
      int state=listOfDetails.insertByPos(tempStudent2,count);
      if(state==1)
         cout<<"\n Successfully inserted \n";
      else if(state==-2)
         cout<<"\n Given position is invalid\n";
      else
         cout<<"\n Insertion failed because U exeeds the maximum\n";
   }
   else if(option==6)
   { 
      if( listOfDetails.deleteAtFirst() == 1)
         cout<<"\n Successfully deleted at first\n";
      else
          cout<<"\n Deletion at first failed because list is empty\n";
   }
   else if(option==7)
   { 
     if( listOfDetails.deleteAtLast() == 1)
        cout<<"\n Successfully deleted at last\n";
     else
        cout<<"\n Deletion at last failed because list is empty\n";
   }
   else if(option==8)
   { 
   if( listOfDetails.displayList() == 1)
     cout<<"\n Successfully displayed\n";
   else
     cout<<"\n Operation failed because list is empty\n";
   }
   else if(option==9) 
   { 
      if( listOfDetails.makeListEmpty() == 1)
        cout<<"\n List is empty now\n";
      else
        cout<<"\n Operation failed\n";
   }
   else if(option==10)
   {
     if( listOfDetails.searchAtFirst() == 1)
        cout<<"\n Operation successful\n";
     else
        cout<<"\n Operation failed because list is empty\n";
   }
   else if(option==11)
   { 
      cout<<"\nEnter student's rollno to perform searchAnElement operation: ";
      cin >> rollNo;
      int index=listOfDetails.searchAnElt(rollNo);
      if(index == -2)
        cout<<"\n Element is not in the list \n";
      else if (index==-1 )
        cout<<"List is empty\n";
      else
      {
         cout<<"\n Element is present in position "<<index+1<<"\n";
      }
  }
  else if(option==12)
       cout<<"\n Thank you! \n\n";
  else
       cout<<"\n Enter a valid input\n";
  }
 }while(option != 12);
}
