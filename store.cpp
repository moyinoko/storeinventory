/*
Title:  store.cpp
	Author:  Moyinoluwa Ojo
	Date:  Friday, April 14, 2017
	Purpose:  Program to input and organize inventory
	

*/
#include "store.h"

int main()
{                        //variables arrays
	int choice;
	int curNumItems = 0;
	
	Item itemArray[arraySize];
	cout << "WELCOME TO AMAZON!" << endl << endl;
do
{	
	choice = menu();
	 switch (choice)
		{
            case 1: add(itemArray, curNumItems);
				break;
			case 2: printPopular(itemArray, curNumItems);
				break;
			case 3: printItems(itemArray, curNumItems);
				break;
			case 4: saveInventory(itemArray, curNumItems);
			cout << "Goodbye!";
				break;
			
        }
}while(choice !=4);
 cout << endl << endl;
	
	
	

	 
	
	
	

	

	return 0;
	
}
