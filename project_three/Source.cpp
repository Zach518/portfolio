#include <iostream>
#include "ShoppingItems.h"

using namespace std;

int main() {

	//instatiate a shoppingitems object
	ShoppingItems list;

	//build the grocery list from the file
	list.buildGroceryList("CS210_Project_Three_Input_File.txt");

	return 0;
}