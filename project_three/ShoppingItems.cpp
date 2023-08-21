#include "ShoppingItems.h"

void ShoppingItems::sortAlphabetically() {
	//sort the items in the groceryItems array alphabetically
	sort(groceryItems, groceryItems + arraySize);
}

void ShoppingItems::countRepeatWords() {
	int wordCount = 1;
	int nextItem = 1;

	for (int i = 0; i < arraySize; i++) {
		//stores 0 if the item at index 'i' is the same as the next index
		int isEqual = groceryItems[i].compare(groceryItems[nextItem]);
		if (isEqual == 0) {
			wordCount++;   //add to the counter for that word
		}
		else {
			//when no more instances of that word are found, add the name and total wordcount to the map
			countedItems.emplace(groceryItems[i], wordCount);
			wordCount = 1;                               //reset the word count
			mapNames[mapNamesCount] = groceryItems[i];   //add the word to mapNames array
			mapNamesCount++;                             //add to the amount of different names
		}
		//incriment counter by one for comparison to next item
		nextItem++;
	}
}

void ShoppingItems::backupData() {
	//open the file
	ofstream outFS;
	outFS.open("frequency.dat");

	if (outFS.is_open()) {
		//for loop for every item in the map
		for (int i = 0; i < countedItems.size(); i++) {
			//write every map name with it's value to the file
			outFS << mapNames[i] << " " << countedItems.at(mapNames[i]) << endl;
		}
		outFS << "-----------------------------------------------------";
	}
	outFS.close();
}

void ShoppingItems::buildGroceryList(string filename) {
	string word;
	ifstream inFS;
	int counter = 0;


	inFS.open(filename);
	//while file is open and we are not at the end of
	if (inFS.is_open()) {
		while (!inFS.eof()) {
			getline(inFS, word);           //get the line
			groceryItems[counter] = word;  //put line in array
			counter++;                     //increment counter
			arraySize++;                   //increment arraySize counter
		}
		inFS.close();
	}
	else {
		cout << "Could not open file";    //Error message if file can't be opened
	}

	//call these functions after grocery list array is filled
	sortAlphabetically();  //sort the array
	countRepeatWords();    //count the repeat words
	backupData();          //backup the data
	showMenu();            //display the menu for next options
}

void ShoppingItems::getWordCount() {
	string word;
	bool contains = false; 
	cout << "Please enter item: ";
	cin >> word;

	//loop through each item in the mapNames array to see if the word you entered is in the array
	for (int i = 0; i < mapNamesCount; i++) {
		if (mapNames[i].compare(word) == 0) {
			contains = true;
			break;
		}
	}
	//if the above loop finds the word in the array
	if (contains == true) {
		cout << word << " " << countedItems.at(word) << endl;  //show the number of occurences of the input word
	}
	//if the above loop does not find any instances of that word
	else {
		cout << "Word not found\n";   //show error message
	}
	//call the menu function again for next option
	showMenu();
}

void ShoppingItems::printNumberedList() {
	//loop throug the countedItems map
	for (int i = 0; i < countedItems.size(); i++) {
		//print each item in the map with its respective value
		cout << mapNames[i] << " " << countedItems.at(mapNames[i]) << endl;
	}
	//call the menu function again for next option
	showMenu();
}

void ShoppingItems::printSpecialCharacterList() {
	//loop through every item in the countedItems map
	for (int i = 0; i < countedItems.size(); i++) {
		//print the name of the item
		cout << mapNames[i] << " ";
		//Print same amount of asterisks for the value of the map key
		for (int j = 0; j < countedItems.at(mapNames[i]); j++) {
			cout << "*";
		}
		cout << endl;
	}
	//call the menu function again for next option
	showMenu();
}

void ShoppingItems::showMenu() {
	int input;
	cout << "---------------------------------------------------\n";
	cout << "Enter option : \n1: Enter Item Name to Search for.\n2: Print List with Item Frequencty \n3: Print List With Special Symbols For Item Count.\n4: Exit Program\n";
	cin >> input;      //store input
	if (input == 1) {
		//call function to find instances of a single word
		getWordCount();             
	}
	else if (input == 2) {
		//call function to print the list with the amount of each item
		printNumberedList();           
	}
	else if (input == 3) {
		//call function to print the list with the special characters
		printSpecialCharacterList();
	}
	else if (input == 4) {
		//exit program
		exit(0);
	}
	else {
		//if anything is pressed that is not on the menu, then show message & call the showMenu function again
		cout << "Please Enter Valid Option\n";
		showMenu();
	}
}