#pragma once

#include "Command.h"

class Jump : public Command
{
public:
	Jump();
	~Jump();

	void Execute(Player* thePlayer);
};