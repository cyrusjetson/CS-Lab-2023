 #include<string>
 #include<stdlib.h>
 #include"E-Device.h"
 #include"Lap.h"
 #include"Mobile.h"
 #include<typeinfo>
 #include<iostream>
 using namespace std;

 int main()
  {
     Electronic_Device *ptrElectronic_Device;
     int id,ch,cores,storage,noOfCam,refRate;
     char brand[20],colour[13];
     float screen,price;
     do
      { 
        cout<<"\n\t$$$$$$$$    -----Electronic_Device-----    $$$$$$$$$\n";
        cout<<"\nMenu:";
        cout<<"\n\t 1.Laptop details";
        cout<<"\n\t 2.Mobile details";
        cout<<"\n\t 3.Exit";
        cout<<"\n\t Enter choice :";
        cin>>ch;

        switch(ch)
          {
              case 1: cout<<"\n\t-----Laptop detail entry-----";
                       cout<<"\n\t( NOTE : GST for laptop is computed from 7%"<<"of the sum of no of cores,price and screen size )\n";
                      cout<<"\n Enter Id : ";
                      cin>>id;
                      cout<<"\n Enter Brand : ";
                      cin>>brand;
                      cout<<"\n Enter Colour : ";
                      cin>>colour;
                      cout<<"\n Enter storage capacity : ";
                      cin>>storage;
                      cout<<"\n Enter price : ";
                      cin>>price;
                      cout<<"\n Enter no of cores : ";
                      cin>>cores;
                      cout<<"\n Enter screen size in inches : ";
                      cin>>screen;

                      ptrElectronic_Device=new Lap(id,brand,colour,storage,price,cores,screen);
                      break;

              case 2: cout<<"\n\t-----Mobile detail entry-----";
                      cout<<"\n\t( NOTE : GST for mobile is computed from 12%"<<"of the sum of no of cameras,price and refresh rate )\n";
                      cout<<"\n Enter Id : ";
                      cin>>id;
                      cout<<"\n Enter Brand : ";
                      cin>>brand;
                      cout<<"\n Enter Colour : ";
                      cin>>colour;
                      cout<<"\n Enter storage capacity : ";
                      cin>>storage;
                      cout<<"\n Enter price : ";
                      cin>>price;
                      cout<<"\n Enter number of cameras :";
                      cin>>noOfCam;
                      cout<<"\n Enter refresh rate : ";
                      cin>>refRate;
 
                      ptrElectronic_Device=new Mobile(id,brand,colour,storage,price,noOfCam,refRate);
                      break;

            case 3:
                      exit(0);
                      break;

          }



    cout<<"\n GST Computation for device is : ";
    cout<<ptrElectronic_Device->GST()<<" rupees";
     cout<<"\n Type of user chosen  object is : "<<typeid(*ptrElectronic_Device).name();

     Lap *ptrLap=dynamic_cast<Lap*>(ptrElectronic_Device);
     if(ptrLap!=NULL)

       {  
          cout<<"\n\n\t---Given details---\n";
          ptrLap->display();

       }

     Mobile *ptrMobile=dynamic_cast<Mobile*>(ptrElectronic_Device);
      if(ptrMobile!=NULL)
        {
          cout<<"\n\n\t---Given details---\n";
          ptrMobile->display();
        }

    }while(1);
  }
