#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class Student
{
  	string name;
  	int rollNo;
  	float cgpa;
  public:
    Student();
    Student(int,string,float);
    Student(const Student &);
    ~Student();
    void dispDetails();
    friend class BST;
    void operator=(Student);
};

class TreeNode
{
  Student* s;
  TreeNode *left;
  TreeNode *right;
  public:
    TreeNode();
    TreeNode(Student*,TreeNode*,TreeNode*);
    TreeNode (const TreeNode &);
    Student * getStudent(TreeNode *);
    friend class BST;
};

class BST
{
   TreeNode* root;
   public: 
     BST();
     bool isEmpty();
     bool insert(TreeNode*,TreeNode*);
     TreeNode* getRoot();
     void preOrder(TreeNode*);
     void inOrder(TreeNode*);
     void postOrder(TreeNode*);
     TreeNode* search(TreeNode*,int);
     TreeNode* findMin(TreeNode*);
     TreeNode* findMax(TreeNode*);
     Student* deletecgpa(int);
};
