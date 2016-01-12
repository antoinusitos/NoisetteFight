#include "stdafx.h"
#include "Forward.h"

Forward::Forward(Player::State theState) : Sequence(theState)
{
	
}

Forward::~Forward()
{
	
}

void Forward::Execute(Player* thePlayer)
{
	//std::cout << thePlayer->GetPlayerID() << "J'avance !" << std::endl;
}