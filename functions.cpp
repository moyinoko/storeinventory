/*
Title:  functions.cpp
	Author:  Moyinoluwa Ojo
	Date:  Friday, April 14, 2017
	Purpose:  Program to input and organize inventory
	

*/
#include "store.h"





int menu()
{ 
  int choice;
  
  
  
  
   cout << "Please choose from the following options:";
   cout << "\n1.  Add new Amazon items(s).";
   cout << "\n2.  Print most popular item.";
   cout << "\n3.  Print all items.";
   cout <<"\n4. End the program." << endl << endl;
   cout <<"CHOOSE 1-4:  "; 
   cin >> choice;
   while (choice < 1 || choice > 4 || !cin)
   { cin.clear(); //this clears all bad flags that were thrown from the last read
    cin.ignore(numeric_limits<streamsize>::max(),'\n');  //clear the keyboard buffer

    cout << "Invalid number. Please input a number between 1 and 4:  ";
    cin >> choice;
  }
 
  
   
   return choice;
}
  
   int add(Item* itemArray, int &curNumItems)
  
  {
    if (curNumItems < 99) 
    { int y=curNumItems;
	  int counter;
	  int choice;
	  ifstream inFile;
	 char filename[26];
	 string numberReadFromFile; //use this when reading a number from the file
	 string horizontalLine(25,'-');
	 string tempString;
	char output[26];
     do
	 { 
	  
	  cout << "Do you want to.....";
	  cout << "\n1. Add items from a file?";
	  cout << "\n2. Add one item manually?";
	  cout << "\n3. Return to main menu?";
	  cout << "\nCHOOSE 1-3: ";
	  cin >> choice;
	  cin.ignore();
	  while (choice < 1 || choice > 3 || !cin)
     { cin.clear(); //this clears all bad flags that were thrown from the last read
      cin.ignore(numeric_limits<streamsize>::max(),'\n');  //clear the keyboard buffer

      cout << "Invalid number. Please input a number between 1 and 3;  ";
      cin >> choice;
	  cin.ignore();
  
     }
	 switch (choice)
	 { case 1:
			
	 
	 	 if(curNumItems =! 0)
		 {curNumItems++;
		 }
	
	 
	
	
	
	
	
	cout << "\n\nPlease enter the name of the file that contains your store data:  ";
	cin.getline(filename, 26);
	
	inFile.open(filename);
	if(inFile)
	{
		getline(inFile, tempString, '#');  
		
		while(!inFile.eof()) 
		{
			itemArray[curNumItems].Name = tempString; 
			getline(inFile, itemArray[curNumItems].Description, '#');  
			
			getline(inFile, numberReadFromFile, '#'); 
			itemArray[curNumItems].costs.goods_Price = stringToFloat(numberReadFromFile); 
			
			getline(inFile, numberReadFromFile, '#'); 
			itemArray[curNumItems].costs.sale_Price = stringToFloat(numberReadFromFile); 
			
			getline(inFile, numberReadFromFile, '#'); 
			itemArray[curNumItems].costs.profit = stringToFloat(numberReadFromFile); 
			for (int m=0; m < 12; m++)
			{getline(inFile, numberReadFromFile, '#'); 
		    itemArray[curNumItems].Popularity[m] = stringToInt(numberReadFromFile); 
			}
			getline(inFile, numberReadFromFile, '#'); 
			itemArray[curNumItems].dates.Month = stringToInt(numberReadFromFile); 
			
			getline(inFile, numberReadFromFile, '#'); 
			itemArray[curNumItems].dates.Day = stringToInt(numberReadFromFile); 
			
			getline(inFile, numberReadFromFile, '#'); 
			itemArray[curNumItems].dates.Year = stringToInt(numberReadFromFile); 
			
			curNumItems++; 
			counter++;
			getline(inFile, tempString, '#'); 
		}
		    cout << counter << " items have been added from "<< filename <<endl;
	        
				inFile.close();
	}
	else
	{
		cout << "File could not be opened.\n\n";
	}
	cout << endl;
	 	break;
	     
		
		case 2:
		
	if(curNumItems != 0)
			
	{curNumItems++;}
	else
		    
		cout << "\nPlease enter items details below:" << endl <<endl;
		cout << "\nName: ";
		getline(cin, itemArray[y].Name);
	    cout << "\nDESCRIPTION:  ";
	    getline(cin, itemArray[y].Description); 
        cout << "\nRETAIL OF PRICE OF GOODS (what store paid for it): ";
	    cin >> itemArray[y].costs.goods_Price;
	 while ((itemArray[y].costs.goods_Price < 0) || !cin)
     { cin.clear(); //this clears all bad flags that were thrown from the last read
      cin.ignore(numeric_limits<streamsize>::max(),'\n');  //clear the keyboard buffer

      cout << "Invalid number. Please input a number greater than 0  ";
      cin >>itemArray[y].costs.goods_Price;
	  cin.ignore();
  
     }
		cout << "\nSALE PRICE (what the store is selling it for): ";
	    cin >> itemArray[y].costs.sale_Price;
		 while ((itemArray[y].costs.sale_Price < 0) || !cin)
     { cin.clear(); //this clears all bad flags that were thrown from the last read
      cin.ignore(numeric_limits<streamsize>::max(),'\n');  //clear the keyboard buffer

      cout << "Invalid number. Please input a number greater than 0  ";
      cin >>itemArray[y].costs.sale_Price;
	  cin.ignore();
  
     }
		itemArray[y].costs.profit = itemArray[y].costs.sale_Price - itemArray[y].costs.goods_Price;
		cout << "\nENTER THE POPULARITY OF THE ITEMS FOR EACH MONTH. "
		<<"\n1 = unpopular and 10 = extremely popular"<< endl;
	    for(int i = 0; i < 12; i++)
		{
		cout <<"Month " << i+1<<" :";
		cin >> itemArray[y].Popularity[i];
		 while ((itemArray[y].Popularity[i] < 0) || (itemArray[y].Popularity[i] > 10) || !cin)
     { cin.clear(); //this clears all bad flags that were thrown from the last read
      cin.ignore(numeric_limits<streamsize>::max(),'\n');  //clear the keyboard buffer

      cout << "Invalid number. Please input a number greater than 0 and less than 10. " << endl;
      cout << "Month " << i+1<<" :";
	  cin >>itemArray[y].Popularity[i];
	  cin.ignore();
  
     }
		
		}
		cout << "ACQUIRE DATE (example: 04 02 16)"<<endl;
		cin >> itemArray[y].dates.Month
		
		 >> itemArray[y].dates.Day
		 >> itemArray[y].dates.Year;
		cin.ignore();
         		
	counter++;
    curNumItems++;	
 	break;
	
		case 3:
		  cout << "\nThere have been "<< counter<< " items added." << endl <<endl;
		 return counter;
		   
		   counter= 0;
	      
		  break;
	 }
      }while(choice != 3);
   }
   else{
   cout << "You have reached the item limit";}
	 }   
  
 void printPopular(Item* itemArray, int curNumItems)
   { 	
	if( curNumItems > 0) 
	{int location;
	
	 int popmonth;
	string horizontalLine(25,'-');
	cout << "What month would you like to investigate?";
	cin  >> popmonth; 
	cin.ignore();
	popmonth = (popmonth -1);
	cout << endl;
	

     int count;
     int highest;
     highest = itemArray[curNumItems].Popularity[popmonth];
     for (count = 0; count < curNumItems; count++)
     {
       if (itemArray[count].Popularity[popmonth] > highest)
	   {
		   highest = itemArray[count].Popularity[popmonth];
		  location = count; 
	   }
	 }
	cout << "\n The most popular item for Month " << (popmonth +1) << " is..."<< endl;
	 
	 cout << horizontalLine << endl;
			cout << right << setw(75)<<"Item "<<right << (location+1); 
			cout << "\nNAME:  " << itemArray[location].Name << endl;
			cout << "\nDESCRIPTION:  " << itemArray[location].Description << endl;
			cout << "\nGOODS PRICE: " << itemArray[location].costs.goods_Price << endl;
			cout << "\nSALE PRICE: " << itemArray[location].costs.sale_Price << endl;
			cout << "\nPROFIT: " << itemArray[location].costs.profit << endl;
			cout << "\nPOPULARITY PER MONTH:" <<endl;
			for(int c=0; c<12; c++)
			{
				cout << "\n\tMONTH " <<(c+1)<<"-"<< itemArray[location].Popularity[c];
			
			}
	       cout << endl << endl;
		   cout << "ACQUIRE DATE: " <<itemArray[location].dates.Month<<"/"
		   <<itemArray[location].dates.Day<<"/" << itemArray[location].dates.Year;
	}
	else{
		cout << "\n Input data first."<< endl << endl;
	}
    }
    void  printItems(Item* itemArray, int curNumItems)
    {
    	 
		string horizontalLine(25,'-');
		for(int x=0; x < curNumItems; x++)
		{
			cout << horizontalLine << endl;
			cout << right << setw(75)<<"Item "<<right << (x+1) << endl;
			cout << "\nNAME:  " << itemArray[x].Name << endl;
			cout << "\nDESCRIPTION:  " << itemArray[x].Description << endl;
			cout << "\nGOODS PRICE: " << itemArray[x].costs.goods_Price << endl;
			cout << "\nSALE PRICE: " << itemArray[x].costs.sale_Price << endl;
			cout << "\nPROFIT: " << itemArray[x].costs.profit << endl;
			cout << "\nPOPULARITY PER MONTH:" <<endl;
			for(int c=0; c<12; c++)
			{
				cout << "\n\tMONTH " <<(c+1)<<"-"<< itemArray[x].Popularity[c];
			
			}
	       cout << endl << endl;
		   cout << "ACQUIRE DATE: " <<itemArray[x].dates.Month<<"/"
		   <<itemArray[x].dates.Day<<"/" << itemArray[x].dates.Year <<endl;
	}
	
  
  
    }
  
  void saveInventory(Item* itemArray, int curNumItems)  
  {
	     	 
	  char output2[26];	
	cout << "What do you want to name your inventory file?" << endl;
		cin.ignore();
		cin.getline(output2, 26);
		fstream outFile(output2, ios::app);
		if (outFile)
		{
			for (int t=0; t < curNumItems; t++)
			{outFile << itemArray[t].Name <<"#";
		     outFile << itemArray[t].Description <<"#";
			 outFile << itemArray[t].costs.goods_Price <<"#";
			  outFile << itemArray[t].costs.sale_Price <<"#";
			   outFile << itemArray[t].costs.profit <<"#";
			 for (int q=0; q < 12; q++)
			 {outFile << itemArray[t].Popularity[q] <<"#";
			 }
			 outFile << itemArray[t].dates.Month <<"#";
			 outFile << itemArray[t].dates.Day <<"#";
			 outFile << itemArray[t].dates.Year <<"#";
		
		     }
		}
         else
             {
               cout << "File could not open.";
              }
	

	 
	outFile.close();
           cout << "All your files have been saved to "<<output2 << endl;
  }	  
	  float stringToFloat(string str)
	  {
		  float number;
		  char convertStr[1000];
		  strcpy(convertStr, str.c_str()); // convert the string to c-string
		  number = atof(convertStr);
		  return number;
	  }  
	  
	  	  int stringToInt(string str)
	  {
		  int number;
		  char convertStr[1000];
		  strcpy(convertStr, str.c_str()); // convert the string to c-string
		  number = atof(convertStr);
		  return number;
	  }  
	  

  

 