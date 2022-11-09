#include <iostream>
#include<string.h>
using namespace std;
class Student
{
  char name[20];
  int ID;
  float cgpa; 
  public:
    Student();
    Student(char*,int,float);
    Student(const Student&);
    Student operator=(Student);
    Student operator=(int);
    bool operator==(Student);
    friend istream& operator>>(istream &,Student&);
    friend ostream& operator<<(ostream &,Student&);
    friend bool operator<(Student x,Student y);
    friend bool operator>(Student x,Student y);
};

class TreeNode
{
  friend class BST;
  Student data;
  TreeNode *left;
  TreeNode *right;
  public:
    TreeNode();
    TreeNode(Student,TreeNode*,TreeNode*);
    TreeNode(const TreeNode &);
    ~TreeNode();
};

class BST
{
  TreeNode *root;
  public:
    BST();
    BST(TreeNode*);
    BST(const BST&);
    ~BST();
    bool isEmpty();
    TreeNode* insertElt(TreeNode* newNode);
    TreeNode* deleteElt(Student Elt);
    Student search(Student);
    void inorder(TreeNode*);
    void preorder(TreeNode*);
    void postorder(TreeNode*);
    TreeNode* getRoot();
};
