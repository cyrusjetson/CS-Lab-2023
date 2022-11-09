#include <iostream>
using namespace std; 
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)  
{  
  int i, key, j;  
  for (i = 1; i < n; i++) 
  {
    key = arr[i];  
    j = i - 1;  
    /* Move elements of arr[0..i-1], that are  
    greater than key, to one position ahead of their current position */
    while (j >= 0 && arr[j] > key) 
    {  
      arr[j + 1] = arr[j];  
      j = j - 1;  
    }  
    arr[j + 1] = key;  
  }  
}

int main()  
{
  int arr[30],i,c;
  int count;
  cout<<"\n\t~~~~~ Insertion sort using C++ ~~~~~\n\nEnter no of elements U want to enter: ";
  cin>>count;
  cout<<"Enter numbers to perform insertion sort: ";
  for(c=0;c<count; c++)
  {
    cin>> arr[c];
  }  
  insertionSort(arr, count); 
  cout<<"\nSorted array:\n";
  for (i = 0; i < count; i++)  
    cout << arr[i] << " ";  
  cout << endl;
  return 0;  
}
