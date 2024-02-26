//Jeremiah Ibarra
//CS132
//Mr. MacKay
//Project 2
//11.07.2023
#include<iostream>
#include<fstream>

using namespace std;

#include "linkedlist.h"
#include "itemStruct.h"



int menuSelection;
int yN;
int runProgram = 1;


int main()
{
	List myInventory;
	ifstream input;
	input.open("inventory.txt");
	int count = 0;
	item temp;
	while (input >> temp)
	{
		myInventory.insert(temp, count);
		count++;

	}

	cout << "The current list is: " << endl << endl;
	myInventory.display(cout);
	


	while (runProgram == 1)
	{
		cout << endl << "Please choose from the following options:" << endl << endl;
		cout << "1. Display current inventory list in alphabetical order" << endl;
		cout << "2. Display current inventory list in reverse alphabetical order" << endl;
		cout << "3. Add item to inventory list" << endl;
		cout << "4. Delete item from inventory list" << endl;
		cout << "5. Update/Change info of existing item" << endl << endl;
		cout << "Enter corrisponding number to make your selction: ";
		cin >> menuSelection;
		cout << endl;

		if (menuSelection == 1)
		{
			cout << "The current inventory list in alphabetical order is: " << endl << endl;
			myInventory.selectionSort();
			myInventory.display(cout);

			cout << endl << endl << "Back to main menu?" << endl << "Enter 1 for yes or 2 for no: " << endl << endl;
			cin >> yN;
			if (yN == 1)
			{
				runProgram = 1;
			}
			if (yN == 2)
			{
				runProgram = 0;
			}

		}
		if (menuSelection == 2)
		{
			cout << "The current inventory list in reverse alphabetical order is: " << endl << endl;
			
			myInventory.reverse();
			myInventory.display(cout);
			cout << endl << endl << "Back to main menu?" << endl << "Enter 1 for yes or 2 for no: " << endl << endl;
			cin >> yN;
			if (yN == 1)
			{
				runProgram = 1;
			}
			if (yN == 2)
			{
				runProgram = 0;
			}

		}
		if (menuSelection == 3)
		{
			item newItem;
			cout << "In this order, please enter the new item's name, price, how many of each item you're adding, and the max possible stock (case sensitive): ";
			cin >> newItem.name >> newItem.price >> newItem.stock >> newItem.maxLevel;

			cout << endl << "your new item is: " << newItem << "has been added to the list." << endl;
			myInventory.insert(newItem, 0);

			cout << endl << endl << "Back to main menu?" << endl << "Enter 1 for yes or 2 for no: " << endl << endl;
			cin >> yN;
			if (yN == 1)
			{
				runProgram = 1;
			}
			if (yN == 2)
			{
				runProgram = 0;
			}
		}
		if (menuSelection == 4)
		{
			int erasePos;
			item deleteItem;
			cout << "What item would you like to delete?: ";
			cin >> deleteItem.name;
			erasePos = myInventory.search(deleteItem);
			if (erasePos != -1)
			{
				myInventory.erase(erasePos);
				cout << deleteItem.name << " has been deleted.";
			}
			else
			{
				cout << "that item is not on the list" << endl << "Go back to main menu to try again..";
			}


			cout << endl << endl << "Back to main menu?" << endl << "Enter 1 for yes or 2 for no: " << endl << endl;
			cin >> yN;
			if (yN == 1)
			{
				runProgram = 1;
			}
			if (yN == 2)
			{
				runProgram = 0;
			}
		}
		if (menuSelection == 5)
		{
			int updatePos;

			cout << "Enter in the name of the Item you would like to change (case sensetive): ";
			
			item updateItem;
			cin >> updateItem.name;
			updatePos = myInventory.search(updateItem);
			if (updatePos != -1)
			{
				item newItem;
				myInventory.erase(updatePos);

				cout << endl << "Seperated by spaces in this order, enter in updated" << endl << "name, price, current stock, and max stock posible for item: ";
				cin >> newItem.name >> newItem.price >> newItem.stock >> newItem.maxLevel;
				myInventory.insert(newItem, 0);

				cout << endl << endl << "Item has been updated.";
				


			}
			else
			{
				cout << "That item is not on the list";
			}

			cout << endl << endl << "Back to main menu?" << endl << "Enter 1 for yes or 2 for no: " << endl << endl;
			cin >> yN;
			if (yN == 1)
			{
				runProgram = 1;
			}
			if (yN == 2)
			{
				runProgram = 0;
			}
		}
		else if (menuSelection < 0 || menuSelection > 5)
		{
			cout << "Invalid Entry";
			cout << endl << endl << "Back to main menu?" << endl << "Enter 1 for yes or 2 for no: " << endl << endl;
			cin >> yN;
			if (yN == 1)
			{
				runProgram = 1;
			}
			if (yN == 2)
			{
				runProgram = 0;
			}
		}
	}

	cout << endl << "LET THIS BE THE HOUR WHEN WE DRAW SWORDS TOGETHER. FELL DEEDS AWAKE." << endl;
	cout << "NOW FOR WRATH, NOW FOR RUIN, AND THE RED DAWN. FORTH EORLINGAS!" << endl << endl;
	
	return 0;

}
