/******************************************************************************
** Program name: Player.cpp
** Author: April Castaneda
** Date: 06.11.2019
** Description: Player.cpp is the Vampire class implementation file. Vampire
**		class is a derived class of Character class.
******************************************************************************/
#include "Player.hpp"

#include <iostream>
using std::cout;
using std::endl;

/******************************************************************************
** Description: Constructor that sends default Vampire values to Character.
**		Attack: 1d12, Defense: 1d6, Armor: 1, Strength: 18
******************************************************************************/
Player::Player(string name) : Character(1, 12, 1, 6, 1, 18, name)
{
}

/******************************************************************************
** Description: Function that determines how Vampire attacks. Rolls die and 
**		calculates damage done based on Character die rolls. Returns
**		the value for damage done.
******************************************************************************/
int Player::attack(int scene)
{
	int dieValue = 0;	// Stores die value

	// Roll attack die
	dieValue = rollDie(aDie, aSides);

	return dieValue;
}

/******************************************************************************
** Description: Function that determines how Vampire defends. Vampire has a 50%
**		chance of Charm. So, Vampire rolls a random number between 1 or 
**		2. If 1, then attackPower is negated. Else, attack goes
**		goes through. Then, determine if attack is an instant kill
**		attack(Glare) or a regular attack. If glare, strength is
**		depleted and Character dies. Else, calculates damage. This is 
**		done by rolling a die with defense attributes. Then, damage is
**		determines using this formula: damage = attackPow - defenseDie
**		- armor. Then, this damage is subtracted from Character's
**		strength.
******************************************************************************/
bool Player::defense(int attackPow)
{
	int damage = 0;	// Variable to calculate total damage 
	int defense = 0; // Variable to store defense die roll
	int charm = 0;	// Variable to see if Charm is in effect
	int dead = 0;	// Variable to determine if Character is dead

	// Roll Charm die
	charm = rollDie(1, 4);
	
	// If Charm is in effect
	if(charm == 1)
	{
		if(attackPow == -1)
		{
			attackPow = 0;	// attackPow negates
			cout << "Audience was about to use Glare but You have ";
			cout << "Charmed opponent into not attacking." << endl;
		}
		else
		{
			attackPow = 0;	// attackPow negated
			cout << "You have Charmed opponent into not attacking." << endl;
		}
	}
	else // Charm not in effect
	{
		// Is attack an instant kill? (Glare from Medusa)
		if(attackPow == -1)
		{
			damage = strength;
			cout << "Audience has used Glare. You have peed your pants.";
			cout << " Instant kill!" << endl;
		}
		else // Regular attack
		{
			defense = rollDie(dDie, dSides); // Roll die with defense attributes
		
			// Calculate damage
			damage = attackPow - defense;

			// Calculate armor into damage if damage greater than 0
			if(damage > 0)
			{
				damage -= armor;
			}
		}
	}
	
	// If damage is >=0, subtract damage from strength
	if(damage >= 0)
	{
		strength -= damage;
	}

	// Did Vampire die?
	if(strength <= 0)
	{
		dead = 1;
	}
	else // Not dead
	{
		dead = 0;
	}

	return dead;
}

/******************************************************************************
** Description: Function that displays Character type.
******************************************************************************/
void Player::displayType()
{
	cout << "Player";
}
