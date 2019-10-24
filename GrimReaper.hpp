/******************************************************************************
** Program name: GrimReaper.hpp
** Author: April Castaneda
** Date: 06.10.2019
** Description: GrimReaper.hpp is the GrimReaper class specification file.
**		GrimReaper class is a derived class of Character class.
******************************************************************************/
#ifndef GRIMREAPER_HPP
#define GRIMREAPER_HPP

#include "Character.hpp"

// Barbarian class declaration
class GrimReaper : public Character
{
	public:
		// Default Constructor
		GrimReaper(string);

		// Virtual functions
		virtual int attack(int);
		virtual bool defense(int attackPow);
		virtual void displayType();

};
#endif
