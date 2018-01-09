/*********************************************************************
** Author: John Yoon
** Description: [Class Interface] - A class 
List that utilizes the Item class in order to create a list that items
can be added to, and removed from. Furthermore, the current status of
the list can be displayed, by showing all the items added thus far,
and their respective information. Finally, the total cost of all the
items is calculated and also shown in the display.
*********************************************************************/

#ifndef LIST_HPP
#define LIST_HPP
#include "Item.hpp"
#include <string>

class List
{
	private:
		Item* *array;
		int count, size;
		void double_size();
		void remove_update(int);

		string name, unit;
		int quantity;
		double price, total;

		bool reject;
	public:
		List();
		void add();
		void remove();
		void display();
};
#endif