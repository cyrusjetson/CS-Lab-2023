#include<string>
using namespace std;
class Electronic_Device
{
int Id;
char* Brand;
char* Colour;
int Storage_Capacity;
float Price;
public:
Electronic_Device(int,char*,char*,int,float);
Electronic_Device();
Electronic_Device(const Electronic_Device &);
~Electronic_Device();
void read();
void display();
float getPrice();
virtual float GST()=0;
};
