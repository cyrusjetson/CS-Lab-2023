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

class Node;
class L_Stack
{
  Node *top;
  public:
    L_Stack();
    L_Stack(Node*);
    L_Stack(const L_Stack&);
    ~L_Stack();
    int push(Node *newNode);
    int pop();
    int isEmpty();
    int peak();
    int makeStackEmpty();
    void displayStack();
};

class L_Queue
{
  Node *first;
  public:
    L_Queue();
    L_Queue(Node*);
    L_Queue(const L_Queue&);
    ~L_Queue();
    int enqueue(Node *newNode);
    int dequeue();
    int isEmpty();
    int peak();
    int recent();
    int makeQueueEmpty();
    void displayQueue();
};

class Node
{
  friend class L_Stack;
  friend class L_Queue;
  Student data;
  Node *next;
  public:
    Node();
    Node(Student,Node*);
    Node(const Node& ref);
    ~Node();
    void getDetails();
    void displayDetails();
};

