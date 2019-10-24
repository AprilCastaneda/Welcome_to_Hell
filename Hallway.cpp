/******************************************************************************
** Program name: Hallway.cpp
** Author: April Castaneda
** Date: 06.08.2019
** Description: Hallway.cpp is the Hallway class implementation file.
******************************************************************************/
#include "Hallway.hpp"

/******************************************************************************
** Description: Constructr
******************************************************************************/
Hallway::Hallway() : Space()
{
	setCharName(' ');
	setSpName("Hallway");
	setHallwayChoice(0);
	setMonster();
	setItems();
	setMenu();
}

/******************************************************************************
** Description: Constructor with one parameter.
******************************************************************************/
Hallway::Hallway(int choice) : Space()
{
	setCharName(' ');
	setSpName("Hallway");
	setHallwayChoice(choice);
	setItems();
	setMenu();

	if(choice == 4)
		setCharName('X');	// Different char for exit
}

/******************************************************************************
** Description: Destructor
******************************************************************************/
Hallway::~Hallway()
{
	if(monster != NULL)
		delete monster;

	if(foundItem != NULL)
		delete foundItem;

	if(useItem != NULL)
		delete useItem;

	if(menu1 != NULL)
		delete menu1;
}

/******************************************************************************
** Description: Sets Monster
******************************************************************************/
void Hallway::setMonster()
{
        monster = NULL;
}

/******************************************************************************
** Description: Sets items.
******************************************************************************/
void Hallway::setItems()
{       
        setFoundItem(NULL);
        setUseItem(NULL);

        Item *tempFound = NULL;
	Item *tempUse = NULL;

	// Create items based on hallway they are in
        if(hallwayChoice == 1){
                tempFound = new Item("Quest", "Steel Key");
                setFoundItem(tempFound);
		tempUse = new Item("Quest", "Steel Key");
		setUseItem(tempUse);
        }
        else if(hallwayChoice == 2){
                tempUse = new Item("Quest", "Silver Key");
                setUseItem(tempUse);
        }
        else if(hallwayChoice == 3){
                tempUse = new Item("Quest", "Gold Key");
                setUseItem(tempUse);
        }
}

/******************************************************************************
** Description: Sets Menu.
******************************************************************************/
void Hallway::setMenu()
{
	menu1 = NULL;

	// exit hallway with specific script
	if(hallwayChoice == 4)
	{
		menu1 = new Menu(1);
		menu1->populateArray(0, "\"Why not just stay?\" (y/n)");
	}
}

/******************************************************************************
 * ** Description: Setters
 * ******************************************************************************/
void Hallway::setFoundItem(Item* fItem){
        foundItem = fItem;
}

void Hallway::setUseItem(Item* uItem){
        useItem = uItem;
}

/******************************************************************************
** Description: Setter and Getter.
******************************************************************************/
void Hallway::setHallwayChoice(int choice)
{
	hallwayChoice = choice;
}

int Hallway::getHallwayChoice()
{
	return hallwayChoice;
}

/******************************************************************************
** Descripton: Unique function to examine room.
******************************************************************************/
bool Hallway::examineRoom(Character* &player)
{
	char stay = ' ';

	// hallway where steel key is found
	if((hallwayChoice == 1) && (!fItemGone))
	{
		cout << "You found a " << foundItem->getItemName() << "." << endl;
		return 1;	// Item found
	}
	// hallway where exit is
	else if(hallwayChoice == 4)	// exit
	{
		int strength = player->getStrength();

		// only able to exit once strength hits 21
		if(strength == 21)	// Player has gotten last item - scythe
		{
			cout << "\n\nYou're stronger this time and maybe the ";
			cout << "Scythe can cut through somehow.\nYou prepare to ";
			cout << "swing when the familiar creature appears again ";
			cout << "in front of you.\n\nIt lowers the hood covering its ";
			cout << "face and you see...\n";
			cout << "...yourself.\n\nShe is younger; unmarred.\nHow is that?";
			cout << "She speaks to you with the voice of youth.\n\n";
			cout << "\"Here you are strong, admired, and wanted.\nYou ";
			cout << "will not age and you will not feel pain.\n";

			// menu if user wants to stay in hell
			menu1->displayMenuYS();
			stay = menu1->getYSInput();

			if(stay == 'y')	// User decides to stay in hell
			{
				cout << "\nThe creature with your face smiles at ";
				cout << "you and puts your head between its hands.\n";
				cout << "She moves closer and closer until her eyes ";
				cout << "are right in front of you.\nBut they disappear ";
				cout << "and there is only darkness; glorious and warm ";
				cout << "and comforting darkness.\nYou put the hood back ";
				cout << "over your head like it has always belonged there.";
				cout << "\nAnd you shuffle away.\n\n";
			
				player->setQuit('q');	// Set player quit
		
				return 0;
			}
			else if(stay == 'n') // User decides not to
			{
				cout << "\n\nWhat she says sounds so sweet and easy.\nWhat ";
				cout << "if you can stay?\nAnd they'd still be with you.\n\n";
				cout << "No, it's not real. None of this is real. \n\n\"I ";
				cout << "will not spend eternity living inside of a lie.\"\n\n";
				cout << "You tell her, \"No.\"\n\n";
				cout << "She disappears in front of you.\nSo does the door ";
				cout << "and the walls and the floor.\n\n";
				cout << "You are back at your console staring at these words.\n\n";
				cout << endl;
				cout << "Thank you for visiting Hell! Please come back again soon.\n";
				cout << endl;

				player->setQuit('q');	// Set player quit
		
				return 0;
			}
		}
		// user cannot exit yet - hasn't done last quest
		else
		{
			cout << "\n\nIt is the end of a hallway and there is a door ";
			cout << "marked 'EXIT'.\nBut there is no doorknob.\n ";
			cout << "How do you open it?\nMaybe something big and heavy, ";
			cout << "or something that can cut through?\n\n";
			
			return 0;
		}
	}
	// default empty hallway script
	else
	{
		cout << "You're in a dark, dusty " << spName << "." << endl;
		return 0;
	}

	return 0;
}
