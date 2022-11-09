#include"E-Device.h"
#include<string.h>
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
  Brand=new char[5];
  Id=0;
  Colour=new char[5];
  Storage_Capacity=0;
  Price=0;
}

