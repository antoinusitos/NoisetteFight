#include "stdafx.h"
#include "Crouch.h"

Crouch::Crouch()
{
	
}

Crouch::~Crouch()
{
	
}

void Crouch::Execute(Player* thePlayer)
{
	if (thePlayer->GetCurrentState() != Player::State::isCrouching)
	{
		std::cout << "Je m'accroupis !" << std::endl;
		thePlayer->Crouch();
	}
}