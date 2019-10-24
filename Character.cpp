/******************************************************************************
** Program name: Character.cpp
** Author: April Castaneda
** Date: 05.03.2019
** Description: Character.cpp is the Creature class implementation file.
******************************************************************************/
#include "Character.hpp"

// https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
#include <random>	// To use random number engine

/******************************************************************************
** Description: Constructor with one parameter.
******************************************************************************/
Character::Character(int aDie, int aSides, int dDie, int dSides, int armor, int strength, string name)
{
	setADie(aDie);
	setASides(aSides);
	setDDie(dDie);
	setDSides(dSides);
	setArmor(armor);
	setStrength(strength);
	setName(name);
	setQuit(' ');
}

/******************************************************************************
** Description: Constructor with two parameters.
******************************************************************************/
Character::Character(string team, string type, string name)
{
	setADie(0);
	setASides(0);
	setDDie(0);
	setDSides(0);
	setArmor(0);
	setStrength(0);
	setTeam(team);
	setType(type);
	setName(name);
	setQuit(' ');
}

/******************************************************************************
** Description: Setter Functions.
******************************************************************************/
void Character::setADie(int aDie)
{
	this->aDie = aDie;
}

void Character::setASides(int aSides)
{
	this->aSides = aSides;
}

void Character::setDDie(int dDie)
{
	this->dDie = dDie;
}

void Character::setDSides(int dSides)
{
	this->dSides = dSides;
}

void Character::setArmor(int armor)
{
	this->armor = armor;
}

void Character::setStrength(int strength)
{
	this->strength = strength;
}

void Character::setTeam(string team)
{
	this->team = team;
}

void Character::setType(string type)
{
	this->type = type;
}

void Character::setName(string name)
{
	this->name = name;
}

void Character::setQuit(char choice)
{
	if(choice == 'q')
		quit = 1;
	else
		quit = 0;
}

/******************************************************************************
** Description: Getter Functions.
******************************************************************************/
int Character::getADie()
{
	return aDie;
}

int Character::getASides()
{
	return aSides;
}

int Character::getDDie()
{
	return dDie;
}

int Character::getDSides()
{
	return dSides;
}

int Character::getArmor()
{
	return armor;
}

int Character::getStrength()
{
	return strength;
}

string Character::getTeam()
{
	return team;
}

string Character::getType()
{
	return type;
}

string Character::getName()
{
	return name;
}

bool Character::getQuit()
{
	return quit;
}

/******************************************************************************
** Description: Function that rolls die based on die number and sides. Adds
**		results of die roll(s) and returns number.
******************************************************************************/
int Character::rollDie(int dieNum, int dieSides)
{
	int totalDieRoll = 0;	// Variable to store die rolls
	int randNum = 0;

	std::random_device seed;	// Will be used to obtain a seed for
					// the random number engine
	std::mt19937 gen(seed());	// Standard mersenne_twister_engine
					// seeded with seed()
	
	// Roll die / generate random number dieNum times
	for(int i = 0; i < dieNum; i++)
	{
		std::uniform_int_distribution<> dis(1, dieSides);

		// Assign generated random number to variable
		randNum = dis(gen);	

		// Add to accumulator	
		totalDieRoll += randNum;
	}

	return totalDieRoll;	// Return die roll(s)
}

/******************************************************************************
** Description: Function that recovers strength based on rollDie result.
******************************************************************************/
int Character::recover(int strengthLoss)
{
	int recovered = 0;

	// Only recover if strengthLoss is greater than 0
	if(strengthLoss > 0)
	{
		recovered = rollDie(1, strengthLoss);

		// Add recover points to strength
		strength += recovered;
	}

	return recovered;
}

/******************************************************************************
** Description: Function that displays Character's info.
******************************************************************************/
void Character::displayStats()
{
	cout << "STATS: Strength: " << strength << " Armor: " << armor;
	cout << " Intelligence: " << aDie << " Charisma: " << dDie << endl;
}

