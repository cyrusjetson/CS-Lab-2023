#include"matrix.h"
#include"maximum.h"
#include<iostream>
using namespace std;
int main()
{
   int ch;
   cout<<"\n          Welcome \n\n";
   cout<<"       Default Argument\n";
   do
   {
      cout<<"MENU:\n";
      cout<<"   1. Find Maximum\n";
      cout<<"   2. Slice Matrix\n";
      cout<<"   3. Exit\n";
      cout<<"Enter your choice:\n";
      cin>>ch;
      if(ch==1)
      {
         int ch1,n,i;
         cout<<"\n        Find Maximum \n";
         cout<<"Enter the no of elements:\n";
         cin>>n;
         int *a=new int[n];
         cout<<"Enter the elements:\n";
         for(i=0;i<n;i++)
           cin>>a[i];
         do
         {
                cout<<"Menu:\n";
		cout<<"   1. With sign parameter\n";
		cout<<"   2. Without sign parameter\n";
		cout<<"   3. Exit\n";
		cout<<"Enter Your Option:\n";
		cin>>ch1;
		if(ch1==1)
		{
		   cout<<"\nThe Maximum:     ";
		   cout<<Maxwith(a,n)<<"\n";
		}
		else if(ch1==2)
		{
		   cout<<"\nThe Maximum:    ";
		   cout<<Maxout(a,n)<<"\n";
		}
	 }while(ch1!=3);
      }
      else if(ch==2)
      { int r,c;
        cout<<"\n          Slice Matrix\n";
        cout<<"Enter the no of rows\n";
        cin>>r;
        cout<<"Enter the no of coloums\n";
        cin>>c;
	int ch3,i,j;
        int **b=new int*[r];
        for(i=0;i<r;i++)
            b[i]=new int[c];
        cout<<"Enter the elements for matrix\n";
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                cin>>b[i][j];
        do
        {
	      cout<<"MENU:\n";
	      cout<<"    1. With rows and columns\n";
  	      cout<<"    2. With row only\n";
	      cout<<"    3. Without rows and columns\n";
	      cout<<"    4. Exit\n";
	      cout<<"Enter your Option:\n";
	      cin>>ch3;
	      if(ch3==3)
	      {
		cout<<"\nYour Matrix:"<<"\n";
                int **s=new int*[r];
                for(i=0;i<r;i++)
                      s[i]=new int[c]; 
                s=Slice(b);
                for(i=0;i<2;i++)
                {
                    for(j=0;j<2;j++)
                         cout<<" "<<s[i][j];
                    cout<<"\n";
                }
     	      }
	      else if(ch3==1)
	      {
                int r1,c1;
   		cout<<"Enter the row and column:\n";
                cin>>r1>>c1;
                int **s=new int*[r1];
                for(i=0;i<r1;i++)
                      s[i]=new int[c1];
                s=Slice(b,r1,c1);
                cout<<"\n";
                for(i=0;i<r1;i++)
                {
                    for(j=0;j<c1;j++)
                         cout<<" "<<s[i][j];
                    cout<<"\n";
                }
             }
             else if(ch3==2)
             {
		int r3;
		cout<<"Enter the Row:\n";
		cin>>r3;
		int **h=new int*[r3];
  		for(i=0;i<r3;i++)
		   h[i]=new int[c];
		h=Slice(b,r3);
		for(i=0;i<r3;i++)
		{
		    for(j=0;j<c;j++)
                          cout<<" "<<h[i][j];
                    cout<<"\n";
 		}
             }

	}while(ch3!=4);
      }
      else if(ch==3)
      {
         cout<<"\n     Good Bye \n";
      }
      else
      {
        cout<<"\n    Enter correct option \n";
      }
   }while(ch!=3);
}
