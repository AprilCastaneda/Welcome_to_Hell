/******************************************************************************
** Program name: Space.hpp
** Author: April Castaneda
** Date: 06.08.2019
** Description: Space.hpp is the Space class specification file.
******************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include "Character.hpp"
#include "Audience.hpp"
#include "Cerberus.hpp"
#include "ExBoyfriend.hpp"
#include "GrimReaper.hpp"

#include "Item.hpp"

class Space{

protected:

	Character *monster;
	Item *foundItem,
		*useItem;

	Space *right,
		*down,
		*left,
		*up;

	char charName;
	string spName;

	char obstruction;
	string key;	// correct key to open obstruction
	bool fItemGone;
public:
	Space(Space*right=NULL, Space*down=NULL, Space*left=NULL,
		Space*up=NULL);

	virtual ~Space();

	// Setters
	virtual void setMonster() = 0;
	virtual void setItems() = 0;
	virtual void setFoundItem(Item*) = 0;
	virtual void setUseItem(Item*) = 0;

	void setRight(Space*);
	void setDown(Space*);
	void setLeft(Space*);
	void setUp(Space*);

	void setCharName(char);
	void setSpName(string);

	void setObstruction(char);
	void setKey(string);

	// Getters
	virtual Character* getMonster();
	virtual Item* getFoundItem();
	virtual Item* getUseItem();

	Space* getRight();
	Space* getDown();
	Space* getLeft();
	Space* getUp();

	char getCharName();
	string getSpName();

	char getObstruction();
	string getKey();

	virtual bool isObstructed(char);

	void foundItemGone();
	virtual bool examineRoom(Character *&) = 0;
};
#endif
