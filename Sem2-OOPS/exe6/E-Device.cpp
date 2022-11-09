 #include"E-Device.h"
 #include<string>
 #include<string.h>
 #include<iostream>
 using namespace std;
 Electronic_Device ::  Electronic_Device()
  {
   Id=0;
   Brand='\0';
   Colour='\0';
   Storage_Capacity=0;
   Price=0;
   }


 Electronic_Device ::  Electronic_Device(int x,char* brand,char* colour,int storage,float price)
   {
     Id=x;
     Brand=new char[strlen(brand)+1];
     strcpy(Brand,brand);
     Colour=new char[strlen(colour)+1];
     strcpy(Colour,colour);
     Storage_Capacity=storage;
     Price=price;
   }

   Electronic_Device ::  Electronic_Device(const  Electronic_Device&ref)
 {
     Id=ref.Id;
     Brand=new char[strlen(ref.Brand)+1];
     strcpy(Brand,ref.Brand);
     Colour=new char[strlen(ref.Colour)+1];
     strcpy(Colour,ref.Colour);
     Storage_Capacity=ref.Storage_Capacity;
     Price=ref.Price;
   }
  Electronic_Device :: ~ Electronic_Device()
 {


 }

 void  Electronic_Device:: read()
 {
     cout<<"\n Enter id : ";
     cin>>Id;
     cout<<"\n Enter Brand : ";
     cin>>Brand;
     cout<<"\n Enter colour : ";
     cin>>Colour;
     cout<<"Enter storage capacity : ";
     cin>>Storage_Capacity;
     cout<<"\n Enter price : ";
     cin>>Price;
 }

void  Electronic_Device:: display()
 {    cout<<"\nId : ";
      cout<<Id<<"\n";
      cout<<"Brand : ";
      cout<<Brand<<"\n";
      cout<<"Colour : ";
      cout<<Colour<<"\n";
      cout<<"Storage capacity : ";
      cout<<Storage_Capacity<<"\n";
      cout<<"Price : ";
      cout<<Price<<"\n";
 }

float Electronic_Device:: getPrice()
{
 return Price;
}
