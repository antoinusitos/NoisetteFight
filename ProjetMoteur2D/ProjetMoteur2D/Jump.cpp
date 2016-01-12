#include "stdafx.h"
#include "Jump.h"

Jump::Jump(Player::State theState) : Sequence(theState)
{
	
}

Jump::~Jump()
{
	
}

void Jump::Execute(Player* thePlayer)
{
	if (thePlayer->GetCurrentState() == Player::State::isStanding)
	{
		//std::cout << "Je jump !" << std::endl;
		thePlayer->Jump();
	}
	else if (thePlayer->GetCurrentState() == Player::State::isCrouching)
	{
		//std::cout << "Je me releve !" << std::endl;
		thePlayer->Stand();
	}
}