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

class A_Queue
{
  Student *queueArr;
  int capacity;
  int front;
  int rear;
  public:
    A_Queue();
    A_Queue(Student*,int,int,int);
    A_Queue(const A_Queue&);
    ~A_Queue();
    int enqueue(Student);
    Student dequeue();
    Student peak();
    Student recent();
    int isFull();
    int isEmpty();
    int size();
    int displayQueue();
    int makeQueueEmpty();
};
