#include<iostream>
using namespace std;
#include"sort.h"
#include"reverse.h"
int main()
{
  int ch,m;
  cout<<"\n          Welcome\n\n";
  cout<<"         Function Overloading \n";
  do
  {
    cout<<"MENU:\n";
    cout<<"  1. Sorting.\n";
    cout<<"  2. Reverse.\n";
    cout<<"  3. Exit.\n";
    cout<<"Enter a Choice:\n";
    cin>>ch;
    if(ch==1)
    {
       int ch1,n,i;
       cout<<"\n           Sorting   \n";
       do
       {
         cout<<"MENU:\n";
         cout<<"  1.  Integer\n";
         cout<<"  2.  Float\n";
         cout<<"  3.  Char\n";
         cout<<"  4.  Exit\n";
         cout<<"Enter The Option:\n";
         cin>>ch1;
         if(ch1==1)
         {         
               cout<<"Enter the no of elements:\n";
               cin>>m;
               int *arr = new int[m];
               int *b=new int[m];
               cout<<"Enter the element:\n";
               for(i=0;i<m;i++)
                    cin>>arr[i];
               b=Sort(arr,m);
                cout<<"Sort Indeger:\n";  
                for(i=0;i<m;i++)
                    cout<<b[i]<<"\n";
         }
         else if(ch1==2)
         {
              cout<<"Enter the no.of elements:\n";
      	      int s;
              cin>>s;
              float *flo = new float[s];
              float *c = new float[s];
              cout<<"Enter the element:\n";
              for(i=0;i<s;i++)
                    cin>>flo[i];
              c=Sort(flo,s);
              cout<<"Sort Float:\n"; 
              for(i=0;i<s;i++)
                cout<<c[i]<<"\n";
         }
         else if(ch1==3)
         {
             cout<<"Enter the no of elements:\n";
             cin>>n;
             char *chr = new char[n];
             char *d = new char[n];
             cout<<"Enter the element:\n";
             for(i=0;i<n;i++)
                   cin>>chr[i];
             d=Sort(chr,n);
             cout<<"Sort Character:\n";
             for(i=0;i<n;i++)
                  cout<<d[i]<<"\n";
         }
         else if(ch1==4);
         else
             cout<<"     Invalid Option\n"; 
       }while(ch1!=4);
    }
    else if(ch==2)
    {
      int ch3;
      cout<<"\n        Reverse  \n";
      do
      {
        cout<<"MENU:\n";
        cout<<"  1. Integer\n";
        cout<<"  2. String\n";
        cout<<"  3. Exit\n";
        cout<<"Enter The Option:\n";
        cin>>ch3;
        if(ch3==1)
        {
          cout<<"Enter The Number:\n";
          int e,o;
          cin>>e;
          o=Reverse(e);
          cout<<"Reverse:   "<<o<<"\n";
        }
        else if(ch3==2)
        {
          int n,j;
          cout<<"Enter the length:\n";
          cin>>n;
          char *str=new char[n+1];
          cout<<"Enter the String:\n";
          cin>>str;
          char *a=new char[n+1];
          a=Reverse(str,n);
          cout<<"reverse:\n";
          for(j=0;j<n;j++)
                cout<<a[j];
          cout<<"\n";
         }
         else if(ch3==3);
         else
            cout<<"     Invalid Option\n"; 
       }while(ch3!=3);     
    }
    else if(ch==3)
      cout<<"\n          Good Bye\n\n";
    else
      cout<<"\n        Enter correct input\n";
  }while(ch!=3);
      return 0;
}
