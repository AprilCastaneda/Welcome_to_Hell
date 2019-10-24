/******************************************************************************
** Program name: Character.hpp
** Author: April Castaneda
** Date: 05.03.2019
** Description: Character.hpp is the Creature class specification file.
******************************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

// Character class declaration
class Character
{
	protected:
		int aDie, aSides,	// Attack number of die and sides
			dDie, dSides, 	// Defense number of die and sides
			armor,
			strength;
		string type, 
			name,
			team;
		bool quit;
	public:
		// Constructor with default values
		Character(int aDie=0, int aSides=0, int dDie=0, int dSides=0, int armor=0, int strength=0, string name="");

		// Constructor with three parameters
		Character(string team, string type, string name);	

		// Constructor with two parameters
		Character(string name);

		// Virtual destructor
		virtual ~Character() = default;

		// Setters
		void setADie(int aDie);
		void setASides(int aSides);
		void setDDie(int dDie);
		void setDSides(int dSides);
		void setArmor(int armor);
		void setStrength(int strength);
		void setTeam(string team);
		void setType(string type);
		void setName(string name);
		void setQuit(char);

		// Getters
		int getADie();
		int getASides();
		int getDDie();
		int getDSides();
		int getArmor();
		int getStrength();
		string getTeam();
		string getType();
		string getName();
		bool getQuit();

		// Function that rolls Die based on die number and sides
		int rollDie(int dieNum, int dieSides);

		// Function that recovers strength
		int recover(int strengthLoss);

		// Function that displays Character info
		void displayStats();

		// Virtual functions
		virtual int attack(int) = 0;
		virtual bool defense(int attackPow) = 0;
		virtual void displayType() = 0;
};
#endif
