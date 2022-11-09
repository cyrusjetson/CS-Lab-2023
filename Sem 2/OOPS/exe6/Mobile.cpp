#include"E-Device.h"
#include"Mobile.h"
#include<string>
#include<iostream>
 using namespace std;

 Mobile :: Mobile()
 {
    noOfCam=0;
    refreshRate=0;
 }
Mobile :: Mobile(int x,char* y,char* z,int u,float p,int v,int w):Electronic_Device(x,y,z,u,p)
 {
    noOfCam=v;
    refreshRate=w;
 }
 Mobile :: Mobile(const Mobile& ref)
 {
    noOfCam=ref.noOfCam;
    refreshRate=ref.refreshRate;
 }

 float Mobile :: GST()
 {
    return (((noOfCam+refreshRate+Electronic_Device::getPrice())/100.0)*12.0);
 }
 void Mobile :: display()
  {
     Electronic_Device :: display();
     cout<<"Number of Cameras : ";
     cout<<noOfCam<<"\n";
     cout<<"Screen refresh rate is ";
     cout<<refreshRate<<" Hz"<<"\n";
  }
