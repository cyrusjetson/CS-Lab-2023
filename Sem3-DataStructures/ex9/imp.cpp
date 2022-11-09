#include"head.h"
Student::Student() 
{ 
  strcpy(name,"null"); 
  ID=0;
  cgpa=0; 
} 

Student::Student(char*d,int n,float f) 
{ 
  strcpy(name,d); 
  ID=n;
  cgpa=f;
} 

Student::Student(const Student &f) 
{ 
  strcpy(name,f.name); 
  ID=f.ID;
  cgpa=f.cgpa; 
}

int Student::getID()
{
  return ID;
}

void Student::dispDetails()
{
  cout<<ID<<"\t"<<name<<"\t"<<cgpa<<"\n";
}

HashTable :: HashTable()
{
  capacity =10;
  s= new Student[capacity];
  size =0;
}

int HashTable :: hash(int ID)
{
  return ID%10;
}

int HashTable::insert(Student emp)
{
	if(size==capacity)
		return -1;
	int hashval=hash(emp.getID());
	while(s[hashval].getID()!=0 && s[hashval].getID()!=emp.getID())
	{
		hashval=hash(hashval+1);
	}
	if(s[hashval].getID()==emp.getID())
		return -2;
	s[hashval]=emp;
	size++;
	return 1;
}

int HashTable::remove(int ID)
{
	if(size==0)
		return -1;
  int hashval=hash(ID);
  int flag=0;
  while(flag <= hashval)
  {
     if(s[hashval].getID()!=ID)
     {
         hashval=hash(hashval+1);
         flag++;
         continue;
     }
     else
     {
       s[hashval].~Student();
       return 1;
     }
  }
  return -2;
}

int HashTable::search(int ID)
{
  if(size==0)
    return -1;
  int hashval=hash(ID);
  int flag=1;
  while(flag <= hashval)
  {
    if(s[hashval].getID()!=ID)
    {
      hashval=hash(hashval+1);
      continue;
    }
    else
      return 1;
    flag++;
  }
  return -2;
}

Student HashTable::findElement(int ID)
{
  Student emp;
  if(size==0)
    return emp; 
  int hashval=hash(ID);
  int flag=1;
  while(flag <= hashval)
  {
    if(s[hashval].getID()!=ID)
    {
       hashval=hash(hashval+1);
       continue;
    }
    else
      return s[hashval]; 
    flag++;
  }
  return emp; 
}

void HashTable::display() 
{
  if(size==0)
    cout<<"No Students in the list\n";
  else
  { 
    int i;
    for(i=0;i<size;i++)
      s[i].dispDetails();
  }
}

