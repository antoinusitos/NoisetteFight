#pragma once

#include "Command.h"

class Backward : public Command
{
public:
	Backward();
	~Backward();

	void Execute(Player* thePlayer);
};