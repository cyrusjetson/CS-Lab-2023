#include"numericlib.h"
#include"arraylib.h"
#include<iostream>
using namespace std;
int main()
{
  int a,b,n,c,d;
  cout<<"\n~~~~~~WELCOME~~~~~~\n\n";
  do
  {
  cout<<"\nMenu:\n\n1.Numeric Operations\n2.Array Handling Operations\n3.Exit\n\n";
  cout<<"Enter your option\n";
  cin>>a;
  if(a==1)
  {
    cout<<"Enter the number\n\n";
    cin>>n;
    do
    {
      cout<<"\nMenu:\n\n1.Is Prime\n2.Find minimum digit\n3.Count digit\n4.Exit\n\n";
      cout<<"Enter your option\n";
      cin>>b;
      switch(b)
      {
        case 1:
          {
            c=Isprime(n);
            if(c==1)
                cout<<"Number is prime\n";
            else
                cout<<"Number is not prime\n";
            break;
          }
        case 2:
          {
            cout<<"Minimum digit is "<<Mindigit(n);
            cout<<"\n";
            break;
          }
        case 3:
          {
            cout<<"Count is "<<Count(n);
            cout<<"\n";
            break;
          }
        case 4:
          
            break;
       }
     }while(b!=4);
     
  }
  else if(a==2)
  {
    int num,i,*p;
    cout<<"\nEnter the number of elements\n";
    cin>>num;
    p=new int[num];
    cout<<"\nEnter elements\n";
    for(i=0;i<num;i++)
    {
            cin>>p[i];
    }
    do
    {
     cout<<"Menu:\n\n1.Find Max\n2.Find Occurence\n3.Sum of elements\n4.Exit\n\n";
     cout<<"Enter your option\n";
     cin>>b;
     switch(b)
     {
       case 1:
         {
           cout<<"Maximum value is "<<FindMax(p,num);
           cout<<"\n";
           break;
         }
       case 2:
         {
           int x;
           cout<<"Which number do you want to find occurance?\n";
           cin>>x;
           cout<<"The given number is in "<<Occu(p,num,x);
           cout<<" times\n";
           break;
         }
       case 3:
         {
           cout<<"Sum of the elements is "<<Sum(p,num);
           cout<<"\n";
           break;
         }
       case 4:
      
           break;
     }
    }while(b!=4);
  }
  }while(a!=3);

    return 0;
}
