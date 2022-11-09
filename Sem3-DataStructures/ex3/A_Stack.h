#include <string>
using namespace std;
class Student
{
  string name;
  int rollNo;
  float cgpa;
  public:
    Student();
    Student(string,int,float);
    Student operator=(Student);
    Student operator=(int);
    friend istream& operator>>(istream&,Student&);
    friend ostream& operator<<(ostream&,Student&);
};

class A_Stack
{
  Student *stackArr;
  int capacity;
  int top;
  public:
    A_Stack();
    A_Stack(Student*,int,int);
    A_Stack(const A_Stack&);
    ~A_Stack();
    int push(Student);
    Student pop();
    Student peak();
    int isFull();
    int isEmpty();
    int displayStack();
    int makeStackEmpty();
};
