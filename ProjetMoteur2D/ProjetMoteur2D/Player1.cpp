#include "stdafx.h"
#include "Player1.h"
#include <iostream>

Player1::Player1() : Player::Player()
{
	std::cout << "creation Player " << std::endl;
	playerID = 1;

	currentInputHandler = new InputHandler(this);
}

Player1::~Player1()
{
	
}