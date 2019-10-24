/******************************************************************************
** Program name: Audience.hpp
** Author: April Castaneda
** Date: 06.10.2019
** Description: Audience.hpp is the Audience class specification file. Audience class
**		is a derived class of Character class.
******************************************************************************/
#ifndef AUDIENCE_HPP
#define AUDIENCE_HPP

#include "Character.hpp"

// Medusa class declaration
class Audience : public Character
{
	public:
		// Default Constructor
		Audience(string);

		// Virtual functions
		virtual int attack(int);
		virtual bool defense(int attackPow);
		virtual void displayType();
};
#endif
