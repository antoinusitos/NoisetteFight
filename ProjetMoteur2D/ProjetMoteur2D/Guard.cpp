#include "stdafx.h"
#include "Guard.h"

Guard::Guard()
{
	
}

Guard::~Guard()
{
	
}

void Guard::Execute(Player* thePlayer)
{
	std::cout << thePlayer->GetPlayerID() << "Je block !" << std::endl;
}