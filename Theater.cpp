/******************************************************************************
** Program name: Theater.cpp
** Author: April Castaneda
** Date: 06.08.2019
** Description: Theater.cpp is the Theater class implementation file.
******************************************************************************/
#include "Theater.hpp"

/******************************************************************************
** Description: Constructr
******************************************************************************/
Theater::Theater() : Space()
{
	setCharName('R');
	setSpName("Theater");
	setMonster();
	setItems();
}

/******************************************************************************
** Description: Destructor
******************************************************************************/
Theater::~Theater()
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
void Theater::setMonster()
{
	monster = NULL;

	monster = new Audience("Audience");
}

/******************************************************************************
** Description: Sets items.
******************************************************************************/
void Theater::setItems()
{       
        setFoundItem(NULL);
        setUseItem(NULL);

        Item *tempFound = NULL;

        tempFound = new Item("Equip", "Bronze Medal");
        
	setFoundItem(tempFound);
}

/******************************************************************************
** Description: Setters
******************************************************************************/
void Theater::setFoundItem(Item* fItem){
        foundItem = fItem;
}

void Theater::setUseItem(Item* uItem){
        useItem = uItem;
}

/******************************************************************************
** Descripton: Unique function to examine room.
******************************************************************************/
bool Theater::examineRoom(Character* &player)
{
	bool playerWins = 0;

	// Text for if Monster hasn't been defeated yet
	if(monster != NULL){	// If Monster is not dead
		cout << "A buzzing starts in your ear. It's getting louder and ";
		cout << "louder.\nYou look up and see a boy in front of you.\n";
		cout << "He is bowing to an audience.\nThey are ";
		cout << "standing and clapping and screaming.\nHe looks familiar.. \n";
		cout << "You are in the wings of a stage.\nA girl waves at you from ";
		cout << "the other side of the theater.\nYou cannot see her face ";
		cout << "but her silhouette is clear.\nShe is wearing a halo and a ";
		cout << "ballerina's outfit.\nSandy Fetterman wore the same thing ";
		cout << "that day. Just like that day. That day. That day...\nYou start ";
		cout << "hyperventilating.\n\n\"No, no, no..\"\n\n Mrs. Chalmers ";
		cout << "whispers behind you, \"Are you ready?\"\n\n \"No, I'm.. ";
		cout << "\n\n She pushes you to the stage before you can answer.\n\n";
		cout << "..not.\"\n\nThe boy had already left and now, the ";
		cout << "spotlights shine on you.\n";
		cout << "The mic whinces, cutting through the silence.\nThey are all ";
		cout << "waiting for you. They are waiting for you to sing.\nAnd you ";
		cout << "know it because you remember this day.\nYou remember it well. ";
		cout << "Because this is... \n"; 
		
		// player vs monster, returns if player won
		playerWins = battle(player);

		// text for if player doesn't win
		if(!playerWins){
			cout << endl;
			cout << "They are jeering and laughing and booing at you.\n";
			cout << "You f**ked it up again like you did it before.\n";
			cout << "And just like before, the water starts pooling ";
			cout << "down your leg and you can't stop it.\n";
			cout << "This is why they called you PeeWee in the halls ";
			cout << "during all of sixth grade.\nThis is why you didn't ";
			cout << "have friends then.\nThis was the beginning -- the";
			cout << " beginning of the end." << endl;
			cout << endl;		

			return 0;	// Didn't get item
		}
		// text for if player wins
		else{
			cout << endl;
			cout << "You don't remember this part. Because this part ";
			cout << "never happened.\nThis part where the audience got ";
			cout << "up and clapped for you.\nThis part where they are ";
			cout << "smiling and cheering for you.\nThis part where they ";
			cout << "call your name and give you a bronze medal.\nThis ";
			cout << "never happened. But it is happening. Only in Hell." << endl;
			cout << endl;
	
			// Delete monster
			delete monster;
			monster=NULL;

			return 1;	// Got item
		}
	}
	// text for if monster had already been defeated
	else{
		cout << "The theater is empty. " << endl;
		return 0;
	}
}

/******************************************************************************
** Description: Player battles Monster
******************************************************************************/
bool Theater::battle(Character* &player)
{
	
        int attackPower = 0;    // Variable to store attack value
        int origStrengthA = 0;  // Save original strength points
        int origStrengthB = 0;  
        bool dead = 0;          // Determines if any Characters are dead

	// Characters fight until one is defeated
	// Display round information
	cout << endl;
	cout << "***************************************************\n";
	cout << "         The Third WORST DAY OF YOUR LIFE.         \n";
	cout << "		        FIGHT!                      \n";
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
			// Declare Winner
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
