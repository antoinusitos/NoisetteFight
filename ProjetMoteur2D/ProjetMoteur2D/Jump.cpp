#include "stdafx.h"
#include "Jump.h"

Jump::Jump()
{
	
}

Jump::~Jump()
{
	
}

void Jump::Execute(Player* thePlayer)
{
	if (thePlayer->GetCurrentState() != Player::State::isJumping)
	{
		std::cout << "Je jump !" << std::endl;
		thePlayer->Jump();
	}
}