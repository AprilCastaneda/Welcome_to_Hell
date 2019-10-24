/******************************************************************************
** Program name: Dungeon.cpp
** Author: April Castaneda
** Date: 06.08.2019
** Description: Dungeon.cpp is the Dungeon class specification file.
******************************************************************************/
#include "Dungeon.hpp"

/******************************************************************************
** Descriptoin: Constructor
******************************************************************************/
Dungeon::Dungeon(int dungeonChoice) : Space()
{
	setCharName('R');
	setSpName("Dungeon");
	setDungeonChoice(dungeonChoice);
	setMonster();
	setMenus();
	setItems();
}

/******************************************************************************
** Description: Destructor
******************************************************************************/
Dungeon::~Dungeon()
{
	if(menu1 != NULL)
		delete menu1;

	if(menu2 != NULL)
		delete menu2;

	if(menu3 != NULL)
		delete menu3;

	if(monster != NULL)
		delete monster;

	if(foundItem != NULL)
		delete foundItem;
	
	if(useItem != NULL)
		delete useItem;

}

/******************************************************************************
** Description: Setter
******************************************************************************/
void Dungeon::setDungeonChoice(int dungeonChoice){
	this->dungeonChoice = dungeonChoice;
}

/******************************************************************************
** Descrtiption: Sets Menu
******************************************************************************/
void Dungeon::setMenus()
{
	menu1 = menu2 = menu3 = NULL;

	// Menu for first dungeon
	if(dungeonChoice == 1){
		
		int MENU1ROWS = 1;
		int MENU2ROWS = 1;
		int MENU3ROWS = 2;
		
		// Set up menu1
		menu1 = new Menu(MENU1ROWS);
		menu1->populateArray(0, "Light the Torch? (y/n)");

		// Set up menu2
		menu2 = new Menu(MENU2ROWS);
		menu2->populateArray(0, "Approach the Grim Reaper? (y/n)");
	
		// Set up menu3
		menu3 = new Menu(MENU3ROWS);
		menu3->populateArray(0, "The Wall Map is the only thing left in this room.");
		menu3->populateArray(1, "Would you like to look at it? (y/n)");

	}
	// Menu for third dungeon
	else if(dungeonChoice == 3){
		
		int MENU1ROWS = 1;
		int MENU2ROWS = 1;
		
		// Set up menu4
		menu1 = new Menu(MENU1ROWS);
		menu1->populateArray(0, "Attack Cerberus while it's sleeping? (y/n)");
	
		// Set up menu5
		menu2 = new Menu(MENU2ROWS);
		menu2->populateArray(0, "Pet Cerberus? (y/n)");
	}
}

/******************************************************************************
** Description: Sets Monster
******************************************************************************/
void Dungeon::setMonster()
{
        monster = NULL;

	if(dungeonChoice == 3){
       		monster = new Cerberus("Cerberus");
	}
}

/******************************************************************************
** Description: Sets items.
******************************************************************************/
void Dungeon::setItems()
{
	setFoundItem(NULL);
	setUseItem(NULL);

	Item *tempFound = NULL;

	// Sets items in space based on which dungeon it is
	if(dungeonChoice == 1){
		tempFound = new Item("Equip", "Mini Map");
		setFoundItem(tempFound);
	}
	else if(dungeonChoice == 2){
		tempFound = new Item("Quest", "Silver Key");
		setFoundItem(tempFound);
	}
	else if(dungeonChoice == 3){
		tempFound = new Item("Quest", "Gold Key");
		setFoundItem(tempFound);
	}
	else if(dungeonChoice == 4){
		tempFound = new Item("Equip", "Fur Coat");
		setFoundItem(tempFound);
	}
}

/******************************************************************************
** Description: Setters
******************************************************************************/
void Dungeon::setFoundItem(Item* fItem){
	foundItem = fItem;
}

void Dungeon::setUseItem(Item* uItem){
	useItem = uItem;
}

/******************************************************************************
** Description: User interacts with dungeon based on dungeon choice.
******************************************************************************/
bool Dungeon::examineRoom(Character* &player)
{
	// If Dungeon #1 - first Dungeon
	if(dungeonChoice == 1){

		// Variables for room choices
		char choice1, 
			choice2,
			choice3;
		choice1 = choice2 = choice3 = ' ';
		
		// Sees if exit cannot be opened yet
		if(isObstructed('w')){

			cout << "\n\"Hey, is someone here?\"\n\nYou push ";
			cout << "yourself to the end of the bed and feel the wall behind your ";
			cout << "back.\nYou spread your ";
			cout << "arms, running your hands and fingers against ";
			cout << "the wall.\nThere is something...\n\n";
			
			cout << "You discover a torch on the wall." << endl << endl; // Torch

			// Loop until user chooses to talk to grim reaper and get item
			do{
				menu1->displayMenuYS();	
				choice1 = menu1->getYSInput();

				// If user lights torch
				if(choice1 == 'y'){

					Item *tempItem = getFoundItem();
					string name = tempItem->getItemName();

					cout << "\nThe dim glow from the torch spreads to the corners ";
					cout << "of the room.\nThe walls are grey and covered in ";
					cout << "grime.\nThere is a glint in the corner furthest ";
					cout << "from you.\nYou go towards it. Closer and closer.";
					cout << "\nIt moves.\nYou back away as something emerges from";
					cout << " the darkness -- a tall, hooded creature carrying a ";
					cout << "scythe.\nYou scream.\n\n";
					cout << "The creature moves to the wall near the torch.\n";
					cout << "It motions for you to come close.\n\n";			
					
					// Loop for user to approach grim reaper
					do{
						menu2->displayMenuYS();
						choice2 = menu2->getYSInput();

						if(choice2 == 'y'){ // User approaches grim reaper
							cout << "\nYou bravely move towards the Grim Reaper.\n";
							cout << "It taps its scythe at something on the wall.\n";
							cout << "You see that it is pointing at what seems to ";
							cout << "be a map.\nYou look closer.\n\n\n";
		
							showMap(); // Show wall map
		
							cout << "The Grim Reaper puts the blade of its scythe ";
							cout << "underneath the words \"24 hours\".\n";
							cout << "It cocks its head, or what seems to be its head ";
							cout << "to the side, seeming to ask if you understand.\n";
							cout << "\n\"What? I don't know what that means? What is this?\n";
							cout << "Hell? What the F**k?\"\n\n";
							cout << "The Grim Reaper repositions its scythe under ";
							cout << "your head, the blade cutting into your chin.";
							cout << "\n\n\"24 Hours. OK, I get it. I have 24 hours to ";
							cout << "get out of here!\"\n\nIt hands you a " << name << " and waves its ";
							cout << "arm behind it.\nLight seeps through as a door ";
							cout << "opens.\n";
							cout << "What is this? What if you try USING it?\n\n";
						
							setObstruction(' ');	// remove obstruction

							return 1;
						}
						else
						{	
							// If user doesn't want to get near grim reaper
							cout << "\nYou shrink away from the grim reaper.\n";
							cout << "\"How do I get out of here?\"\n";

							return 0;
						}	
					}
					while(choice2 != 'y');	// Loop until user chooses 'y'
				}	 
				else{
					cout << "You hear something shift close by but you cannot";
					cout << " see anything.";
	
					return 0;
				}
			}
			while(choice1 != 'y');	// Loop until user chooses 'y'

			cout << endl << endl;
		}
		else{	// Visits to Space that are not the first time

			menu3->displayMenuYS();
			choice3 = menu3->getYSInput();

			cout << endl;

			// sees if user wants to look at map on wall
			if(choice3 == 'y')	// Show user map
				showMap();

			return 0;
		}

		return 0;	// No item here
	}
	// 2nd dungeon - no monster - only item to be found
	else if(dungeonChoice == 2){
		
		Item* tempItem = getFoundItem();
		string name = tempItem->getItemName();
		
		cout << "You're in what used to be a jail cell. There are cobwebs ";
		cout << "and rats and something else... \nThere is a lump in the corner ";
		cout << "of the room.\nYou inch closer and find someone. Or what used ";
		cout << "to be someone.\nIt's a skeleton covered in rags.\n";
		
		// if item hasn't been taken yet
		if(!fItemGone){
			cout << "You take a closer look and see that it has ";
			cout << "something tucked in its hand. You find a " << name << "." << endl;
			return 1;
		}

		return 0;
	}
	// 3rd dungeon - cerberus monster - item to be found
	else if(dungeonChoice == 3){

		// checks if monster already died
		if(monster != NULL){
	
			char choice = ' ';
			bool playerWins = 0;
			
			Item* tempItem = getFoundItem();
			string name = tempItem->getItemName();

			// text for approaching cerberus
			cout << "\nIs that a train? Or a chainsaw?\nYou move closer to ";
			cout << "whatever is making that sound.\nIt seems to be coming ";
			cout << "this small hill.\nOr is it a hill?\nIt's hard to make ";
			cout << "out in the darkness so you move closer still.\nOne.more.step.";
			cout << "And you freeze.\nIt isn't a train or a chainsaw making ";
			cout << "that noise.\nIt is a giant, three-headed, sleeping dog.\n" << endl;
		
			// asks user if they want to fight cerberus
			menu1->displayMenuYS();
			choice = menu1->getYSInput();

			// user wants to fight cerberus
			if(choice == 'y'){
			
				// player vs cerberus, returns if player wins
				playerWins = battle(player);

				// player doesn't win text
				if(!playerWins){
					cout << "\nCerberus lunges at you and almost bites ";
					cout << "your head off.\nGood thing it's on a ";
					cout << "leash and cannot follow you out of this ";
					cout << "room.\n\n";

					return 0;	// no item gained
				}
				// player wins text
				else{
					cout << "\nYou are about to deal the final blow ";
					cout << "when Cerberus whines.\nThis monster ";
					cout << "of a dog seems now like any other ";
					cout << "dog as it puts its head on its paws ";
					cout << "and\nlooks at you with pleading eyes.\n\n";
					
					// if user wants to pet cerberus
					menu2->displayMenuYS();
					choice = menu2->getYSInput();

					// If user wants to pet cerberus
					if(choice == 'y'){
		
						cout << "\nYou gather the courage to put ";
						cout << "your hand in front of Cerberus' ";
						cout << "three heads.\nIt looks down at you ";
						cout << "and at first, you are frozen\nBut ";
						cout << "it nudges one of its heads on your palm ";
						cout << "and you decide to pet a monster.\n";
						cout << "Cerberus closes its eyes and pushes its ears for you to scratch.";
						cout << "\nIn doing so, it reveals a light ";
						cout << "coming from behind and ";
						cout << "a " << name;
						cout << " hanging on its neck.\n";					

						// cerberus moves and secret path south opens
						obstruction = ' ';	// remove obstruction
					
						return 1;	// item picked up
					}
					// User doesn't want to pet cerberus
					else{
						cout << "You notice that the creature has ";
						cout << "something from its neck.\nYou decide to get ";
						cout << "item before steering clear of the creature ";
						cout << "for good.\n\n";

						return 1;	// item picked up
					}

					// Delete Monster
					delete monster;
					monster = NULL;

					return 1;
				}

				return 0;
			}
			// user decides not to attack cerberus
			else{
				cout << "\nYou decide not to take your chances and back away ";
				cout << "slowly from the creature.\n\n";
				
				return 0;
			}

			return 0;
		}		
		// monster already defeated
		else{
			cout << "Cerberus sees you come in and decides to go back to sleep." << endl;
			return 0;
		}
	}
	// dungeon 4 - secret room - found item
	else if(dungeonChoice == 4){

		Item* tempItem = getFoundItem();
		string name = tempItem->getItemName();

		cout << "You wouldn't have found this place if you hadn't given a good boy a pet." << endl;
		cout << "You find a " << name << " on the floor." << endl;

		return 1;	// returns item picked up
	}

	return 0;		
}

/******************************************************************************
** Description: PLayer battles monster.
******************************************************************************/
bool Dungeon::battle(Character* &player)
{
        int attackPower = 0;    // Variable to store attack value
        int origStrengthA = 0;  // Save original strength points
        int origStrengthB = 0;
        bool dead = 0;          // Determines if any Characters are dead

        cout << endl;
        cout << "***************************************************\n";
        cout << "                       FIGHT!                      \n";
        cout << "***************************************************\n";
        cout << endl;

	// Store original strength
        origStrengthA = player->getStrength();
	cout << "player" << endl;
        origStrengthB = monster->getStrength();
	cout << "monster" << endl;

	// Display combatant's info
        cout << player->getName() << " (strength: " << player->getStrength() << ") VS " << monster->getName() << " (strength: " << monster->getStrength() << ")" << endl;
        cout << endl;

	// Fight to the death
	do
	{
		// Player attacks first
		attackPower = player->attack(1);

		// Monster defends
                dead = monster->defense(attackPower);
  		
		attackPower = 0;

		if(!dead)	// Keep fighting
		{
			// Monster attacks
			attackPower = monster->attack(1);
		
			// Player defends
                        dead = player->defense(attackPower);

                        attackPower = 0;
			
			if(dead){ 	// Monster dies

				// Declare winner
                                cout << monster->getName() << " defeated ";
                                cout << player->getName() << "!" << endl;
				
				// Recover strength
                                player->setStrength(origStrengthA);
                                monster->setStrength(origStrengthB);

				return 0;
			}
			else{	// Player wins
	
				// Declare winner
        	                cout << player->getName() << " defeated ";
	                        cout << monster->getName() << "!" << endl;

				// Recover strengt
	                        player->setStrength(origStrengthA);
        	                monster->setStrength(origStrengthB);

                	        return 1;
			}
		}
	}
	while(!dead);
	
	return 0;
}

/******************************************************************************
** Description: Prints wall map.
******************************************************************************/
void Dungeon::showMap(){

        char corner = '+';
        char wall = '|';
        char ceiling = '-';
        char floor = '-';
        char player = '*';
        char room = 'R';
        char exit = 'X';

        // Initialize display board
        for(int i = 0; i < 11; i++)
        	for(int j = 0; j < 11; j++)
                	displayBoard[i][j] = ' ';

	// Fill in board map
        displayBoard[0][2] = corner;
        displayBoard[0][3] = ceiling;
        displayBoard[0][4] = corner;
        displayBoard[0][6] = corner;
        displayBoard[0][7] = ceiling;
        displayBoard[0][8] = corner;

        displayBoard[1][2] = wall;
        displayBoard[1][3] = room;
        displayBoard[1][4] = wall;
        displayBoard[1][6] = wall;
        displayBoard[1][7] = room;
        displayBoard[1][8] = wall;

        displayBoard[2][0] = corner;
        displayBoard[2][1] = ceiling;
        displayBoard[2][2] = corner;
        displayBoard[2][4] = corner;
        displayBoard[2][5] = ceiling;
        displayBoard[2][6] = corner;
        displayBoard[2][8] = corner;
        displayBoard[2][9] = ceiling;
        displayBoard[2][10] = corner;

        displayBoard[3][0] = wall;
        displayBoard[3][9] = room;
        displayBoard[3][10] = wall;

        displayBoard[4][0] = corner;
        displayBoard[4][2] = corner;
        displayBoard[4][3] = floor;
        displayBoard[4][4] = corner;
        displayBoard[4][6] = corner;
        displayBoard[4][8] = corner;
        displayBoard[4][9] = floor;
        displayBoard[4][10] = corner;

        displayBoard[5][0] = wall;
        displayBoard[5][1] = exit;
        displayBoard[5][2] = wall;
        displayBoard[5][4] = wall;
        displayBoard[5][5] = room;
        displayBoard[5][6] = wall;
        displayBoard[5][8] = wall;

        displayBoard[6][0] = corner;
        displayBoard[6][1] = floor;
        displayBoard[6][2] = corner;
        displayBoard[6][4] = corner;
        displayBoard[6][5] = floor;
        displayBoard[6][6] = corner;
        displayBoard[6][8] = corner;
        displayBoard[6][9] = ceiling;
        displayBoard[6][10] = corner;

        displayBoard[7][6] = wall;
        displayBoard[7][9] = room;
        displayBoard[7][10] = wall;

        displayBoard[8][6] = corner;
        displayBoard[8][8] = corner;
        displayBoard[8][9] = floor;
        displayBoard[8][10] = corner;

        displayBoard[9][6] = wall;
        displayBoard[9][7] = player;
        displayBoard[9][8] = wall;

        displayBoard[10][6] = corner;
        displayBoard[10][7] = floor;
        displayBoard[10][8] = corner;

	// Display map and text
	cout << "WELCOME TO HELL!" << endl << endl;
	cout << "Visitation Hours: 24 hours max" << endl;
	cout << "Please vacate the premises prior to the allotted hours or be granted a permanent stay." << endl << endl;
	cout << "Please enjoy your visit." << endl << endl;
	
	// Print board
        for(int i = 0; i < 11; i++){
                for(int j = 0; j < 11; j++)
                        cout << displayBoard[i][j] << " ";
                cout << endl;
        }
        cout << endl << "LEGEND: R=Room X=Exit *=You are Here" << endl << endl << endl;
}
	
