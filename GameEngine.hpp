/******************************************************************************
** Program name: GameEngine.hpp
** Author: April Castaneda
** Date: 06.08.2019
** Description: GameEngine class specification file.
******************************************************************************/
#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

//#include <iomanip>
//using namespace std;

#include "Menu.hpp"

#include "Character.hpp"
#include "Player.hpp"

#include "Map.hpp"

// Game Engine Class declaration
class GameEngine
{
	private:
		Menu *menu1,	// menus to create
			*menu2;
		Map *world; 
		char displayBoard[11][11];
	public:
		// Constructor
		GameEngine();

		// Destructor
		~GameEngine();

		// Function to run Game	
		void runGame();

		// Function to create World
		void buildWorld();

		// Function to run scripts
		void runScript1();

		// Functions to create and run Menus
		void createMenus();
		char runMenu1();
		void runMenu2();
		
		// Function to move char
		void moveChar(char);

		// Function that prints status
		void displayTime();
};
#endif
