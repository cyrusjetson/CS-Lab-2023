#include"E-Device.h"
#include<stdlib.h>
#include<iostream>
using namespace std;
int main()
{
  int ch,ch1,ch2,ch3,pos;
  Electronic_Device D1,D2,D3;
  do
  {
    cout<<"\n\t-------Operator Overloading--------\n";
    cout<<"\nMenu\n";
    cout<<"\n1.Unary Operations\n";
    cout<<"2.Binary Operations\n";
    cout<<"3.Assingnment Operation\n";
    cout<<"4.Subscript Operator\n";
    cout<<"5.Relational Operator\n";
    cout<<"6.Exit\n";
    cout<<"Enter your chioce\n";
    cin>>ch;
    switch(ch)
    {
       case 1: do
               {
               cout<<"\n\t-------Unary Operations-----\n";
               cout<<"\t-------Price Increment------\n";
               cout<<"\n1.Pre Increment\n";
               cout<<"2.Post Increment\n";
               cout<<"3.Exit\n";
               cout<<"Enter Your Choice:";
               cin>>ch1;
               switch(ch1)
                {
                 case 1:cout<<"\nEnter Device details\n";
                        cin>>D1;
                        D2=++D1;
                        cout<<"\nGiven device details\n";
                        cout<<D1;
                        cout<<"\n\tIncremented device details\n";
                        cout<<D2;
                        break;
                 case 2:cout<<"\nEnter Device details\n";
                        cin>>D1;
                        D2=D1++;
                        cout<<"\nGiven device details\n";
                        cout<<D1;
                        cout<<"\n\tIncremented device details\n";
                        cout<<D2;
                        break;
                 case 3:break;
                 default:cout<<"Enter valid choice\n";
                }        
               }while(ch1!=3);           
               break;

       case 2: do
               {
                 cout<<"\n\t-------Binary operations for price-------\n";
                 cout<<"1.Binary Addition\n";
                 cout<<"2.Binary subtraction\n";
                 cout<<"3.Exit\n";
                 cout<<"Enter your choice:";
                 cin>>ch2;
                 switch(ch2)
                 {
                   case 1: cout<<"\n\tBinary Addition\n";
                           cout<<"Enter device_1 details\n";
                           cin>>D1;
                           cout<<"Enter device_2 details\n";
                           cin>>D2;
                           D3=D1+D2;
                           cout<<D3;
                           break;
                   case 2: cout<<"\n\tBinary Substraction\n";
                           cout<<"\nEnter device_1 details\n";
                           cin>>D1;
                           cout<<"Enter device_2 details\n";
                           cin>>D2;
                           D3=D1-D2;
                           cout<<D3;
                           break;
                   case 3:break;
                    default: cout<<"Enter valid chioce\n";
                 }
                }while(ch2!=3);
                break;

       case 3: cout<<"\n\t-------Assignment Operator-------\n";
               cout<<"\nEnter the Details\n";
               cin>>D1;
               D2=D1;
               cout<<"\nAssigned details\n";
               cout<<D2;
               break;

       case 4: cout<<"\n\t-------Subscript Operator for colour-------\n";
               cout<<"\nEnter the Details\n";
               cin>>D1;
               cout<<"Enter position:";
               cin>>pos;
               cout<<D1[pos];
               break;

       case 5: do
               {
               cout<<"\n\t-------Relational Operator-------\n";
               cout<<"1.Equal operator\n2.Not equal operator\n3.Exit\n";
               cout<<"Enter your choice:";
               cin>>ch3;
               switch(ch3)
               {
                 case 1: bool a;
                         cout<<"\n-------Equal Operator-------\n";
                         cout<<"\nEnter device_1 details\n";
                         cin>>D1;
                         cout<<"Enter device_2 details\n";
                         cin>>D2;
                         a=D1==D2;
                         if(a==true) 
                           cout<<"\nGiven device details are equal\n";
                         else
                           cout<<"\nGiven device details are  not equal\n";
                         break;
                case 2:  bool b;
                         cout<<"\n-------Not Equal Operator-------\n";
                         cout<<"\nEnter device_1 details\n";
                         cin>>D1;
                         cout<<"Enter device_2 details\n";
                         cin>>D2;
                         if(D1!=D2)
                           cout<<"\nGiven device details are  not equal\n";
                         else
                           cout<<"\nGiven device details are equal\n";
                         break;
                 case 3: break;
                default: cout<<"Enter valid choice\n";
              }
              }while(ch3!=3);
              break;
      case 6: 
              return 0;
              break;
       default: cout<<"Enter valid choice\n";
    }
  }while(ch!=6);
  
}
