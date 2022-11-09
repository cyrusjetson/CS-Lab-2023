#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class Student 
{ 
  char name[20]; 
  int ID; 
  int cgpa;
  friend class HashTable;
  public: 
    Student(); 
    Student(char*,int,float); 
    Student(const Student&); 
    int getID();
    void dispDetails(); 
};

class HashTable 
{
  public:
    HashTable();
    int hash(int); 
    int insert(Student); 
    int remove(int); 
    int search(int); 
    Student findElement(int); 
    void display(); 
  private:
    int capacity; 
    int size; 
    Student *s; 
};
