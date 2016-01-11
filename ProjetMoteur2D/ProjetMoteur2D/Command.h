#pragma once
#include "Player.h"

class Command
{
public:
	Command();
	~Command();
	
	virtual void Execute(Player thePlayer);

};