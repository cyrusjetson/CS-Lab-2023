#include"head.h"
int main()
{
  char name[20];
  int ID;
  float f;
  HashTable h;
  int ch=0;
  while(true)
  {
     cout<<"\n Enter 1 to insert a Student.";
     cout<<"\n Enter 2 to remove a Student.";
     cout<<"\n Enter 3 to search a Student by ID.";
     cout<<"\n Enter 4 to find an Student.";
     cout<<"\n Enter 5 to display Student details.";
     cout<<"\n Enter 6 to exit.";
     cout<<"\n Enter your option : ";
     cin>>ch;
     switch(ch)
     {
       case 1:
       {
         cout<<"\n Enter the name of the Student: ";
         cin>>name;
         cout<<" Enter ID: ";
         cin>>ID ;
         cout<<" Enter CGPA: ";
         cin>>f;
         Student s(name,ID,f);
         int temp=h.insert(s);
         if(temp==1)
            cout<<"\n Student inserted.";
         else if(temp== -1)
            cout<<"\n List is full.";
         else
            cout<<"\n Duplicate Student cannot be inserted.";
         break;
     }
     case 2:
     {
        int ID;
        cout<<"\n Enter the ID of the Student to be removed.";
        cin>>ID;
        int temp=h.remove(ID);
        if(temp == -1)
           cout<<"\n List is empty.\n";
        else if (temp == -2)
            cout<<"\n Student not found.";
        else
            cout<<"\n Student deleted.";
        break;
    }
    case 3:
    {
       int ID;
       cout<<"\n Enter the ID of the Student to be searched.";
       cin>>ID;
       int temp=h.search(ID);
       if(temp == -1)
          cout<<"\n List is empty.";
       else if (temp == -2)
          cout<<"\n Student not found.";
       else
          cout<<"\n Student found.";
       break;
   }
   case 4:
   {
      int ID;
      cout<<"\n Enter the ID of the Student to be searched.";
      cin>>ID;
      Student s=h.findElement(ID);
      if(s.getID() == 0)
        cout<<"\n Student not found.";
      else
      {
        cout<<"\n ID \t Name \t CGPA \n";
        s.dispDetails();
      }
      break;
   }
   case 5:
   {
      cout<<"\n ID \t Name \t CGPA\n";
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
