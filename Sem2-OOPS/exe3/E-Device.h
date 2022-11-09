class Electronic_Device
{
float Price;
char* Brand;
char* Colour;
int Storage_Capacity;
int Id;
public:
void SetPrice(float);
float GetPrice();
void SetBrand(char*);
char* GetBrand();
void SetColour(char*);
char* GetColour();
void SetStorage(int);
int GetStorage();
void SetId(int);
int GetId();
Electronic_Device();
Electronic_Device(const Electronic_Device &);
~Electronic_Device();
};
