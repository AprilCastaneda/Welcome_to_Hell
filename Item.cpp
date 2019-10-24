/******************************************************************************
** Program name: Item.cpp
** Author: April Castaneda
** Date: 06.10.2019
** Description: Item class implementation file.
******************************************************************************/
#include "Item.hpp"

/******************************************************************************
** Description: Constructor
******************************************************************************/
Item::Item(string itemType, string itemName)
{
	setItemType(itemType);
	setItemName(itemName);
	setUsed(0);
}

/******************************************************************************
** Description: Setter
******************************************************************************/
void Item::setItemType(string itemType)
{
	this->itemType = itemType;
}

void Item::setItemName(string itemName)
{
	this->itemName = itemName;
}

void Item::setUsed(bool used)
{
	this->used = used;
}

/******************************************************************************
** Description: Getter
******************************************************************************/
string Item::getItemType()
{
	return itemType;
}

string Item::getItemName()
{
	return itemName;
}

bool Item::getUsed()
{
	return used;
}
