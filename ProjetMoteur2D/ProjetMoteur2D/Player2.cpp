#include "stdafx.h"
#include "Player2.h"

Player2::Player2() : Player::Player()
{
	playerID = 2;

	currentInputHandler = new InputHandler(this);
}

Player2::~Player2()
{
	
}