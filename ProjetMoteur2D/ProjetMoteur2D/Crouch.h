#pragma once

#include "Command.h"

class Crouch : public Command
{
public:
	Crouch();
	~Crouch();

	void Execute(Player* thePlayer);
};