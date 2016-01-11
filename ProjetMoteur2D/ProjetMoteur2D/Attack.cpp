#include "stdafx.h"
#include "Attack.h"

Attack::Attack(Player::State theState) : Sequence(theState)
{
	
}

Attack::~Attack()
{
	
}


void Attack::Execute(Player* thePlayer)
{
	std::cout << thePlayer->GetPlayerID() << " : Je tape ";
	if (thePlayer->GetCurrentState() == Player::State::isCrouching)
	{
		std::cout << "accroupis ! " << std::endl;
	}
	else if (thePlayer->GetCurrentState() == Player::State::isJumping)
	{
		std::cout << "en l'air ! " << std::endl;
	}
	else
	{
		std::cout << "debout ! " << std::endl;
	}
}