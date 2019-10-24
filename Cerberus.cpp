/******************************************************************************
** Program name: Cerberus.cpp
** Author: April Castaneda
** Date: 06.12.2019
** Description: Cerberus.cpp is the Cerberus class implementation file. Cerberus
**		class is a derived class of Character class.
******************************************************************************/
#include "Cerberus.hpp"

#include <iostream>
using std::cout;
using std::endl;

/******************************************************************************
** Description: Constructor that sends default Cerberus values to Character. 
**		Attack: 1d10, Defense: 2d6, Armor: 2, Strength: 12
******************************************************************************/
Cerberus::Cerberus(string name) : Character(1, 10, 2, 6, 3, 15, name)
{
}

/******************************************************************************
** Description: Function that determines how Cerberus attack. Rolls die and 
**		calculates damage done based on Character die rolls. Returns
**		the value for damage done.
******************************************************************************/
int Cerberus::attack(int scene)
{
	int dieValue = 0;	// Stores die value

	// Roll attack die
	dieValue = rollDie(aDie, aSides);

	// Display attack die value
	cout << "One of Cerberus's heads tries to take a bite: " << dieValue << endl;

	return dieValue;
}

/******************************************************************************
** Description: Function that determines how Cerberus defends. Cerberus take
**		parameter of attack power. Determines if it is an instant kill
**		attack(Glare) or a regular attack. If glare, strength is 
**		depleted and Character dies. Else, calculates damage. This is
**		done by rolling a die with defense attributes. Then, damage is
**		determined using this formula: damage = attackPow - defenseDie
**		- armor. Then, this damage is subtracted from Character's
**		strength. Also, for every four points of damage, Cerberus lose
**		one die. So the die mod is calculated as follows: dieMod = 
**		damage / 4; Then, if dieMod is greater than 0, dieMod is 
**		subtracted from dDie.
******************************************************************************/
bool Cerberus::defense(int attackPow)
{
	int damage = 0;	// Variable to calculate total damage
	int defense = 0;	// Variable to store defense die roll
	int dieMod = 0;		// Determines if dDie is modified
	int dead = 0;		// Variable to see if Character is dead

	// Is attack an instant kill? (Glare from Medusa)
	if(attackPow == -1)
	{
		damage = strength;
	}
	else	// Regular attack
	{
		defense = rollDie(dDie, dSides); // Roll die with defense attributes
	
		// Display defense die
		cout << "Cerberus defends: " << defense << endl;
	
		// Calculate damage
		damage = attackPow - defense;

		// Calculate armor into damage if damage greater than 0
		if(damage > 0)
		{
			damage -= armor;
		}
	}

	// If damage is >= 0, subtract damage from strength
	if(damage >= 0)
	{
		strength -= damage;
	}

	// Modify defense die based on strength 
	if((strength > 4) && (strength <= 8))
	{
		dieMod = 1;
	}
	else if((strength > 0) && (strength <= 4))
	{
		dieMod = 2;
	}
	
	// Subtract dieMod from dDie
	if(dieMod >= 1)
	{
		dDie -= dieMod;
	}

	// Return if Character is dead or not
	if(strength <= 0)
	{
		dead = 1;
	}
	else
	{
		dead = 0;
	}

	return dead;
}

/******************************************************************************
** Description: Function that displays Character type.
******************************************************************************/
void Cerberus::displayType()
{
	cout << "Cerberus";
}
