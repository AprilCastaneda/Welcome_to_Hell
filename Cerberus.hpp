/******************************************************************************
** Program name: Cerberus.hpp
** Author: April Castaneda
** Date: 06.12.2019
** Description: Cerberus.hpp is the Cerberus class specification file. Cerberus
**		class is a derived class of Character class.
******************************************************************************/
#ifndef CERBERUS_HPP
#define CERBERUS_HPP

#include "Character.hpp"

// Cerberus class declaration
class Cerberus : public Character
{
	public:
		// Default Constructor
		Cerberus(string);

		// Virtual functions
		virtual int attack(int);
		virtual bool defense(int attackPow);
		virtual void displayType();
};
#endif
