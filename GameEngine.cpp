/******************************************************************************
** Program name: GameEngine.cpp
** Author: April Castaneda
** Date: 05.23.2019
** Description: GameEngine class implementation file.
******************************************************************************/
#include "GameEngine.hpp"


/******************************************************************************
** Description: Default Constructor. Set all pointers to NULL.
******************************************************************************/
GameEngine::GameEngine()
{
	menu1 = NULL;
	menu2 = NULL;
}

/******************************************************************************
** Description: Destructor.
******************************************************************************/
GameEngine::~GameEngine()
{
	if(world != NULL)
		delete world;

	if(menu1 != NULL)
		delete menu1;

	if(menu2 != NULL)
		delete menu2;

	
}
/*****************************************************************************
** Description: Function#1 - runGame() runs menu1 and menu2.
******************************************************************************/
void GameEngine::runGame()
{
	buildWorld();	
	
	createMenus();	

	// Run first script
	runScript1();

	char menu1choice = ' ';

	// Run first menu
	menu1choice = runMenu1();

	// run until user quits
	while(menu1choice != 'q'){

		// Display mini map if user has equipped it
		world->displayMap();

		// Display time after user has gotten out of first room
		if(world->getTime() < 24)
			displayTime();
		
		// User has lost
		if(world->getTime() <= 0){
			cout << "You've run out of time!\nYou look down as ";
			cout << "shackles appear on your hands and feet.\n";
			cout << "The Grim Reaper leads you to the ";
			cout << "dungeons, forcing you to relive the worst ";
			cout << "days of your life FOR ALL ETERNITY.\n";
			menu1choice = 'q';
			break;
		}
		// Normal console display 
		else{
			world->displayAvailDirs();
			menu1choice = runMenu1();
		}
	}
}

/******************************************************************************
** Description: Function that creates World.
******************************************************************************/
void GameEngine::buildWorld()
{
	world = new Map;
}

/******************************************************************************
** Description: Run first script.
******************************************************************************/
void GameEngine::runScript1()
{
	cout << endl;
	cout << "You awaken in the darkness.\n\nThere is a throbbing pain ";
	cout << "spreading from the back of your head to your temples.\nYou ";
	cout << "reach to your right to feel your cellphone... It's not ";
	cout << "there.\nWhere is it? And the side table?\n";
	cout << "You hear something shuffle.\n\n";
}
/******************************************************************************
** Description: Function#2 = createMenus() creates menu1 and menu2.
******************************************************************************/
void GameEngine::createMenus()
{
	const int MENU1_ROWS = 1;
	const int MENU2_ROWS = 1;
	
	// MENU 1
	// Dynamically allocate menu1
	menu1 = new Menu(MENU1_ROWS);

	// Populate menu1
	menu1->populateArray(0, "EXAMINE: r(room) | MOVE: w(up), a(left), s(down), d(right) | ITEMS: i(inv/stats), u(use) | QUIT: q");
	
	// MENU 2
	// Dynamically allocate menu2 - item use
	menu2 = new Menu(MENU2_ROWS, 1, 4);

	// Populate menu2
	menu2->populateArray(0, "Which Item would you like to use? (1-4)");
}

/******************************************************************************
** Description: Function that runs menu1.
******************************************************************************/
char GameEngine::runMenu1(){

	char choice = ' ';	// Variable for user choice

	// Display menu1 and get input
	menu1->displayMenuDir();
	choice = menu1->getDirInput();

	// Perform action based on choices
	// User chose move direction
	if((choice=='w') || (choice=='a') || (choice=='s') || (choice=='d')){

		// Move Character
		moveChar(choice);
		
		return choice;
	}
	// user chose examine room
	else if(choice == 'r'){

		// Examine room
		world->examineSpace();
	
		Character *temp = world->getP1();

			// If player chose to quit within space
			if(temp->getQuit())
				choice = 'q';

		return choice;
	}
	// user chose to look at inventory
	else if(choice == 'i'){

		// Examine inventory / status
		world->checkInventory();
		world->checkStatus();

		return choice;
	}
	// user chose to use item in inventory
	else if(choice == 'u'){

		// Show inventory
		world->checkInventory();

		// Call item menu
		runMenu2();
		
		return choice;
	}
	else // quit
		return choice;

}

/******************************************************************************
** Description: Function that runs menu2. Which item to use?
******************************************************************************/
void GameEngine::runMenu2()
{
	int iPick = 0;

	// Display items
	// If no items
	if(world->inventoryEmpty())
		cout << "Inventory is empty. Cannot use items." << endl;
	else{
		// Display menu2 and get input
		menu2->displayMenu();
		iPick = menu2->getIntInput();

		world->useItem(iPick); // use item picked 
	}
}

/******************************************************************************
** Description: Function that moves Character.
******************************************************************************/
void GameEngine::moveChar(char dir)
{
	bool pointsSomewhere = 0;
	bool cantOpen = 0;

	// Check if there is an exit at movement direction
	pointsSomewhere = world->pointsToDir(dir);

	// Check if exit is an open/locked door
	cantOpen = world->isObstructed(dir);

	// if direction goes nowhere
	if(!pointsSomewhere)
		cout << "Invalid direction." << endl;
	else if(cantOpen)	// if obstructed
		cout << "The door won't open. Find something to open it." << endl;
	else{	// otherwise, move 
		world->movePlayer(dir);
		world->decrementTime();	// Decrement time
	}
}

/******************************************************************************
** Description: Function that displays time left.
******************************************************************************/
void GameEngine::displayTime()
{
	int steps = world->getTime();

	cout << steps << " hours left." << endl;
}	

