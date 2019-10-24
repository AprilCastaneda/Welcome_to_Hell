/******************************************************************************
** Program name: Map.cpp
** Author: April Castaneda
** Date: 06.08.2019
** Description: Map.cpp is the Map class specification file.
******************************************************************************/
#include "Map.hpp"

/******************************************************************************
** Description: Constructor
******************************************************************************/
Map::Map(){

	// Create 2d array of Space pointers
	board = new Space **[MAPROWS];
	
	for(int i = 0; i < MAPROWS; i++)
		board[i] = new Space *[MAPCOLS];

	for(int i = 0; i < MAPROWS; i++)
		for(int j = 0; j < MAPCOLS; j++)
			board[i][j] = NULL;

	//Create specific spaces
	// Create Dungeons - 4 different dungeons
	board[1][4] = new Dungeon(2);
	board[2][2] = new Dungeon(3);
	board[3][2] = new Dungeon(4);
	board[4][3] = new Dungeon(1);

	// Create Hallways
	board[1][0] = new Hallway;
	board[1][1] = new Hallway(3); // Set hallway where gold key is used
	board[1][2] = new Hallway;
	board[1][3] = new Hallway(2); // Set hallway where silver key is used
	board[2][0] = new Hallway(4); // Set hallway to exit
	board[2][3] = new Hallway;
	board[3][3] = new Hallway(1); // Set hallway where steel key is found

	// Create Theater
	board[3][4] = new Theater;

	// Create Apt
	board[0][3] = new Apt;

	// Create Hospital
	board[0][1] = new Hospital;

	// Set Pointers to point to adjacent spaces where exits are
	setSpacePointers();

	// Set Obstructions - i.e. closed doors
	setObstructions();

	// Set player character
	p1 = NULL;
	p1 = new Player("You");

	// Set Time
	setTime(24);
	
	// Set miniMap - if user has it - 0 = doesn't have map
	setMiniMap(0);

	// Set Menus
	menu1 = NULL;
	menu1 = new Menu(1);
	menu1->populateArray(0, "Pick up the item? (y/n)");
	
	menu2 = NULL;
	menu2 = new Menu(1);
	menu2->populateArray(0, "Would you like to remove an item? (y/n)");

	menu3 = NULL;
	menu3 = new Menu(1, 1, 4);
	menu3->populateArray(0, "Which item would you like to lose? (1-4)");

	// Place player
	player = board[4][3];
}

/******************************************************************************
** Description: Destructor
******************************************************************************/
Map::~Map()
{
	// Delete board
	for(int i = 0; i < MAPROWS; i++)
	{
		for(int j = 0; j < MAPCOLS; j++)
		{
			if(board[i][j] != NULL)
			{
				delete board[i][j];
			}
		}
		
		// Delete sub array
		delete []board[i];
	}

	// Delete outer array
	delete []board;

	// Delete Character
	if(p1 != NULL)
		delete p1;

	// Delete menus
	if(menu1 != NULL)
		delete menu1;

	if(menu2 != NULL)
		delete menu2;

	if(menu3 != NULL)
		delete menu3;

	// Delete items in Inventory
	inventory.clear();
}

/******************************************************************************
** Description: Function that connects Space pointers.
******************************************************************************/
void Map::setSpacePointers()
{
	// Starting from 0,0 to 4,4
	board[0][1]->setDown(board[1][1]);

	board[0][3]->setDown(board[1][3]);

	board[1][0]->setRight(board[1][1]);
	board[1][0]->setDown(board[2][0]);

	board[1][1]->setRight(board[1][2]);
	board[1][1]->setLeft(board[1][0]);
	board[1][1]->setUp(board[0][1]);
	
	board[1][2]->setRight(board[1][3]);
	board[1][2]->setDown(board[2][2]);
	board[1][2]->setLeft(board[1][1]);

	board[1][3]->setRight(board[1][4]);
	board[1][3]->setDown(board[2][3]);
	board[1][3]->setLeft(board[1][2]);
	board[1][3]->setUp(board[0][3]);

	board[1][4]->setLeft(board[1][3]);

	board[2][0]->setUp(board[1][0]);
	
	board[2][2]->setDown(board[3][2]);
	board[2][2]->setUp(board[1][2]);

	board[2][3]->setDown(board[3][3]);
	board[2][3]->setUp(board[1][3]);
 
	board[3][2]->setUp(board[2][2]);

	board[3][3]->setRight(board[3][4]);
	board[3][3]->setDown(board[4][3]);
	board[3][3]->setUp(board[2][3]);

	board[3][4]->setLeft(board[3][3]);

	board[4][3]->setUp(board[3][3]);
}

/******************************************************************************
** Description: Function that sets obstructions.
******************************************************************************/
void Map::setObstructions()
{
	// sets where doors that cannot be opened are - need keys
	board[1][1]->setObstruction('w');
	board[1][3]->setObstruction('w');
	board[2][2]->setObstruction('s');
	board[3][3]->setObstruction('d');
	board[4][3]->setObstruction('w');
}

/******************************************************************************
** Description: Function that sets if user has mini map.
******************************************************************************/
void Map::setMiniMap(bool mM)
{
	miniMap = mM;
}

/******************************************************************************
** Description: Function that returns p1 pointer
******************************************************************************/
Character* Map::getP1()
{
	return p1;
}

/******************************************************************************
** Description: Function that sets time.
******************************************************************************/
void Map::setTime(int time)
{
	this->time = time;
}

/******************************************************************************
** Description: Function that returns time.
******************************************************************************/
int Map::getTime()
{
	return time;
}

/******************************************************************************
** Description: Function that decrements time.
******************************************************************************/
void Map::decrementTime()
{
	time--;
}

/******************************************************************************
** Description: Function that sets items.
******************************************************************************/
void Map::setItems()
{
	// Set keys that open obstructions
	board[1][1]->setKey("Gold Key");
	board[1][3]->setKey("Silver Key");
	board[3][3]->setKey("Steel Key");
}

/******************************************************************************
** Description: Function that adds item.
******************************************************************************/
bool Map::addItem(Item* newItem)
{
	char choice = ' ';
	int rmItem = 0;

	// only add item if it is less than max size == 4
	if(inventory.size() >= 4){

		cout << "Inventory is full. Cannot add another item." << endl;
	
		// Show user Inventory
		checkInventory();

		// Ask user if they'd like to remove an item to make room.
		menu2->displayMenuYS();
		choice = menu2->getYSInput();

		// user wants to drop item
		if(choice == 'y'){
			
			// Get which item user wants to lose
			menu3->displayMenu();
			rmItem = menu3->getIntInput();
	
			rmItem -= 1;	// Get index of item

			removeItem(rmItem); // remove item
		}
		// user doesn't want to drop an item
		else
			cout << "You keep your inventory as is." << endl;

		return 0;
	}
	else{	// There is room for item, so add it to vector
		inventory.push_back(newItem);
		
		// Sort inventory
		sort(inventory.begin(), inventory.end());

		// Display updated inventory
		checkInventory();
		
		return 1;
	}
}

/******************************************************************************
** Description: Function that drops item based on user choice.
**		Parameter is index number.
******************************************************************************/
void Map::removeItem(int itemNum)
{
	// checks if inventory is empty
	if(inventoryEmpty())
		cout << "Inventory empty. No items to remove." << endl;
	// checks if index number given is less than inventory size
	else if(((unsigned int)itemNum + 1) > inventory.size()){
		cout << "Invalid entry. You have less items than the number ";
		cout << "entered." << endl;
	}
	// otherwise, try to remove item
	else{

		// Check if item is Quest item
		Item *temp = inventory[itemNum];
		string type = temp->getItemType();
		string name = temp->getItemName();

		// if quest item, cannot be dropped
		if(type == "Quest")
			cout << "You cannot drop a Quest item." << endl;

		// If equipment, can be dropped but removes stats
		else{	
			// adjust stats based on item removed
			if(name == "Scythe"){
				int charStrength = 0;
				charStrength = p1->getStrength();
				charStrength -= 3;
				p1->setStrength(charStrength);
				cout << "\nYou drop the " << name << "." << endl;
				cout << "You have decreased in strength -3!" << endl;
				cout << "Strength: " << p1->getStrength() << endl;
			}
			else if(name == "Watch"){
				time -= 5;
				cout << "\nYou drop the " << name << "." << endl;
				cout << "You lose five hours of time." << endl << endl;
			}
			else if(name == "Mini Map"){
				miniMap = 0;
				cout << "\nYou drop the " << name << "." << endl;
			}
			else if(name == "Fur Coat"){
				int charArmor = 0;
				charArmor = p1->getArmor();
				charArmor -= 2;
				p1->setArmor(charArmor);
				cout << "\nYou drop the " << name << "." << endl;
				cout << "You have decreased your armor -2!" << endl;
				cout << "Armor: " << p1->getArmor() << endl;
			}
			else if(name == "Bronze Medal"){
				int charisma = 0;
				charisma = p1->getDDie();
				charisma -= 1;
				p1->setDDie(charisma);
				cout << "\nYou drop the " << name << "." << endl;
				cout << "You have decreased your charisma -1!" << endl;
				cout << "Charisma: " << p1->getDDie() << endl;
			}
			else
				cout << "\nInvalid item: " << name << endl;

			// Erase item
			eraseItem(itemNum);
		}
	}
}

/******************************************************************************
** Description: Function that erases item from vector.
******************************************************************************/
void Map::eraseItem(int itemNum)
{
	// Erase item
	inventory.erase(inventory.begin() + itemNum);

	if(!inventoryEmpty())	// If not empty, then sort
		sort(inventory.begin(), inventory.end());

	checkInventory();	// Print updated inventory
}

/******************************************************************************
** Description: Function that uses items.
******************************************************************************/
void Map::useItem(int choice)
{
	unsigned int vectSize = inventory.size();
	string iType = "";
	string iName = "";
	Item *tempUse = NULL;
	string tempUseName = "";

	// checks if inventory is empty
	if(inventoryEmpty())
		cout << "No items to use." << endl;
	// Is choice a larger number than inventory size?
	else if((unsigned int)choice > vectSize)
		cout << "No item at slot " << choice << "." << endl;
	// otherwise, try to use item
	else{

		choice -= 1;	// change choice to index value	
		
		// Is item quest item or equipment?
		iType = inventory[choice]->getItemType();
		iName = inventory[choice]->getItemName();

		// If Equipment
		if(iType == "Equip"){

			tempUse = inventory[choice];

			// Check if item has already been equipped
			if(tempUse->getUsed())
				cout << "Item has already been equipped." << endl;
			else{
				tempUse->setUsed(1);	// Mark item as used
				equipItem(iName);
			}
		}
		// If Quest item
		else if(iType == "Quest"){
			
			// Get useItem at player loc
			tempUse = player->getUseItem();
			
			// make sure there is an item there - location has designated items to be used
			if(tempUse != NULL){

				tempUseName = tempUse->getItemName();
			
				// Is key the right one?
				if(iName == tempUseName){
					
					// key is correct so remove obstruction
					player->setObstruction(' ');
					cout << "Door has opened!" << endl;

					// Destroy key
					cout << iName << " is destroyed in the process." << endl;
					eraseItem(choice);
				}
				// Wrong key
				else
					cout << "Incorrect key used. Try again." << endl;
			}
			// Key not needed in space
			else
				cout << "There is no effect." << endl;
		}
		else
			cout << "Invalid item type: choice: " << choice << endl;
	}
}

/******************************************************************************
** Description: Equip item.
******************************************************************************/
void Map::equipItem(string nm)
{
	// Do different effects based on item
	if(nm == "Scythe"){
		int charStrength = 0;
		charStrength = p1->getStrength();
		charStrength += 3;
		p1->setStrength(charStrength);
		cout << "You equip the " << nm << "." << endl;
		cout << "You have incresed in strength +3!" << endl;
		cout << "Strength: " << p1->getStrength() << endl;
	}
	else if(nm == "Watch"){
		time += 5;
		cout << "You equip the " << nm << "." << endl;
		cout << "In exchange for all the years you've lost with ExBoyfriend, ";
		cout << "you get back five hours of lost time." << endl << endl;
	}
	else if(nm == "Mini Map"){
		miniMap = 1;
		cout << "You equip the " << nm << "." << endl;
	}
	else if(nm == "Fur Coat"){
		int charArmor = 0;
		charArmor = p1->getArmor();
		charArmor += 2;
		p1->setArmor(charArmor);
		cout << "You equip the " << nm << "." << endl;
		cout << "You have increased your armor +2!" << endl;
		cout << "Armor: " << p1->getArmor() << endl;
	}
	else if(nm == "Bronze Medal"){
		int charisma = 0;
		charisma = p1->getDDie();
		charisma += 1;
		p1->setDDie(charisma);
		cout << "You equip the " << nm << "." << endl;
		cout << "You have increased your charisma +1!" << endl;
		cout << "Charisma: " << p1->getDDie() << endl;
	}
	else
		cout << "Invalid item: " << nm << endl;
}
		
/******************************************************************************
** Description: Function that displays Inventory.
******************************************************************************/
void Map::checkInventory()
{
	// If nothing in inventory
	if(inventoryEmpty())
		cout << "ITEMS: None" << endl;
	// Otherwise, print out
	else{
		cout << "ITEMS: ";
		for(unsigned int i = 0; i < inventory.size(); i++)
			cout << i+1 << ": " << inventory[i]->getItemName() << " ";
		cout << endl;
	}
}

/******************************************************************************
** Description: Function that checks if inventory is empty.
******************************************************************************/
bool Map::inventoryEmpty()
{
	return inventory.empty();
}

/******************************************************************************
** Description: Function that checks if direction points to NULL.
******************************************************************************/
bool Map::pointsToDir(Space* someDir)
{
	return (someDir != NULL);
}

/******************************************************************************
** Description: Function that checks if direction points to NULL - overloaded
**		with char
******************************************************************************/
bool Map::pointsToDir(char direction)
{
	Space *R, *D, *L, *U;

	R = player->getRight();
	D = player->getDown();
	L = player->getLeft();
	U = player->getUp();

	// Check if direction entered has an exit
	if(direction == 'd')
		return (pointsToDir(R));
	else if(direction == 's')
		return (pointsToDir(D));
	else if(direction == 'a')
		return (pointsToDir(L));
	else if(direction == 'w')
		return (pointsToDir(U));
	else 
		return 0;
}

/******************************************************************************
** Description: Function that calls isObstructed function from Space.
******************************************************************************/
bool Map::isObstructed(char direction)
{
	return player->isObstructed(direction);
}

/******************************************************************************
** Description: Functions that move player R, D, L, U.
******************************************************************************/
void Map::movePlayer(char direction)
{
	if(direction == 'd')
		movePRight();
	else if(direction == 's')
		movePDown();
	else if(direction == 'a')
		movePLeft();
	else if(direction == 'w')
		movePUp();
}

void Map::movePRight()
{
	player = player->getRight();
}

void Map::movePDown()
{
	player = player->getDown();
}

void Map::movePLeft()
{
	player = player->getLeft();
}

void Map::movePUp()
{
	player = player->getUp();
}

/******************************************************************************
** Description: Function that checks the status of the player.
******************************************************************************/
void Map::checkStatus()
{
	p1->displayStats();
}

/******************************************************************************
** Description: Function that examines room player is at.
******************************************************************************/
void Map::examineSpace()
{
	bool itemAtLoc = 0;
	bool itemAdded = 0;
	char getItem = ' '; // y or n
	Item *temp = NULL;

	// Examine room and see if there is an item there
	itemAtLoc = player->examineRoom(p1);

	if(itemAtLoc){	// There's an item at location

		temp = player->getFoundItem();

		// Ask user if they want to pick it up
		menu1->displayMenuYS();
		getItem = menu1->getYSInput();

		// If user wants to get item
		if(getItem == 'y'){
			itemAdded = addItem(temp);
			
			if(itemAdded){	// Remove item from space
				player->foundItemGone();
			}
		}
		// User doesn't pick up item
		else
			cout << "No items picked up." << endl;
	}
}

/******************************************************************************
** Description: Function that displays all available directions.
******************************************************************************/
void Map::displayAvailDirs()
{
	Space *R, *D, *L, *U;

	R = player->getRight();
	D = player->getDown();
	L = player->getLeft();
	U = player->getUp();

	// Are there available exits?
	if(!((pointsToDir(R)) || (pointsToDir(D)) || (pointsToDir(L)) || (pointsToDir(U))))
		cout << "EXITS: None" << endl;
	else{
		cout << "EXITS: ";

		// Check R, D, L, U - then print out if there is an exit
		if(pointsToDir(R))
			cout << "d(right) ";
		if(pointsToDir(D))
			if(player != board[2][2]) // Keep secret room hidden
				cout << "s(down) ";
		if(pointsToDir(L))
			cout << "a(left) ";
		if(pointsToDir(U))
			cout << "w(up)";
	}
	cout << endl;
}

/******************************************************************************
** Description: Function that checks if user got mini map.
******************************************************************************/
bool Map::gotMiniMap()
{
	return miniMap;
}			

/******************************************************************************
** Description: Function that prints Map.
******************************************************************************/
void Map::displayMap()
{
	// Only display minimap if user has equipped it
	if(gotMiniMap()){
		cout << endl;

		// Print Map
		for(int i = 0; i < MAPROWS; i++){
			for(int j = 0; j < MAPCOLS; j++){

				// Set char to display if player or not
				string show = " ";
				if(board[i][j] != NULL){
					if(board[i][j] == player)
						show = "*";
					else
						show = board[i][j]->getCharName();
				}

				// Set specific board space displays
				if((i == 0) && (j == 0))
					cout << "___";
				else if((i == 0) && (j == 1))
					cout << "|" << show << "|";
				else if((i == 0) && (j == 2))
					cout << "___";
				else if((i == 0) && (j == 3))
					cout << "|" << show << "|";
				else if((i == 0) && (j == 4))
					cout << "___";	
				else if((i == 1) && (j == 0))
					cout << "|" << show << " ";
				else if((i == 1) && (j == 1)){
					if(show != "*")
						show = "_";
					cout << "_" << show << "_";
				}
				else if((i == 1) && (j == 2))
					cout << " " << show << " ";	
				else if((i == 1) && (j == 3))
					cout << " " << show << " ";	
				else if((i == 1) && (j == 4))
					cout << "_" << show << "|";
				else if((i == 2) && (j == 0))
					cout << "|" << show << "|";
				else if((i == 2) && (j == 2))
					cout << "|" << show << "|";
				else if((i == 2) && (j == 3))
					cout << "|" << show << "|";
				else if((i == 2) && (j == 4))
					cout << "___";
				else if((i == 3) && (j == 0))
					cout << "---";
				else  if((i == 3) && (j == 2)){	// Hide secret room
					if(show != "*")
						cout << "---";
					else
						cout << "|" << show << "|";
				}
				else if((i == 3) && (j == 3))
					cout << "|" << show << " ";
				else if((i == 3) && (j == 4))
					cout << "_" << show << "|";
				else if((i == 4) && (j == 3))
					cout << "|" << show << "|";
				else if(board[i][j] == NULL)
					cout << "   ";
				else
					cout << "   "; 
			}
			cout << endl;
		}
		cout << endl;
	}
}
