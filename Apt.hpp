/******************************************************************************
** Program name: Apt.hpp
** Author: April Castaneda
** Date: 06.08.2019
** Description: Apt.hpp is the Apt class specification file.
******************************************************************************/
#ifndef APT_HPP
#define APT_HPP

#include "Space.hpp"

class Apt : public Space
{

	public:
		Apt();
		~Apt();

                virtual void setMonster();
                virtual void setItems();
                virtual void setFoundItem(Item*);
                virtual void setUseItem(Item*);

		virtual bool examineRoom(Character*&);

		bool battle(Character*&);
};
#endif

