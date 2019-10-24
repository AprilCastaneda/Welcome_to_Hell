/******************************************************************************
** Program name: GrimReaper.cpp
** Author: April Castaneda
** Date: 06.10.2019
** Description: GrimReaper.cpp is the GrimReaper class implementation file.
**		GrimReaper class is a derived class of Character class.
******************************************************************************/
#include "GrimReaper.hpp"

#include <iostream>
using std::cout;
using std::endl;

/******************************************************************************
** Description: Constructor that sends default Grim Reaper values to Character.
**		Attack: 2d6, Defense: 2d6, Armor: 0, Strength: 12
******************************************************************************/
GrimReaper::GrimReaper(string name) : Character(2, 6, 2, 6, 0, 25, name)
{
}

/******************************************************************************
** Description: Function that determines how Grim Reaper attacks. Rolls die and
**		calculates damage done based on Character die rolls. Returns 
**		the value for damage done.
******************************************************************************/
int GrimReaper::attack(int scene)
{
	int dieValue = 0;	// Stores die value

	// Roll attack die
	dieValue = rollDie(aDie, aSides);

	// Display attack die value
	cout << "Grim Reaper attacks: " << dieValue << endl;

	return dieValue;
}

/******************************************************************************
** Description: Function that determines how Grim Reaper defends. Grim Reaper takes
**		parameter of attack power. Determines if it is an instant kill
**		attack(Glare) or a regular attack. If glare, strength is
**		depleted and Character dies. Else, calculates damage. This is
**		done by rolling a die with defense attributes. Then, using this
**		formula: damage = attackPow - defenseDie - armor. Then, this
**		damage is subtracted from Character's strength. Returns value
**		if Character is dead.
******************************************************************************/
bool GrimReaper::defense(int attackPow)
{
	int damage = 0; // Variable to calculate total damage
	int defense = 0;	// Variable to store defense die roll total
	bool dead = 0;		// Variable to store if Character is dead

	// Is attack an instant kill? (Glare from Medusa)
	if(attackPow == -1)
	{
		damage = strength;
	}
	else // Regular attack
	{
		defense = rollDie(dDie, dSides); // Roll die with defense attributes
		
		// Display defense die
		cout << "Grim Reaper defends: " << defense << endl;	
		
		// Calculate damage
		damage = attackPow - defense - armor;
	}

	// If damage is >= 0, subtract damage from strength
	if(damage >= 0)
	{
		strength -= damage;
	}

	// Return if Character is dead or not
	if(strength <= 0)
	{
		dead = 1;
	}	
	else // Character not dead
	{
		dead = 0;
	}
	
	return dead;
}

/******************************************************************************
** Description: Function that displays Character type.
******************************************************************************/
void GrimReaper::displayType()
{
	cout << "Grim Reaper";
}
