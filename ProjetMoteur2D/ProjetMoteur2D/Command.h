#pragma once
#include "Player.h"
#include <iostream>

class Command
{
public:
	Command();
	~Command();
	
	virtual void Execute(Player* thePlayer) = 0;

};