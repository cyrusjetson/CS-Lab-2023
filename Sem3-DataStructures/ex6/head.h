#include<iostream>
#include<stdlib.h>
using namespace std;

class BookStore 
{

public:
BookStore ();		// Default constructor
  BookStore (string, int, int, int);	// Parameterized constructor
  BookStore (const BookStore &);
  
ookStore ();		// Destructor
  void dispDetails ();		// To display the details of the employees
private:
string bookName;
  
int bookId, pages, price;
  
friend class BST;

};


class TreeNode 
{

public:
TreeNode ();
  
TreeNode (string, int, int, int);
  
TreeNode (const TreeNode &);
  
BookStore * getBookStore (TreeNode *);

private:
BookStore * e;
  
TreeNode * left;
  
TreeNode * right;
  
friend class BST;

};


class BST 
{

public:
BST ();
  
bool isEmpty ();
  
bool insert (TreeNode *, TreeNode *);
  
TreeNode * getRoot ();
  
void preOrder (TreeNode *);
  
void inOrder (TreeNode *);
  
void postOrder (TreeNode *);
  
TreeNode * search (TreeNode *, int);
  
TreeNode * findMin (TreeNode *);
  
TreeNode * findMax (TreeNode *);
  
BookStore * deleteBook (int);

private:
TreeNode * root;

};

