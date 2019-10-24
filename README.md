# Welcome_to_Hell

“Welcome to Hell” is a Horror Escape game wherein the user has to figure out how to leave hell within 24 hours - or face staying there for eternity.

To run game:
Type make in Terminal.
Type ./edit once executable is created.

Theme: 
Horror Escape game

Goal: 
To escape hell within the allotted 24 hours

Space Types:
Dungeon Hallway Theater Apt Hospital

Character Types
User:
Player 
Monsters: Audience
Ex Boyfriend Cerberus Grim Reaper

Structure:
Game Engine class runs a Map class that has a 2D array of Space pointers as a member.

Player Inventory:
Item Class
Vector of Item pointers is a member of Map class

Things player can do:
Move: Right, Down, Left, Up
Examine: Room
Inventory: Look at Inventory, Use Items 
Quit

Win Conditions:
Player finds exit within allotted time and is able to exit.
  - User must defeat all monsters in rooms to gain final item required to exit

Lose Conditions:
Player doesn’t exit within 24 hours.
