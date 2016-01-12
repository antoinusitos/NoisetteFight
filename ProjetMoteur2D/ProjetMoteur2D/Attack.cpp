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
		//thePlayer->Crouch();
		thePlayer->CheckCombo();
	}
	else if (thePlayer->GetCurrentState() == Player::State::isJumping)
	{
		std::cout << "en l'air ! " << std::endl;
		//thePlayer->Jump();
		thePlayer->CheckCombo();
	}
	else
	{
		std::cout << "debout ! " << std::endl;
		thePlayer->CheckCombo();
	}
}