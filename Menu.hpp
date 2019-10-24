/********************************************************************
** Program name: Menu.hpp
** Author: April Castaneda
** Date: 04.13.2019
** Description: Menu class specification file.
**		Dynamically creates a menu based on # of rows.
**		Takes Input. Validates Input. Returns valid input as
**		integer.
*********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <string>
using std::string;

// Menu class declaration
class Menu
{
private:
	int menuRows;		// how many rows in the menu
	int minVal, maxVal; 	// min and max values of user input
	int intInput;		// user input changed to integer
	double minDbl, maxDbl;	// min and max of double input
	double dblInput;	// user input changed to double
	string stringInput; 	// user input as a string
	char dirInput;		// user input for directions
	char ysInput;		// user input for yes/no
	string* menuArray;	// array to be dynamically allocated
public:
	// Constructors
	Menu(); 		// default constructor
	Menu(int rows, int min, int max); // Constructor for int input
	Menu(int rows, double minD, double maxD); // Constructor for dbl input
	Menu(int rows);	// Constructor for string input

	// Destructor
	~Menu();

	// Setter Functions
	void setRows(int rows);
	void setMin(int min);
	void setMax(int max);
	void setMinDbl(double minD);
	void setMaxDbl(double maxD);	
	void setIntInput(int input);
	void setStringInput(string strInput);
	void setDirInput(char direction);
	void setYSInput(char yesNo);
	void setMenuArray(int rows);

	// Getter Functions
	int getRows();
	int getMin();
	int getMax();
	double getMinDbl();
	double getMaxDbl();	
	int getIntInput();
	double getDblInput();
	string getStringInput();
	char getDirInput();
	char getYSInput();
	string* getMenuArray();

	// Dynamically allocate Menu Array
	string* allocMenu(int rows);

	// Populate Menu Array
	void populateArray(int rowNum, string optionScript);

	// Display Menu
	void displayMenu();
	void displayUnsignedMenu();
	void displayMenuDbl();
	void displayMenuString();
	void displayMenuDir();
	void displayMenuYS();

	// Validate Input
	bool validateInput();
	bool validateUnsignedInput();
	bool validateDoubleInput();
	bool validateStringInput();
	bool validateDirInput();
	bool validateYSInput();
};
#endif
		

