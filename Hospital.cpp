/******************************************************************************
** Program name: Hospital.cpp
** Author: April Castaneda
** Date: 06.08.2019
** Description: Hospital.cpp is the Hospital class implementation file.
******************************************************************************/
#include "Hospital.hpp"

/******************************************************************************
** Description: Constructr
******************************************************************************/
Hospital::Hospital() : Space()
{
	setCharName('R');
	setSpName("Hospital");
	setMonster();
	setItems();
}

/******************************************************************************
** Description: Destructor
******************************************************************************/
Hospital::~Hospital()
{
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
void Hospital::setMonster()
{
        monster = NULL;

        monster = new GrimReaper("Grim Reaper");
}

/******************************************************************************
** Description: Sets items.
******************************************************************************/
void Hospital::setItems()
{
        setFoundItem(NULL);
        setUseItem(NULL);

        Item *tempFound = NULL;

        tempFound = new Item("Equip", "Scythe");

        setFoundItem(tempFound);
}

/******************************************************************************
** Description: Setters
******************************************************************************/
void Hospital::setFoundItem(Item* fItem){
        foundItem = fItem;
}

void Hospital::setUseItem(Item* uItem){
        useItem = uItem;
}

/******************************************************************************
** Descripton: Unique function to examine room.
******************************************************************************/
bool Hospital::examineRoom(Character* &player)
{
	bool playerWins = 0;

	string name = foundItem->getItemName();

	// Text for if monster not defeated in space
	if(monster != NULL) // Monster not dead
	{
		cout << "\n\nYou hear a beeping beside you.\nThe walls are white.";
		cout << "The ceilings are white.\nEverything is so damn sterile ";
		cout << "and flourescent and...\nYou look down at your hand.\n";
		cout << "It is holding someone else's.\nIt looks so small, not like ";
		cout << "how it used to be.\nYou look at his face.\nHe is sleeping.\n";
		cout << "He was once so strong and powerfule and sometimes, frightening.\n";
		cout << "But now, you can see the outlines of the bones of his face ";
		cout << "underneath overstretched skin.\nThis is your father.\n";
		cout << "This was your father.\nYou know what's going to happen ";
		cout << "next.\nYou grab his hand harder as you see the beeping ";
		cout << "increase in speed.\nThe nurses and doctors run in to ";
		cout << "the room and push you aside.\nYou didn't see it before.\n";
		cout << "But now you see the creature walk behind the hospital ";
		cout << "staff --\nthe creature with black robes and a head full ";
		cout << "of darkness.\nThis is...\n\n";

		// player vs monster, returns if player won
		playerWins = battle(player);

		// Text for if player wins
		if(playerWins){

			cout << "\n\nThe creature backs away and out of the door.";
			cout << "\nThe beeping slows down and a nurse approaches ";
			cout << "you, a smile on her face.\n\n\"He's ok. He's going ";
			cout << "make it!\"\n\nYou are stunned as she embraces you.\n";
			cout << "\nThis isn't what happened.\n";
			cout << "You look to where the creature was and found that it ";
			cout << "has left a " << name << ".\n\n";

			// Delete Monster
			delete monster;
			monster = NULL;		

			return 1;	// signals that player found an item

		}
		// Text for if monster wins
		else{

			cout << "\n\nNo, No, No, Not again.\nYou try to get back ";
			cout << "to your Father but a nurse won't let you through.";
			cout << "\n\n\"Please ma'am, go back into the waiting room.\n\n";
			cout << "You hear the flat line as the nurse pushes you away ";
			cout << "from him.\nThat flat line that punctures you inside.\n";
			cout << "You already know what happens after this.\nNo one has to ";
			cout << "tell you twice.\n\n";
		
			return 0; // signals that player didn't find an item
		}
	}
	// Text for if monster had already been defeated
	else{

		cout << "\n\nThe hospital waiting room is filled with the hopeless and about ";
		cout << "to be deceased.\nYou don't want to be here.\n";
	
		return 0;

	}
}

/******************************************************************************
** Description: Player battles monster.
******************************************************************************/
bool Hospital::battle(Character* &player)
{

	int attackPower = 0;    // Variable to store attack value
        int origStrengthA = 0;  // Save original strength points
        int origStrengthB = 0;
        bool dead = 0;          // Determines if any Characters are dead

	// Display round info
        cout << endl;
        cout << "***************************************************\n";
        cout << "             The WORST DAY OF YOUR LIFE.           \n";
        cout << "                       FIGHT!                      \n";
        cout << "***************************************************\n";
        cout << endl;

	// Get original strength
        origStrengthA = player->getStrength();
        origStrengthB = monster->getStrength();

	// Display info
	cout << player->getName() << " (strength: " << player->getStrength() << ") VS " << monster->getName() << " (strength: " << monster->getStrength() << ")" << endl;
        cout << endl;

	// Characters fight to the death
        do
        {
                attackPower = player->attack(1);

                // Monster defends
                dead = monster->defense(attackPower);

                attackPower = 0;

                if(!dead)	// If Monster doesn't die, round continues
		{
			// Monster attacks, player defends
                        attackPower = monster->attack(1);

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
