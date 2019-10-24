/******************************************************************************
** Program name: Theater.hpp
** Author: April Castaneda
** Date: 06.08.2019
** Description: Theater.hpp is the Theater class specification file.
******************************************************************************/
#ifndef THEATER_HPP
#define THEATER_HPP

#include "Space.hpp"

class Theater : public Space
{

	public:
		Theater();
		~Theater();

		virtual void setMonster();
                virtual void setItems();
                virtual void setFoundItem(Item*);
                virtual void setUseItem(Item*);
		
		virtual bool examineRoom(Character*&);
		
		bool battle(Character*&);
};
#endif

