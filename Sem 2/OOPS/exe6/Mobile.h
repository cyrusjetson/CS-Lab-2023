#include<string>
using namespace std;
class Mobile : public Electronic_Device

 {
   int noOfCam;
   int refreshRate;

   public:

      Mobile();
      Mobile(const  Mobile& ref);
      Mobile(int,char*,char*,int,float,int,int);
     float GST();
     void display();

 };
