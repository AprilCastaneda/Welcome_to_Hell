/******************************************************************************
** Program name: Player.hpp
** Author: April Castaneda
** Date: 06.10.2019
** Description: Player.hpp is the Player class specification file. Player
**		class is a derived class of Character class.
******************************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Character.hpp"

// Vampire class declaration
class Player : public Character
{
	public:
		// Default Constructor
		Player(string);

		// Virtual functions
		virtual int attack(int);
		virtual bool defense(int attackPow);
		virtual void displayType();

};
#endif
