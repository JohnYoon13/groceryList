/*********************************************************************
** Author: John Yoon
** Description: Main function used to test the Item class
and the List class. Prompts the user to select from numbers 1 through 4
in order to either add to, remove from, display, or exit a grocery list.
*********************************************************************/

#include "List.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int user_input;
	List grocery;

	//Takes user input in order to decide which function to apply.
	//Potential invalid user inputs are taken into account.
	while(true)
	{
		cout << "ENTER 1 to add your item." << endl;
		cout << "ENTER 2 to remove your item." << endl;
		cout << "ENTER 3 to show what you have thus far." << endl;
		cout << "ENTER 4 if you are finished." << endl;
		cin >> user_input;


		switch(user_input)
		{
			case 1:
				cin.ignore();
				grocery.add();
				break;

			case 2:
				cin.ignore();
				grocery.remove();
				break;

			case 3:
				grocery.display();
				break;

			case 4:
				return 0;

			default:
				cout << "\nInvalid input. Please try again.\n" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
		}
	}

	return 0;
}