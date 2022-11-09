#include"E-Device.h"
#include<string.h>
#include<iostream>
using namespace std;
void Electronic_Device::SetPrice(float x)
{
   Price= x;
}

float Electronic_Device::GetPrice()
{
    return Price;
}

void Electronic_Device::SetBrand(char *x)
{
     Brand=new char[strlen(x)+1];
     strcpy(Brand,x);

}

char* Electronic_Device::GetBrand()
{
   return Brand;
}

void Electronic_Device::SetColour(char *x)
{
   Colour=new char[strlen(x)+1];
   strcpy(Colour,x);
}

char* Electronic_Device::GetColour()
{
   return Colour;
}

void Electronic_Device::SetStorage(int x)
{
   Storage_Capacity=x;
}

int Electronic_Device::GetStorage()
{
   return Storage_Capacity;
}

void Electronic_Device::SetId(int x)
{
    Id=x;
}
int Electronic_Device::GetId()
{
   return Id;
}

Electronic_Device::~Electronic_Device()
{
delete[] Colour;
delete[] Brand;
}
Electronic_Device::Electronic_Device(const Electronic_Device& E)
{
Brand=new char[strlen(E.Brand)+1];
strcpy(Brand,E.Brand);
Id=E.Id;
Colour=new char[strlen(E.Colour)+1];
strcpy(Colour,E.Colour);
Storage_Capacity=E.Storage_Capacity;
Price=E.Price;
}

Electronic_Device :: Electronic_Device ()
{
Id=10002;
Price=20000000;
Storage_Capacity=63;
Colour=new char[10];
Brand=new char[10];
}

istream& operator>>(istream& myin,Electronic_Device& c)
{
  cout<<"\n\t-----Device detail entry-----\n";
  cout<<"\nEnter Id:";
  myin>>c.Id;
  cout<<"\nEnter Brand:";
  myin>>c.Brand;
  cout<<"\nEnter Storage capacity:";
  myin>>c.Storage_Capacity;
  cout<<"\nEnter Colour:";
  myin>>c.Colour;
  cout<<"\nEnter price:";
  myin>>c.Price;
  return myin;
}

ostream& operator<<(ostream& myout,Electronic_Device& e)
{
   myout<<"\n\nID: ";
   myout<<e.Id;
   myout<<"\nBrand Name: ";
   myout<<e.Brand;
   myout<<"\nColour:";
   myout<<e.Colour;
   myout<<"\nStorage Capacity: ";
   myout<<e.Storage_Capacity;
   myout<<"\nPrice: ";
   myout<<e.Price;
   myout<<"\n";
   return myout;   
}
 
Electronic_Device Electronic_Device::operator+(Electronic_Device e)
{
  Price=Price+e.Price;
  return *this;
}

Electronic_Device operator-(Electronic_Device e,Electronic_Device e1)
{
  e.Price=e.Price-e1.Price;
  return e;
}

bool Electronic_Device::operator==(Electronic_Device e)
{
  if(Price==e.Price&&Brand==e.Brand&&Colour==e.Colour&&Storage_Capacity==e.Storage_Capacity&&Id==e.Id)
   return true;
  return false;
}

bool operator!=(Electronic_Device e,Electronic_Device e1)
{
  if(e.Price!=e1.Price||e.Brand!=e1.Brand||e.Colour!=e1.Colour||e.Storage_Capacity!=e1.Storage_Capacity||e.Id!=e1.Id)
     return true;
   return false;
}

Electronic_Device Electronic_Device::operator=(Electronic_Device e)
{
  Price=e.Price;
  Brand=new char[strlen(e.Brand)+1];
  strcpy(Brand,e.Brand);
  Colour=new char[strlen(e.Colour)+1];
  strcpy(Colour,e.Colour);
  Storage_Capacity=e.Storage_Capacity;
  Id=e.Id;
  return *this;
}

Electronic_Device operator++(Electronic_Device& c)
{
   c.Price=c.Price+1;
   return c;
}

Electronic_Device Electronic_Device::operator++(int)
{
 
  Electronic_Device ans;
   ans.Id=Id;
  ans.Colour=new char[strlen(Colour)+1];
  strcpy(ans.Colour,Colour);
  ans.Brand=new char[strlen(Brand)+1];
  strcpy(ans.Brand,Brand);
  ans.Storage_Capacity=Storage_Capacity;
  ans.Price=Price;
  Price=Price+1;
  return ans;
}

char& Electronic_Device::operator[](int n)
{
  return Colour[n-1];
}
