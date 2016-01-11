#include "stdafx.h"
#include "Sequence.h"

Sequence::Sequence(Player::State theState)
{
	currentState = theState;
}

Sequence::~Sequence()
{
	
}

Player::State Sequence::GetCurrentState()
{
	return currentState;
}