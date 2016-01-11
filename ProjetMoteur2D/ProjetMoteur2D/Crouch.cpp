#include "stdafx.h"
#include "Crouch.h"

Crouch::Crouch(Player::State theState) : Sequence(theState)
{
	
}

Crouch::~Crouch()
{
	
}

void Crouch::Execute(Player* thePlayer)
{
	if (thePlayer->GetCurrentState() == Player::State::isStanding)
	{
		std::cout << "Je m'accroupis !" << std::endl;
		thePlayer->Crouch();
	}
	else if (thePlayer->GetCurrentState() == Player::State::isJumping)
	{
		std::cout << "Je descend !" << std::endl;
		thePlayer->Stand();
	}
}