/******************************************************************************
** Program name: ExBoyfriend.hpp
** Author: April Castaneda
** Date: 06.10.2019
** Description: ExBoyfriend.hpp is the ExBoyfriend class specification file.
**		ExBoyfriend class is a derived class of Character class.
******************************************************************************/
#ifndef EXBOYFRIEND_HPP
#define EXBOYFRIEND_HPP

#include "Character.hpp"

// ExBoyfriend class declaration
class ExBoyfriend : public Character
{
	private:
		int lives;	// ExBoyfriend has two lives
	public:
		// Default Constructor
		ExBoyfriend(string);

		// Setter function
		void setLives(int lives);

		// Getter function
		int getLives();

		// Virtual functions
		virtual int attack(int);
		virtual bool defense(int attackPow);
		virtual void displayType();
};
#endif
