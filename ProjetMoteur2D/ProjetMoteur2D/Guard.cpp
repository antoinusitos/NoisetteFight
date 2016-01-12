#include "stdafx.h"
#include "Guard.h"

Guard::Guard(Player::State theState) : Sequence(theState)
{
	
}

Guard::~Guard()
{
	
}

void Guard::Execute(Player* thePlayer)
{
	std::cout << thePlayer->GetPlayerID() << "Je block !" << std::endl;
	thePlayer->Block();
}