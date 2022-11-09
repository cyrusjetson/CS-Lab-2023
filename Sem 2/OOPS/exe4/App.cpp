#include"E-Device.h"
#include<stdlib.h>
#include<iostream>
using namespace std;
int main()
{
int n,i,id,storage;
float price;
char a[20],colour[10];
cout<<"\n\t ---------Device Details-------";
cout<<"\nEnter Id to start\n";
cin>>id;
Electronic_Device::SetId(id);
cout<<"\nEnter how many Device\n";
cin>>n;
Electronic_Device e2;
Electronic_Device *e1=new Electronic_Device[n];
cout<<"\nEnter device details\n";
for(i=0;i<n;i++)
{
  cout<<"\nEnter brand name: \n";
  cin>>a;
  e1[i].SetBrand(a);
  cout<<"\nEnter the Price: ";
  cin>>price;
  e1[i].SetPrice(price);
  cout<<"\nEnter the colour: ";
  cin>>colour;
  e1[i].SetColour(colour);
  cout<<"\nEnter the storage capacity: ";
  cin>>storage;
  e1[i].SetStorage(storage);
}
int c,i1,i2,I;
char col[10];
do
 {  
    cout<<"\nDEVICE DETAILS\n";
    cout<<"\n\t----MENU----\n";
    cout<<"\n1.Enter the Device ID for Details\n";
    cout<<"2.Update the Device Colour\n";
    cout<<"3.Enter the ID to Copy\n";
    cout<<"4.Display All Details\n";
    cout<<"5.No of object created\n";
    cout<<"6.Current next Id\n";
    cout<<"7.Exit\n";
    cout<<"\nEnter your choice\n";
    cin>>c;
    switch(c)
    {
      case 1: cout<<"\nEnter the Device ID for Details\n";
              cin>>id;
              c=0;
              for( i=0;i<n;i++)
              { 
                 if(id==e1[i].GetId())
                 {
                  cout<<"\n\nID: ";
                  cout<<e1[i].GetId();
                  cout<<"\nBrand Name: ";
                  cout<<e1[i].GetBrand();
                  cout<<"\nColour: ";
                  cout<<e1[i].GetColour();
                  cout<<"\nStorage Capacity: ";
                  cout<<e1[i].GetStorage();
                  cout<<"\nPrice: ";
                  cout<<e1[i].GetPrice();
                  cout<<"\n";
                  c++;
                 }
              }
              if(c==0)
                  {
                             cout<<"\n   Id not found\n";
                     }
              break;
      case 2: cout<<"\nUpdate the Device Colour\n";
              cout<<"\nEnter the ID\n";
              cin>>I;
              for(i=0;i<n;i++)
              if(e1[i].GetId()==I)
              {
               cout<<"\nEnter the new device colour : ";
               cin>>col;
               e1[i].SetColour(col);
              }
              
              for( i=0;i<n;i++)
              {
                 if(I==e1[i].GetId())
                 {
                  cout<<"\n\nID: ";
                  cout<<e1[i].GetId();
                  cout<<"\nBrand Name: ";
                  cout<<e1[i].GetBrand();
                  cout<<"\nColour: ";
                  cout<<e1[i].GetColour();
                  cout<<"\nStorage Capacity: ";
                  cout<<e1[i].GetStorage();
                  cout<<"\nPrice: ";
                  cout<<e1[i].GetPrice();
                  cout<<"\n";
                  
                 }
               }
              break;
      case 3: cout<<"\nEnter the ID to Copy: ";
              cin>>i1;
              for(i=0;i<n;i++)
                if(e1[i].GetId()==i1)
                  e2=e1[i];
              for( i=0;i<n;i++)
              {
                 if(I==e1[i].GetId())
                 {
                  cout<<"\n\nID: ";
                  cout<<e1[i].GetId();
                  cout<<"\nBrand Name: ";
                  cout<<e1[i].GetBrand();
                  cout<<"\nColour: ";
                  cout<<e1[i].GetColour();
                  cout<<"\nStorage Capacity: ";
                  cout<<e1[i].GetStorage();
                  cout<<"\nPrice: ";
                  cout<<e1[i].GetPrice();
                  cout<<"\n";
                 }
               }        
             
              break;
      case 4: cout<<"\n\t----All Details-----\n";
              for( i=0;i<n;i++)
              {
                 cout<<"\n\nID: ";
                 cout<<e1[i].GetId();
                 cout<<"\nBrand Name: ";
                 cout<<e1[i].GetBrand();
                 cout<<"\nColour:";
                 cout<<e1[i].GetColour();
                 cout<<"\nStorage Capacity: ";
                 cout<<e1[i].GetStorage();
                 cout<<"\nPrice: ";
                 cout<<e1[i].GetPrice();
                 cout<<"\n";
              }
              break;
      case 5: cout<<"\n-------No of object created-------\n";
              cout<<Electronic_Device::noOfObjectCreated();
              cout<<"\n";
              break;
      case 6: cout<<"-------Current next Id-------\n";
              cout<<Electronic_Device::NextId();
              break;
      case 7:exit(0);
             break;
      default : cout<<"Enter valid choice\n";
   }
}while(c<=5);
}
