#pragma once

#include "Command.h"

class Forward : public Command
{
public:
	Forward();
	~Forward();

	void Execute(Player* thePlayer);
};