#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Student 
{ 
  char name[20]; 
  int ID; 
  float cgpa;
  friend class BinHeap;
  public: 
    Student(); 
    Student(char*,int,float); 
    Student(const Student&); 
    int getID();
    void dispDetails(); 
}; 


class BinHeap
{
  public:
    BinHeap();
    int isEmpty();
    int isFull();
    int enqueue(Student);
    Student dequeue();
    Student findMin();
    int search(int);
    void display();
  private:
    Student *s;
    int capacity,hsize;
};
