/******************************************************************************
** Program name: Item.hpp
** Author: April Castaneda
** Date: 06.10.2019
** Description: Item class specification file.
******************************************************************************/
#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
using std::string;

class Item
{
	private:
		string itemType;
		string itemName;
		bool used;
	public:
		Item(string, string);

		void setItemName(string);
		void setItemType(string);
		void setUsed(bool);

		string getItemType();
		string getItemName();
		bool getUsed();		
};
#endif
