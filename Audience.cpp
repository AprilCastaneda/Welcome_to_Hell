/******************************************************************************
** Program name: Audience.cpp
** Author: April Castaneda
** Date: 06.10.2019
** Description: Audience.cpp is the Audience class implementation file. Audience 
**		class is a derived class of Character class.
******************************************************************************/
#include "Audience.hpp"

#include <iostream>
using std::cout;
using std::endl;

/******************************************************************************
** Description: Constructor that sends default Audience values to Character.
**		Attack: 2d6, Defense: 1d6, Armor: 3, Strength: 8
******************************************************************************/
Audience::Audience(string name) : Character(2, 6, 1, 6, 3, 8, name)
{
}

/******************************************************************************
** Description: Function that determines how Audience attacks. Rolls die and
**		calculates damage done based on Character die rolls. Returns
**		the value for damage done.
******************************************************************************/
int Audience::attack(int)
{
	int dieValue = 0;	// Stores die value

	// Roll attack die
	dieValue = rollDie(aDie, aSides);

	// Display attack die value
	cout << "Audience boos and jeers at you: " << dieValue << endl;

	// Determine if Medusa uses Glare
	if(dieValue == 12)
	{
		dieValue = -1;	// Lets Characters know Glare is used
	}

	return dieValue;
}

/******************************************************************************
** Description: Function that determines how Audience defends. Audience takes 
**		parameter of attack power. Determines if it is an instant kill
**		attack(Glare) or a regular attack. If glare, strength is 
**		depleted and Character dies. Else, calculate damage. This is
**		done by rolling a die with defense attributes. Then, damage is
**		determined usin gthis formula: damage = attackPow - defenseDie
**		- armor. Then, this damage is subtracted from Character's 
**		strength. 
******************************************************************************/
bool Audience::defense(int attackPow)
{
	int damage = 0;	// Variable to calculate total damage
	int defense = 0;	// Variable to store defense die roll
	int dead = 0;	// Variable to determine if Character is dead

	// Is attack an instant kill? (Glare from Medusa)
	if(attackPow == -1)
	{
		damage = strength;
	}
	else // Regular attack
	{
		defense = rollDie(dDie, dSides); // Roll die with defense attributes
	
		// Display defense die
		cout << "Audience can't hear you because some of them are on their cellphones: " << defense << endl;

		// Calculate damage
		damage = attackPow - defense;
	
		// Calculate armor if damage greater than 0
		if(damage > 0)
		{
			damage -= armor;
		}
	}

	// Display total damage
	cout << "Audience actually likes what they're hearing: " << damage << endl;

	// If damage is >=0, subtract damage from strength
	if(damage >= 0)
	{
		strength -= damage;
	}
	
	// Did she die?
	if(strength <= 0)
	{
		dead = 1;
	}
	else	// Not dead
	{
		dead = 0;
	}

	return dead;
}

/******************************************************************************
** Description: Function that displays Character type.
******************************************************************************/
void Audience::displayType()
{
	cout << "Audience";
}
