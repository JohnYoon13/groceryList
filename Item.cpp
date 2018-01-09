/*********************************************************************
** Author: John Yoon
** Description: [Class Implementation] - A class Item that
consists of a string called name, a string called unit, a double 
called price, and an int called quantity. It has get and set methods 
for each field, and a constructor that takes four parameters and 
passes them to the set methods. It has a default constructor that sets 
name and unit to "", price to  0.0 and quantity to 0.
*********************************************************************/

#include "Item.hpp"

Item::Item(string item_name, string item_unit, double item_price, int item_quantity)
{
	setName(item_name);
	setUnit(item_unit);
	setPrice(item_price);
	setQuantity(item_quantity);
}

Item::Item()
{
	setName("");
	setUnit("");
	setPrice(0.0);
	setQuantity(0);
}

/*********************************************************************
** Function: setName
** Description: Takes a string and sets it to name.
** Parameters: A string
*********************************************************************/
void Item::setName(string item_name)
{
	name = item_name;
}

/*********************************************************************
** Function: setUnit
** Description: Takes a string and sets it to unit.
** Parameters: A string
*********************************************************************/
void Item::setUnit(string item_unit)
{
	unit = item_unit;
}

/*********************************************************************
** Function: setPrice
** Description: Takes a double and sets it to price.
** Parameters: A double
*********************************************************************/
void Item::setPrice(double item_price)
{
	price = item_price;
}

/*********************************************************************
** Function: setQuantity
** Description: Takes an integer and sets it to quantity.
** Parameters: An integer
*********************************************************************/
void Item::setQuantity(int item_quantity)
{
	quantity = item_quantity;
}

/*********************************************************************
** Function: getName
** Description: Returns a string, name.
** Parameters: None
*********************************************************************/
string Item::getName()
{
	return name;
}

/*********************************************************************
** Function: getUnit
** Description: Returns a string, unit.
** Parameters: None
*********************************************************************/
string Item::getUnit()
{
	return unit;
}

/*********************************************************************
** Function: getPrice
** Description: Returns a double, price.
** Parameters: None
*********************************************************************/
double Item::getPrice()
{
	return price;
}

/*********************************************************************
** Function: getQuantity
** Description: Returns an integer, quantity.
** Parameters: None
*********************************************************************/
int Item::getQuantity()
{
	return quantity;
}