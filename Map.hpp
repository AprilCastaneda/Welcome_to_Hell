/******************************************************************************
** Program name: Map.hpp
** Author: April Castaneda
** Date: 06.08.2019
** Description: Map.hpp is the Map class specification file.
******************************************************************************/
#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;

#include "Space.hpp"
#include "Dungeon.hpp"
#include "Hallway.hpp"
#include "Theater.hpp"
#include "Apt.hpp"
#include "Hospital.hpp"

#include "Item.hpp"

#include "Character.hpp"
#include "Player.hpp"
#include "Audience.hpp"
#include "ExBoyfriend.hpp"
#include "GrimReaper.hpp"

#include "Menu.hpp"

const int MAPROWS=5;
const int MAPCOLS=5;

class Map{

	private:
		Space *player;
		Space ***board;
		vector <Item*> inventory;
		Character *p1;
		Menu *menu1,
			*menu2,
			*menu3;
		int time;
		bool miniMap;
	public:
		// Constructor
		Map();

		// Destructor
		~Map();
		// Function that sets up world
		void setSpacePointers();

		// Function that sets up obstructions
		void setObstructions();
		void setMiniMap(bool);
		void setMenu();

		// Function that returns p1
		Character* getP1();

		// Functions that deal with time
		void setTime(int);
		int getTime();
		void decrementTime();

		// Manage Inventory
		void setItems();
		bool addItem(Item*);
		void removeItem(int);
		void eraseItem(int);
		void useItem(int);
		void equipItem(string);
		void sortItems();
		void checkInventory();
		bool inventoryEmpty();

		// Function that runs Menu
		char runMenu();
	
		// Functions that check if pointers point to a Space	
		bool pointsToDir(Space*);
		bool pointsToDir(char);

		// Function that checks if direction is obstructed
		bool isObstructed(char);

		// Functions that moves player
		void movePlayer(char);
		void movePRight();
		void movePDown();
		void movePLeft();
		void movePUp();

		// Function that displays player's stats
		void checkStatus();
		bool playerQuit();

		// Function that calls virtual Space functions
		void examineSpace();

		// Functions that display Space
		void displayAvailDirs();
		bool gotMiniMap();
		void displayMap();
};
#endif
