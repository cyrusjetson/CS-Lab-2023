#include<string>
using namespace std;
class Student
{
  int rollNo;
  string name;
  float cgpa;
  public:
    friend class A_List;
    Student();
    Student(int,string,float);
    Student(const Student&);
    void getDetails(int,string,float);
    friend void display(Student);
};

class A_List
{
  Student *studentsArray;
  int capacity;
  int size;
  public:
    A_List();
    A_List(Student*,int,int);
    A_List(const A_List &);
    void setDetails(Student*,int,int);
    int isFull();
    int isEmpty();
    int insertAtFirst(Student);
    int insertAtLast(Student);
    int insertByPos(Student,int);
    int deleteAtFirst();
    int deleteAtLast();
    int displayList();
    int makeListEmpty();
    int searchAtFirst();
    int searchAnElt(int);
};
