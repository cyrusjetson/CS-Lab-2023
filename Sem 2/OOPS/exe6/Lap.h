#include<string>
using namespace std;
class Lap : public Electronic_Device
{
    int cores;
    float screen;
 public :
     Lap();
     Lap(const Lap&);
     Lap(int a,char* b,char* c,int d,float p,int u,float v);
     void display();
     void read();
     float GST();
};
