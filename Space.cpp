/******************************************************************************
** Program name: Space.cpp
** Author: April Castaneda
** Date: 06.08.2019
** Description: Space.cpp is the Space class implementation file.
******************************************************************************/
#include "Space.hpp"

/******************************************************************************
** Description: Constructor
******************************************************************************/
Space::Space(Space*right, Space*down, Space*left, Space*up){

	setRight(right);
	setDown(down);
	setLeft(left);
	setUp(up);
	obstruction = ' ';
	setKey("");
	fItemGone = 0;
}

/******************************************************************************
** Description: Virtual Desstructor.
******************************************************************************/
Space::~Space(){

}

/******************************************************************************
** Description: Setters
******************************************************************************/
void Space::setRight(Space *right){
	this->right = right;
}

void Space::setDown(Space *down){
	this->down = down;
}

void Space::setLeft(Space *left){
	this->left = left;
}

void Space::setUp(Space *up){
	this->up = up;
}

void Space::setCharName(char charName){
	this->charName = charName;
}

void Space::setSpName(string spName){
	this->spName = spName;
}

void Space::setObstruction(char obstruction){
	this->obstruction = obstruction;
}

void Space::setKey(string key){
	this->key = key;
}

/******************************************************************************
** Description: Getters
******************************************************************************/
Character* Space::getMonster(){
	return monster;
}

Item* Space::getFoundItem(){
	return foundItem;
}

Item* Space::getUseItem(){
	return useItem;
}

Space* Space::getRight(){
	return right;
}

Space* Space::getDown(){
	return down;
}

Space* Space::getLeft(){
	return left;
}

Space* Space::getUp(){
	return up;
}

char Space::getCharName(){
	return charName;
}

string Space::getSpName(){
	return spName;
}

char Space::getObstruction(){
	return obstruction;
}

string Space::getKey(){
	return key;
}

/******************************************************************************
** Description: Function to determine if movement direction is obstructed.
******************************************************************************/
bool Space::isObstructed(char direction){
	return (direction == obstruction);
}

/******************************************************************************
** Description: Function that deletes foundItem if user picked it up.
******************************************************************************/
void Space::foundItemGone()
{
	//delete foundItem;
	fItemGone = 1;
}
