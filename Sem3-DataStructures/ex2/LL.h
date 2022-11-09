#include<string>
using namespace std;
class Student
{
  string name;
  int rollNo;
  float cgpa;
  friend class Node;
  friend class A_List;
  public:
    void setDetails(string,int,float);
    string getName();
    int getRoll();
    float getCgpa();
};

class Node
{
   public:
     Student data;
     Node *next;
     Node();
     Node(string,int,float);
};

class L_List
{
  public:
    Node *first;
    L_List();
    bool isEmpty();
    bool insertAtFirst(Node *NewNode);
    bool insertAtLast(Node *NewNode);
    bool insertByPosition(int,Node *NewNode);
    bool deleteAtFirst();
    bool deleteAtLast();
    bool deleteByPosition(int);
    bool makeListEmpty();
    int getPositionOfElement(int);
    int displayAll();
};
