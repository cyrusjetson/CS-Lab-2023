 #include"E-Device.h"
 #include"Lap.h"
 #include<iostream>
 using namespace std;

 Lap ::  Lap(int a,char* b,char* c,int d,float p,int u,float v):Electronic_Device(a,b,c,d,p)
  {
     cores=u;
    screen=v;
  }

  Lap ::  Lap()
 {
     cores=0;
     screen=0;
 }

  Lap ::  Lap(const  Lap& ref)
 {
     screen=ref.screen;
     cores=ref.cores;
 }

 void  Lap :: read()
  {
    Electronic_Device :: read();
    cout<<"\n Enter no.of cores : ";
    cin>>cores;
    cout<<"\n Enter screen size : ";
    cin>>screen;
  }

 void  Lap :: display()
  {
     Electronic_Device :: display();
     cout<<"No of cores : ";
     cout<<cores<<"\n";
     cout<<"Screen size : ";
     cout<<screen<<" inch"<<"\n";
  }

 float  Lap :: GST()
 {
   return (7.0*(cores+screen+Electronic_Device::getPrice())/100.0);
 }
