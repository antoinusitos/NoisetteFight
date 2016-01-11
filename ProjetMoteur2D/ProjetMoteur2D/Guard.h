#pragma once

#include "Command.h"

class Guard : public Command
{
public:
	Guard();
	~Guard();

	void Execute(Player* thePlayer);
};