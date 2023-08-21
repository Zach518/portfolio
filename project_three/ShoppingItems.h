#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;

class ShoppingItems
{
	public:
		void buildGroceryList(string filename);       //create an array of each item in the file provided
		void sortAlphabetically();					  //sort each word alphabetically
		void countRepeatWords();                      //count the amount of repeat words by comparing it to the next item in the array
		void getWordCount();                          //get the count of the word you put in
		void printNumberedList();                     //print the number of times each item appears
		void printSpecialCharacterList();             //print the number of times each item appears with special characters
		void backupData();                            //output the counted numbers to a backupfile
		void showMenu();                              //display the menu
	private:
		string groceryItems[1000];       //array used to store the raw list of items
		map<string, int> countedItems;   //map used to store each type of item with the amount it appears
		string mapNames[1000];           //array used to store the name of each unique item in the map for comparison purposes
		int arraySize = 0;               //size of the groceryItems array for looping purpose
		int mapNamesCount = 0;           //size of the mapNames map for looping purpose
};

