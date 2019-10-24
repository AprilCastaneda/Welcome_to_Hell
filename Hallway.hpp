/******************************************************************************
** Program name: Hallway.hpp
** Author: April Castaneda
** Date: 06.08.2019
** Description: Hallway.hpp is the Hallway class specification file.
******************************************************************************/
#ifndef HALLWAY_HPP
#define HALLWAY_HPP

#include "Space.hpp"
#include "Menu.hpp"

class Hallway : public Space
{
	private:
		int hallwayChoice;
		Menu *menu1;
	public:
		Hallway();
		Hallway(int);
		~Hallway();

		void setHallwayChoice(int);
                virtual void setMonster();
		virtual void setItems();
                virtual void setFoundItem(Item*);
                virtual void setUseItem(Item*);
		void setMenu();

		int getHallwayChoice();
		
		virtual bool examineRoom(Character*&);
};
#endif

