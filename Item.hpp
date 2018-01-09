/*********************************************************************
** Author: John Yoon
** Description: [Class Interface] - A class Item that
consists of a string called name, a string called unit, a double 
called price, and an int called quantity. It has get and set methods 
for each field, and a constructor that takes four parameters and 
passes them to the set methods. It has a default constructor that sets 
name and unit to "", price to  0.0 and quantity to 0.
*********************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>

using std::string;

class Item
{
	private:
		string name;
		string unit;
		double price;
		int quantity;
	public:
		Item(string, string, double, int);
		Item();
		void setName(string);
		void setUnit(string);
		void setPrice(double);
		void setQuantity(int);
		string getName();
		string getUnit();
		double getPrice();
		int getQuantity();
};
#endif