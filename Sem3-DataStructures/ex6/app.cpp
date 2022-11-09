#include"head.cpp"
int
main () 
{
  
string bookName;
  
int bookId, pages, price, ch, c = 1;
  
BST t;
  
while (c != 0)
    
    {
      
cout << "\n Enter 1 to add Book";
      
cout << "\n Enter 2 to search Book";
      
cout << "\n Enter 3 to find minimum";
      
cout << "\n Enter 4 to find maximum";
      
cout << "\n Enter 5 to delete Book";
      
cout << "\n Enter 6 to display Book details (inOrder)";
      
cout << "\n Enter 7 to display Book details (preOrder)";
      
cout << "\n Enter 8 to display Book details (postOrder)";
      
cout << "\n Enter 9 to exit";
      
cout << "\n Enter your choice : ";
      
cin >> ch;
      
switch (ch)
	
	{
	
case 1:
	  
	  {
	    
cout << "\n Enter the name of the book : ";
	    
cin >> bookName;
	    
cout << "\n Enter ID : ";
	    
cin >> bookId;
	    
cout << "\n Enter no.of Pages : ";
	    
cin >> pages;
	    
cout << "\n Enter the Price : ";
	    
cin >> price;
	    
TreeNode * newNode =
	      new TreeNode (bookName, bookId, pages, price);
	    
TreeNode * temp = t.getRoot ();
	    
int flag;
	    
flag = t.insert (temp, newNode);
	    
if (flag == 1)
	      
cout << "\n Insertion successfull";
	    
	    else
	      
cout << "\n Insertion not successfull";
	    
break;
	  
}
	
case 2:
	  
	  {
	    
int id;
	    
cout << "\n Enter the id of the Book to be searched : ";
	    
cin >> id;
	    
TreeNode * temp = t.getRoot ();
	    
if (temp != NULL)
	      
	      {
		
TreeNode * temp1 = t.search (temp, id);
		
if (temp1 != NULL)
		  
		  {
		    
BookStore * e = temp1->getBookStore (temp1);
		    
cout << "\n Name \t ID \t PAGES \t PRICE \n";
		    
e->dispDetails ();
		  
}
		
		else
		  
cout << "\n Book not present";
	      
}
	    
	    else
	      
cout << "\n Tree is Empty";
	    
break;
	  
}
	
case 3:
	  
	  {
	    
TreeNode * temp = t.getRoot ();
	    
if (temp != NULL)
	      
	      {
		
TreeNode * temp1 = t.findMin (temp);
		
BookStore * e = temp1->getBookStore (temp1);
		
cout << "\n Name \t ID \t PAGES \t PRICE \n";
		
e->dispDetails ();
	      
}
	    
	    else
	      
cout << "\n Tree is empty";
	    
break;
	  
}
	
case 4:
	  
	  {
	    
TreeNode *temp = t.getRoot ();
	    
if (temp != NULL)
	      
	      {
		
TreeNode *temp1 = t.findMax (temp);
		
BookStore *e = temp1->getBookStore (temp1);
		
cout << "\n Name \t ID \t PAGES \t PRICE \n";
		
e->dispDetails ();
	      
}
	    
	    else
	      
cout << "\n Tree is empty";
	    
break;
	  
}
	
case 5:
	  
	  {
	    
int id;
	    
cout << "\n Enter the id of the book to be deleted : ";
	    
cin >> id;
	    
TreeNode * temp = t.getRoot ();
	    
if (t.search (temp, id) != NULL)
	      
	      {
		
BookStore * temp1 = t.deleteBook (id);
		
cout << "\n Deletion is successfull";
		
cout << "\n Deleted Element is : ";
		
cout << "\n Name \t ID \t PAGES \t PRICE \n";
		
temp1->dispDetails ();
	      
}
	    
	    else
	      
cout << "\n Book not present";
	    
break;
	  
}
	
case 6:
	  
	  {
	    
TreeNode * temp = new TreeNode ();
	    
temp = t.getRoot ();
	    
if (temp != NULL)
	      
	      {
		
cout << "\n Name \t ID \t PAGES \t PRICE \n";
		
t.inOrder (temp);
	      
}
	    
	    else
	      
cout << "\n Tree is empty";
	    
break;
	  
}
	
case 7:
	  
	  {
	    
TreeNode * temp = new TreeNode ();
	    
temp = t.getRoot ();
	    
if (temp != NULL)
	      
	      {
		
cout << "\n Name \t ID \t PAGES \t PRICE \n";
		
t.preOrder (temp);
	      
}
	    
	    else
	      
cout << "\n Tree is empty";
	    
break;
	  
}
	
case 8:
	  
	  {
	    
TreeNode * temp = new TreeNode ();
	    
temp = t.getRoot ();
	    
if (temp != NULL)
	      
	      {
		
cout << "\n Name \t ID \t PAGES \t PRICE \n";
		
t.postOrder (temp);
	      
}
	    
	    else
	      
cout << "\n Tree is empty";
	    
break;
	  
}
	
case 9:
	  
exit (0);
	
}
    
}
  
return 0;

}

