/*
	Title:  store.h
	Author:  Moyinoluwa Ojo
	Date:  Monday, April 10, 2017
	Purpose: To Organize and input Amazon inventory.
	
*/

#ifndef ARRAYHEADER_H
#define ARRAYHEADER_H
#include <iostream>
#include <string>
#include <limits>
#include <cstring>
#include<sstream>
#include<cstdlib>
#include <fstream>


#include <iomanip>
using namespace std;



const int arraySize = 100;


 struct Money
{
	float goods_Price;
	float sale_Price;
	float profit;
	
};

struct Date
{
	int Month;
	int Day;
	int Year;
};

struct Item
{
	string Name;
	string Description;
	Money costs;
	int Popularity[12];
	Date dates;
	
	
};
/* Allows users to add inventory through txt file or manually
*/
   int add(Item* itemArray, int &curNumItems); 
  /* Calls the menu for users to select commands
  */  
  int menu();
 /* Converts Strings to Floats*/  
  float stringToFloat(string str);
   /* Converts Floats to Ints */
   int stringToInt(string str);
/* Prints the most popular item for a selected period */  
  void printPopular(Item* itemArray, int curNumItems);
 /* Prints all items that have been added */ 
  void printItems(Item* itemArray, int curNumItems);
  /* Saves all inputed inventory into a textfile*/
  void saveInventory(Item* itemArray, int curNumItems);




#endif