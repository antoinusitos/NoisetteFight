#include "stdafx.h"
#include "Attack.h"

Attack::Attack()
{
	
}

Attack::~Attack()
{
	
}


void Attack::Execute(Player* thePlayer)
{
	std::cout << thePlayer->GetPlayerID() << "Je tape !" << std::endl;
}