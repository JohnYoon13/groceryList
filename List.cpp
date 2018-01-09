/*********************************************************************
** Author: John Yoon
** Description: [Class Implementation] - A class 
List that utilizes the Item class in order to create a list that items
can be added to, and removed from. Furthermore, the current status of
the list can be displayed, by showing all the items added thus far,
and their respective information. Finally, the total cost of all the
items is calculated and also shown in the display.
*********************************************************************/

#include "List.hpp"
#include <iostream>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::getline;

List::List()
{	
	count = 0;
	size = 4;
	array = new Item*[4];	
}

/*********************************************************************
** Function: double_size
** Description: First updates the value of size by doubling the previous
value. Then uses a dynamic array that applies the aforementioned updated
size. Finally, updates each value in the array, and the new array is
assigned back under the name of array.
** Parameters: None
*********************************************************************/
void List::double_size()
{
	size *= 2;
	Item* *new_array = new Item*[size];

	for(int i = 0; i < count; i++)
	{
		new_array[i] = array[i];
	}

	array = new_array;
}

/*********************************************************************
** Function: remove_update
** Description: Updates the values within the array from a removal
by just shifting over each value. Then decrements count by one.
** Parameters: An integer
*********************************************************************/
void List::remove_update(int k)
{
	for(int i = k; i < count; i++)
	{
		array[i] = array[i + 1];
	}

	count--;
}

/*********************************************************************
** Function: add
** Description: Prompts the user for information regarding the Item,
such as the name, unit, price, and quantity. Takes that information and
the respective Item to add it to the List. The count is incremented by 
one, and if the count becomes equal to the size, then the double_size
function is applied. Takes into consideration invalid user inputs.
** Parameters: None
*********************************************************************/
void List::add()
{	
	
	do
	{	
		cout << "What is the name of the item?" << endl;
		getline(cin, name);
		bool reject = false;

		for(unsigned int i = 0; i < name.length() && reject == false; i++)
		{
			if(isalpha(name[i]))
				continue;

			if(name[i] == ' ')
				continue;

			reject = true;
		}

		if(reject == false)
			break;
		
	}while(reject == false);
	

	do
	{	
		cout << "What are the units (ounces, pounds, cans, etc.)?" << endl;
		getline(cin, unit);
		bool reject = false;

		for(unsigned int i = 0; i < unit.length() && reject == false; i++)
		{
			if(isalpha(unit[i]))
				continue;

			if(unit[i] == ' ')
				continue;

			reject = true;
		}

		if(reject == false)
			break;
	}while(reject == false); 
		


	cout << "How much does it cost, per unit?" << endl;
	cin >> price;	

	while((!cin) || (price <= 0))
	{	
		cout << "Invalid input, please try again: ";	
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> price;	
	}

	cout << "How many of the item do you want?" << endl;
	cin >> quantity;

	while((!cin) || (quantity <= 0))
	{	
		cout << "Invalid input, please try again: ";	
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> quantity;	
	}
	cout << '\n' << endl;


	if(count == size)
	{
		double_size();
	}

	array[count] = new Item(name, unit, price, quantity);
	count++;
}

/*********************************************************************
** Function: remove
** Description: Prompts the user for information regarding which Item
they wish to remove from the List. Takes the name of that item in order
to find the matching name in the array, so that the remove_update
function can be applied.
** Parameters: None
*********************************************************************/
void List::remove()
{
	do
	{	
		cout << "What item do you want to remove, by name?" << endl;
		getline(cin, name);
		bool reject = false;

		for(unsigned int i = 0; i < name.length() && reject == false; i++)
		{
			if(isalpha(name[i]))
				continue;

			if(name[i] == ' ')
				continue;

			reject = true;
		}

		if(reject == false)
			break;
		
	}while(reject == false);


	for(int i = 0; i < count; i++)
	{
		if(array[i]->getName() == name)
		{
			remove_update(i);
		}
	}
}

/*********************************************************************
** Function: display
** Description: Sets value of total to 0. Then retrieves and prints 
the complete current information regarding all Items on the List.
Furthermore, it calculates and prints each item's subtotal by
multipling the item's price by its quantity. Finally, the total is
calculated by adding up all the subtotal values, and the total is 
printed in a user-friendly format.
** Parameters: None
*********************************************************************/
void List::display()
{
	total = 0;

	for(int i = 0; i < count; i++)
	{
		cout << "NAME: " << array[i]->getName() << endl;
		cout << "UNITS: " << array[i]->getUnit() << endl;
		cout << "PRICE: " << array[i]->getPrice() << endl;
		cout << "QUANTITY: " << array[i]->getQuantity() << endl;
		cout << "SUBTOTAL: $" << array[i]->getPrice() * array[i]->getQuantity() << "\n" << endl;

		total += (array[i]->getPrice()) * (array[i]->getQuantity());
	}

	cout << "The TOTAL is $" << total << ".\n" << endl;
}

