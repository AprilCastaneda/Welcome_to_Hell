/********************************************************************
** Program name: Menu.cpp
** Author: April Castaneda
** Date: 04.13.2019
** Description: Menu class implementation file.
**		Dynamically creates a menu based on # of rows.
**		Takes Input. Validates Input. Returns valid input as
**		integer.
********************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "Menu.hpp"

/********************************************************************
** Description: Default Constructor
********************************************************************/
Menu::Menu()
{
	setRows(1);
	setMin(1);
	setMax(1);
	setMinDbl(0.0);
	setMaxDbl(0.0);
	setStringInput("1");
	setIntInput(1);
	menuArray = nullptr;
}

/********************************************************************
** Description: Constructor for integer input.
********************************************************************/
Menu::Menu(int rows, int min, int max)
{
	setRows(rows);
	setMin(min);
	setMax(max);
	setMenuArray(rows);
}

/********************************************************************
** Description: Constructor for double input.
********************************************************************/
Menu::Menu(int rows, double minD, double maxD)
{
	setRows(rows);
	setMinDbl(minD);
	setMaxDbl(maxD);
	setMenuArray(rows);
}

/********************************************************************
** Description: Constructor for string input.
********************************************************************/
Menu::Menu(int rows)
{
	setRows(rows);
	setMenuArray(rows);
}

/********************************************************************
** Description: Destructor
********************************************************************/
Menu::~Menu()
{
	if(menuArray != nullptr)
	{
		delete[] menuArray;
		menuArray = nullptr;
	}
}

/********************************************************************
** Description: Setter Functions
********************************************************************/
void Menu::setRows(int rows)
{
	menuRows = rows;
}

void Menu::setMin(int min)
{
	minVal = min;
}

void Menu::setMax(int max)
{
	maxVal = max;
}

void Menu::setMinDbl(double minD)
{
	minDbl = minD;
}

void Menu::setMaxDbl(double maxD)
{
	maxDbl = maxD;
}

void Menu::setStringInput(string strInput)
{
	stringInput = strInput;
}

void Menu::setIntInput(int input)
{
	intInput = input;
}

void Menu::setDirInput(char direction)
{
	dirInput = direction;
}

void Menu::setYSInput(char ys)
{
	ysInput = ys;
}

void Menu::setMenuArray(int rows)
{
	string *tempPtr = allocMenu(rows);
	menuArray = tempPtr;
}

/********************************************************************
** Description: Getter Functions
********************************************************************/
int Menu::getRows()
{
	return menuRows;
}

int Menu::getMin()
{
	return minVal;
}

int Menu::getMax()
{
	return maxVal;
}

double Menu::getMinDbl()
{
	return minDbl;
}

double Menu::getMaxDbl()
{
	return maxDbl;
}

string Menu::getStringInput()
{
	return stringInput;
}

int Menu::getIntInput()
{
	return intInput;
}

double Menu::getDblInput()
{
	return dblInput;
}

char Menu::getDirInput()
{
	return dirInput;
}

char Menu::getYSInput()
{
	return ysInput;
}

string* Menu::getMenuArray()
{
	return menuArray;
}

/********************************************************************
** Description: Dynamically allocate menu based on number of rows
********************************************************************/
string* Menu::allocMenu(int rows)
{
	string* tempPtr = new string[rows];
	
	return tempPtr;
}

/********************************************************************
** Description: Populate array
********************************************************************/
void Menu::populateArray(int rowNum, string optionScript)
{
	menuArray[rowNum] = optionScript;
}

/********************************************************************
** Description: Display Menu for Int Input.
********************************************************************/
void Menu::displayMenu()
{
	bool inputValid = 0;

//	cout << "***************************************************" << endl;
	
	for(int x = 0; x < menuRows; x++)
	{
		cout << menuArray[x] << endl;
	}
	
//	cout << "***************************************************" << endl;
	
/*	cout << "Please enter an integer between " << minVal;
	cout << " to " << maxVal << ": ";
*/	
	do
	{
		getline(cin, stringInput);	
		inputValid = validateInput();
	}
	while(!inputValid); 
}

/********************************************************************
** Description: Display Menu for Unsigned Int Input.
********************************************************************/
void Menu::displayUnsignedMenu()
{
	bool inputValid = 0;

	for(int x = 0; x < menuRows; x++)
	{
		cout << menuArray[x] << endl;
	}
/*	cout << "Please enter an integer between " << minVal;
	cout << " to " << maxVal << ": ";
*/
	do
	{
		getline(cin, stringInput);	
		inputValid = validateUnsignedInput();
	}
	while(!inputValid); 
}

/********************************************************************
** Description: Display Menu for double Input.
********************************************************************/
void Menu::displayMenuDbl()
{
	for(int x = 0; x < menuRows; x++)
	{
		cout << menuArray[x] << endl;
	}
/*	cout << "Please enter a value between " << minDbl;
	cout << " to " << maxDbl << ": ";
*/
	getline(cin, stringInput);
}

/********************************************************************
** Description: Display Menu for String Input.
********************************************************************/
void Menu::displayMenuString()
{
	bool inputValid = 0;

	for(int x = 0; x < menuRows; x++)
	{
		cout << menuArray[x] << endl;
	}
	
	do
	{
		getline(cin, stringInput);	
		inputValid = validateStringInput();
	}
	while(!inputValid);
}

/********************************************************************
** Description: Display Menu for Direction Input.
********************************************************************/
void Menu::displayMenuDir()
{
	bool inputValid = 0;

	cout << "--------------------------------------------------------------------------------------------------" << endl;
	for(int x = 0; x < menuRows; x++)
	{
		cout << menuArray[x] << endl;
	}
	cout << "--------------------------------------------------------------------------------------------------" << endl;
	
	do
	{
		getline(cin, stringInput);	
		inputValid = validateDirInput();
	}
	while(!inputValid);
}
 
/********************************************************************
** Description: Display Menu for Yes/No Input.
********************************************************************/
void Menu::displayMenuYS()
{
	bool inputValid = 0;

	for(int x = 0; x < menuRows; x++)
	{
		cout << menuArray[x] << endl;
	}
	
	do
	{
		getline(cin, stringInput);	
		inputValid = validateYSInput();
	}
	while(!inputValid);
}
/********************************************************************
** Description: Validates if input is a signed integer and between 
**		min/max.
********************************************************************/
bool Menu::validateInput()
{
	// Check to see input is not empty
	if(stringInput.empty())
	{
		cout << "Input Error. Try again." << endl;
		return 0;
	}

	// Go through characters of string to determine if integer
	for(unsigned int x = 0; x < stringInput.size(); x++)
	{
		char temp; // holder for characters in stringInput

		temp = stringInput.at(x);

		if(!isdigit(temp))
		{
			// If negative number, valid
			if((temp == 45) && (x == 0))
			{
				continue;
			}
			else
			{
				cout << "Input Error. Try again." << endl;
				return 0; // invalid data
			}
		}		
	}

	// data is an integer, so turn string into integer
	int tempInt = stoi(stringInput);
		
	// Now, see if data is between minValue and maxValue
	if(!((tempInt >= minVal) && (tempInt <= maxVal)))  
	{
		cout << "Input Error. Try again." << endl;
		return 0; // invalid data
	}

	// data is valid, so assign tempInt to intInput
	intInput = tempInt;

	return 1;
}

/********************************************************************
** Description: Validates if input is an usigned integer and between 
**		min/max.
********************************************************************/
bool Menu::validateUnsignedInput()
{
	// Check to see input is not empty
	if(stringInput.empty())
	{
		cout << "Input Error. Try again." << endl;
		return 0;
	}

	// Go through characters of string to determine if integer
	for(unsigned int x = 0; x < stringInput.size(); x++)
	{
		char temp; // holder for characters in stringInput

		temp = stringInput.at(x);

		if(!isdigit(temp))
		{
			cout << "Input Error. Try again." << endl;
			return 0; // invalid data
		}		
	}

	// data is an integer, so turn string into integer
	int tempInt = stoi(stringInput);
		
	// Now, see if data is between minValue and maxValue
	if(!((tempInt >= minVal) && (tempInt <= maxVal)))  
	{
		cout << "Input Error. Try again." << endl;
		return 0; // invalid data
	}

	// data is valid, so assign tempInt to intInput
	intInput = tempInt;

	return 1;
}

/********************************************************************
** Description: Validate if input is a double and between min/max.
********************************************************************/
bool Menu::validateDoubleInput()
{
	// Check to see if input is not empty
	if(stringInput.empty())
	{
		cout << "Input Error. Try again." << endl;
		return 0;
	}

	int decimalCount = 0;

	// Go through characters of string to determine if integer
	for(unsigned int x = 0; x < stringInput.size(); x++)
	{
		char temp; // holder for characters in stringInput

		temp = stringInput.at(x);

		// See if char is decimal
		if(temp == 46)
		{
			decimalCount++; // Increment counter if decimal
		}

		// If not a digit
		if(!isdigit(temp))
		{
			// Go through different possibilities if/not a decimal
			if((temp == 46) && (decimalCount > 1))
			{
				cout << "Input Error. Try again." << endl;
				return 0; // invalid data)
			}		
			else if((temp != 46) && (decimalCount > 1))	
			{
				cout << "Input Error. Try again." << endl;
				return 0; // invalid data
			}
			else if((temp == 46) && (decimalCount <= 1))
			{
				continue;
			}
			else if((temp != 46) && (decimalCount <= 1))
			{
				cout << "Input Error. Try again." << endl;
				return 0; // invalid data
			}
		}		
	}

	// Data is a double, so turn string int double
	double tempDbl = stod(stringInput);

	// Now, see if data is between minDbl and maxDbl
	if(!((tempDbl >= minDbl) && (tempDbl <= maxDbl)))
	{
		cout << "Input Error. Try again." << endl;
		return 0; // invalid data
	}

	// Data is valid, so assign tempInt to dblInput
	dblInput = tempDbl;

	return 1;
}

/********************************************************************
** Description: Validates if string input has valid characters
********************************************************************/
bool Menu::validateStringInput()
{
	// Check to see input is not empty
	if(stringInput.empty())
	{
		cout << "Input Error. Try again." << endl;
		return 0;
	}

	return 1;
}

/********************************************************************
** Description: Validates if directional input has valid characters.
********************************************************************/
bool Menu::validateDirInput()
{
	// Check to see input is not empty
	if(stringInput.empty())
	{
		cout << "Input Error. Try again." << endl;
		return 0;
	}

	char temp; // holder for characters in stringInput

	temp = stringInput.at(0);

	temp = tolower(temp);	// change to lower case
	
	// Determine if not char
	if(!isalpha(temp))
	{
		cout << "Input Error. Try again." << endl;
		return 0; // Invalid data
	}

	// Determine if either w, a, s, d, r, i, q
	if(!((temp=='w')||(temp=='a')||(temp=='s')||(temp=='d')||(temp=='r')||(temp=='i')||(temp=='u')||(temp=='q')))	
	{
		cout << "Input Error. Try again." << endl;
		return 0; // Invalid data
	}
	
	// Data is valid so assign temp to dirInput
	dirInput = temp;
	
	return 1;
}

/********************************************************************
** Description: Validates if yes/no input has valid characters.
********************************************************************/
bool Menu::validateYSInput()
{
	// Check to see input is not empty
	if(stringInput.empty())
	{
		cout << "Input Error. Try again." << endl;
		return 0;
	}

	char temp; // holder for characters in stringInput

	temp = stringInput.at(0);

	temp = tolower(temp);	// change to lower case
	
	// Determine if not char
	if(!isalpha(temp))
	{
		cout << "Input Error. Try again." << endl;
		return 0; // Invalid data
	}

	// Determine if either y/s
	if(!((temp=='y') || (temp=='n')))	
	{
		cout << "Input Error. Try again." << endl;
		return 0; // Invalid data
	}
	
	// Data is valid so assign temp to dirInput
	ysInput = temp;
	
	return 1;
}
