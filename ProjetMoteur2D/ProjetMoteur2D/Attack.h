#pragma once

#include "Command.h"

class Attack : public Command
{
public:
	Attack();
	~Attack();

	void Execute(Player* thePlayer);
};