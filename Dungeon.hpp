/******************************************************************************
** Program name: Dungeon.hpp
** Author: April Castaneda
** Date: 06.08.2019
** Description: Dungeon.hpp is the Dungeon class specification file.
******************************************************************************/
#ifndef DUNGEON_HPP
#define DUNGEON_HPP

#include "Space.hpp"
#include "Menu.hpp"
#include "Item.hpp"

class Dungeon : public Space
{
	private:
		int dungeonChoice;
		char displayBoard[11][11]; // Wall map 
		Menu *menu1, *menu2, *menu3;
	public:
		Dungeon(int);
		~Dungeon();
                
		virtual void setMonster();
		virtual void setItems();
		virtual void setFoundItem(Item*);	
		virtual void setUseItem(Item*);
	
		void setDungeonChoice(int);
		void setMenus();

		virtual bool examineRoom(Character*&);
		bool battle(Character*&);
		void showMap();
};
#endif
