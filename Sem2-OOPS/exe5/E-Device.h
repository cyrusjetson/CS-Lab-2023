#include<iostream>
using namespace std;
class Electronic_Device
{
  int Id;
  float Price;
  char *Colour;
  char *Brand;
  int Storage_Capacity;

public:
  void SetId(int);
  int GetId();
  void SetPrice(float);
  float GetPrice();
  void SetColour(char*);
  char* GetColour();
  void SetBrand(char*);
  char* GetBrand();
  void SetStorage(int);
  int GetStorage();
  ~Electronic_Device();
  Electronic_Device(const Electronic_Device&);
  Electronic_Device();
  friend istream& operator>>(istream& myin,Electronic_Device&);
  friend ostream& operator<<(ostream& myout,Electronic_Device&);
  Electronic_Device operator+(Electronic_Device);
  friend Electronic_Device operator-(Electronic_Device,Electronic_Device);
  bool operator==(Electronic_Device);
  friend bool operator!=(Electronic_Device,Electronic_Device);
  Electronic_Device operator=(Electronic_Device);
  friend Electronic_Device operator++(Electronic_Device&);
  Electronic_Device operator++(int);
  char& operator[](int);
};
