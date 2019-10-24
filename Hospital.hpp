/******************************************************************************
** Program name: Hospital.hpp
** Author: April Castaneda
** Date: 06.08.2019
** Description: Hospital.hpp is the Hospital class specification file.
******************************************************************************/
#ifndef HOSPITAL_HPP
#define HOSPITAL_HPP

#include "Space.hpp"

class Hospital : public Space
{

	public:
		Hospital();
		~Hospital();

                virtual void setMonster();
                virtual void setItems();
                virtual void setFoundItem(Item*);
                virtual void setUseItem(Item*);

		virtual bool examineRoom(Character*&);
	
		bool battle(Character*&);
};
#endif

