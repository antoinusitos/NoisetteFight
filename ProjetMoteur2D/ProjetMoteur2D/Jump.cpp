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
	std::cout << thePlayer->GetPlayerID() << "Je jump !" << std::endl;
}