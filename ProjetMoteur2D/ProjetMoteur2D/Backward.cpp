#include "stdafx.h"
#include "Backward.h"

Backward::Backward()
{
	
}

Backward::~Backward()
{
	
}

void Backward::Execute(Player* thePlayer)
{
	std::cout << thePlayer->GetPlayerID() << "Je recule !" << std::endl;
}