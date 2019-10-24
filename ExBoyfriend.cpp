/******************************************************************************
** Program name: ExBoyfriend.cpp
** Author: April Castaneda
** Date: 06.10.2019
** Description: ExBoyfriend.cpp is the ExBoyfriend class implementation file.
**		ExBoyfriend class is a derived class of Character class.
******************************************************************************/
#include "ExBoyfriend.hpp"

#include <iostream>
using std::cout;
using std::endl;

/******************************************************************************
** Description: Constructor that sends default HarryPotter values to Character.
**		Attack: 2d6, Defense: 2d6, Armor: 0, Strength: 10
******************************************************************************/
ExBoyfriend::ExBoyfriend(string name) : Character(2, 6, 2, 6, 0, 10, name)
{
	int lives = 2;
	setLives(lives);
}

/******************************************************************************
** Description: Setter function.
******************************************************************************/
void ExBoyfriend::setLives(int lives)
{
	this->lives = lives;
}

/******************************************************************************
** Description: Getter function.
******************************************************************************/
int ExBoyfriend::getLives()
{
	return lives;
}

/******************************************************************************
** Description: Function that determines how HarryPotter attacks. Rolls die and
**		calculates damage done based on Character die rolls. Returns
**		the value for damage done.
******************************************************************************/
int ExBoyfriend::attack(int scene)
{
	int dieValue = 0;	// Stores die value

	// Roll attack die
	dieValue = rollDie(aDie, aSides);

	// Display attack die value
	cout << "ExBoyfriend tells you he's leaving: " << dieValue << endl;

	return dieValue;
}

/******************************************************************************
** Description: Function that determines how HarryPotter defends. HarryPotter
**		takes parameter of attack power. Determines if it is an instant
**		kill attack(Glare) or a regular attack. If glare and lives is
**		greater than 1, turn strength into 20 and take away one of the
**		lives. If glare and lives is not greater than 1, then strength
**		is depleted and Character dies. Else, calculates damage. This
**		is done by rolling a die with defense attributes. Then, damage
**		is determined using this formula: damage = attackPow - 
**		defenseDie - armor. Then, this damage is subtracted from 
**		Character's strength. If damage is greater than or equal to 
**		strength, and lives are greater than 1, then strength is turned
**		into 20 and one of the lives is taken away. Otherwise,
**		Character not resurrected by Hogwarts.
******************************************************************************/
bool ExBoyfriend::defense(int attackPow)
{
	int damage = 0;	// Variable to calculate total damage
	int defense = 0;	// Variable to store defense die roll
	int dead = 0;	// Variable to determine if Character is dead

	// Is attack an instant kill? (Glare from Medusa)
	if(attackPow == -1)
	{
		// If Harry Potter has two lives, he uses Hogwarts and lives
		if(lives > 1)
		{
			damage = strength;
		}
		else // Instant kill
		{
			damage = strength;	
		}
	}
	else // Regular attack
	{
		defense = rollDie(dDie, dSides); // Roll die with defense attributes
	
		// Display defense die
		cout << "ExBoyfriend tells you what you want to hear: " << defense << endl;
	
		// Calculate damage
		damage = attackPow - defense - armor;
	}

	// If damage is >= 0, subtract damage from strength
	if(damage >= 0)
	{
		strength -= damage;
	}
	
	// Did he die?
	if(strength <= 0)
	{
		// If he has two lives, he uses Hogwarts and lives
		if(lives > 1)
		{
			strength = 20;	// Gives character MAX strength
			lives--;	// Take one of the lives
			cout << "ExBoyfriend decides to stay..." << endl;
			cout << "But wait! ExBoyfriend doesn't really know what he wants.\n";
			cout << "He threatens to leave again with double the strength!" << endl;
			dead = 0;
		}
		else
		{
			dead = 1;
		}
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
void ExBoyfriend::displayType()
{
	cout << "ExBoyfriend";
}
