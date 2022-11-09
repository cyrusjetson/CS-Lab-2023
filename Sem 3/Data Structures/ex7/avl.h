class Student
{ 
  char name[20]; 
  int ID; 
  float cgpa;
  friend class AVL;
  friend class AvlNode;
  public: 
    Student(); 
    Student(char*,int,float); 
    Student(const Student&); 
    void dispDetails(); 
}; 


class AvlNode
{
  public:
      AvlNode();
      AvlNode(char*,int,float);
      Student * getStudent(AvlNode *);
      int getId(AvlNode *);
  private:
      Student *b;
      AvlNode *left;
      AvlNode *right;
      int height;
      friend class AVL;
};

class AVL
{
   public:
        AVL();
        ~AVL();
        AvlNode * getRoot();
        int getBalance(AvlNode *);
        int findHeight(AvlNode *);
        void updateRoot(AvlNode *);
        AvlNode * LLRotate(AvlNode *);
        AvlNode * RRRotate(AvlNode *);
        AvlNode * LRRotate(AvlNode *);
        AvlNode * RLRotate(AvlNode *);
        AvlNode * insert(AvlNode *,AvlNode*);
        AvlNode * search(AvlNode *,int);
        void inOrder(AvlNode *);
        void preOrder(AvlNode *);
        void postOrder(AvlNode *);
 private:
        AvlNode *root;
};
