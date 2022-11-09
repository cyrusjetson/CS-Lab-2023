class Electronic_Device
{
int Id;
float Price;
char* Brand;
char* Colour;
int Storage_Capacity;
static int id;
static int noOfObject;
public:
int GetId();
void SetPrice(float);
float GetPrice();
void SetBrand(char*);
char* GetBrand();
void SetColour(char*);
char* GetColour();
void SetStorage(int);
int GetStorage();
static void SetId();
static void SetId(int);
static int noOfObjectCreated();
static int NextId();
Electronic_Device();
Electronic_Device(const Electronic_Device &);
~Electronic_Device();
};
