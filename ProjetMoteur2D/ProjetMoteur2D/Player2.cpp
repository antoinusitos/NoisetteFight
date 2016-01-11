#include "stdafx.h"
#include "Player2.h"

Player2::Player2() : Player::Player()
{
	playerID = 2;

	currentInputHandler = new InputHandler(this);

	combos = new std::vector<Hit*>();
}

Player2::~Player2()
{
	
}

void Player2::CreateCombos()
{

}

void Player2::ResetEtat()
{
	SetCurrentState(State::isStanding);
}