/******************************************************************************
** Program name: Apt.cpp
** Author: April Castaneda
** Date: 06.08.2019
** Description: Apt.cpp is the Apt class implementation file.
******************************************************************************/
#include "Apt.hpp"

/******************************************************************************
** Description: Constructr
******************************************************************************/
Apt::Apt() : Space()
{
	setCharName('R');
	setSpName("Apartment");
	setMonster();
	setItems();
}

/******************************************************************************
** Destructor
******************************************************************************/
Apt::~Apt()
{
	// Delete anything not == NULL
	if(monster != NULL)
		delete monster;

	if(foundItem != NULL)
		delete foundItem;

	if(useItem != NULL)
		delete useItem;
}

/******************************************************************************
** Description: Sets Monster
******************************************************************************/
void Apt::setMonster()
{
        monster = NULL;

        monster = new ExBoyfriend("Shitty Ex-Boyfriend");
}

/******************************************************************************
** Description: Sets items.
******************************************************************************/
void Apt::setItems()
{
        setFoundItem(NULL);
        setUseItem(NULL);

        Item *tempFound = NULL;

        tempFound = new Item("Equip", "Watch");
        
        setFoundItem(tempFound);
}

/******************************************************************************
** Description: Setters
******************************************************************************/
void Apt::setFoundItem(Item* fItem){
        foundItem = fItem;
}

void Apt::setUseItem(Item* uItem){
        useItem = uItem;
}

/******************************************************************************
** Descripton: Unique function to examine room.
******************************************************************************/
bool Apt::examineRoom(Character* &player)
{
	bool playerWins = 0;

	if(monster != NULL)	// Monster not dead
	{
		// Text for if Monster still lives in Space
		cout << "Your hands holds on to the siderail as you climb up ";
		cout << "the stairs.\nYou enter a one bedroom apartment, lit ";
		cout << "blue by the moonlight outside.\nHe is sitting on the ";
		cout << "couch.\nThat couch you found after six months of looking ";
		cout << "for a couch on craigslist, and ikea, and anywhere else ";
		cout << "you could.\nAnd you both found it at that secondhand ";
		cout << "vintage store on Highland --\nthe yelow one with the faded ";
		cout << "flowers that reminded you of your house when you were ";
		cout << "young.\nHe is sitting on it now, head in his hands.\n";
		cout << "He looks up when you arrive.\nHe's been waiting for you.";
		cout << "\nAnd you know he has.\nYou've relived this moment many ";
		cout << "times before. Because this is...\n";

		// Player vs Monster battle - returns if playerWins
		playerWins = battle(player);

		// Text for if player wins
		if(playerWins){

			cout << "\n\nHe says he made a mistake. He didn't know what ";
			cout << "he was saying. He didn't know what he was doing.\n\n";
			cout << "\"That girl was nothing to me. You're the one I ";
			cout << "want to be with. Please, stay. I love you.\"\n\n";
			cout << "This is not what really happened. But this is what ";
			cout << "you wanted.\nRight?\n\n";

			cout << "You look at the coffee table and find an old watch ";
			cout << "you'd given him for one of his birthdays.\n\n";

			// Delete monster
			delete monster;
			monster = NULL;
		
			return 1;	// Signals that player got item

		}
		// Text for if monster wins
		else{
			
			cout << "\n\nIt is happening again. He is ransacking the place.\n";
			cout << "He is taking his things out of the closet, out of the ";
			cout << "shelves.\nEverything you've built up together for the ";
			cout << "last two years are now on the floor.\nThe floor, where ";
			cout << "find yourself again. Just like last time.\n\n";

			return 0; 	// Signals that player didn't get item
	
		}

		return 0;
	}
	// Text for if Monster had already been defeated
	else{

		cout << "All that's here are the remnants of a shitty, old apartment.\n";

		return 0;

	}	

}

/******************************************************************************
** Description: Player battles monster.
******************************************************************************/
bool Apt::battle(Character* &player)
{
	
        int attackPower = 0;    // Variable to store attack value
        int origStrengthA = 0;  // Save original strength points
        int origStrengthB = 0;
        bool dead = 0;          // Determines if any Characters are dead

	// Display round info
        cout << endl;
        cout << "***************************************************\n";
        cout << "         The Second WORST DAY OF YOUR LIFE.        \n";
        cout << "                       FIGHT!                      \n";
        cout << "***************************************************\n";
        cout << endl;

	// Get original strength
        origStrengthA = player->getStrength();
        origStrengthB = monster->getStrength();

	// Display combatants' information
        cout << player->getName() << " (strength: " << player->getStrength() << ") VS " << monster->getName() << " (strength: " << monster->getStrength() << ")" << endl;
        cout << endl;

	// Characters fight to the death
        do
        {
		// Player attacks first
                attackPower = player->attack(1);

		// Monster defends
                dead = monster->defense(attackPower);

                attackPower = 0;

		if(!dead)	// If Monster doesn't die, round continues
		{
			// Monster attacks	
                        attackPower = monster->attack(1);

			// Player defends
                        dead = player->defense(attackPower);

                        attackPower = 0;

                        if(dead){	// Monster wins

				// Declare winner
                                cout << monster->getName() << " defeated ";
                                cout << player->getName() << "!" << endl;
	 	
				// Recover strength
                                player->setStrength(origStrengthA);
                                monster->setStrength(origStrengthB);

                                return 0;
                        }
                }
                else	// Player wins
                {
			// Declare winner
                        cout << player->getName() << " defeated ";
                        cout << monster->getName() << "!" << endl;

			// Recover strength
                        player->setStrength(origStrengthA);
                        monster->setStrength(origStrengthB);

                        return 1;
                }
        }
        while(!dead);

        return 0;
}
