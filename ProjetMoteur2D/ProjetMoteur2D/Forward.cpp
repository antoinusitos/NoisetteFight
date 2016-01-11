#include "stdafx.h"
#include "Forward.h"

Forward::Forward()
{
	
}

Forward::~Forward()
{
	
}

void Forward::Execute(Player* thePlayer)
{
	std::cout << thePlayer->GetPlayerID() << "J'avance !" << std::endl;
}