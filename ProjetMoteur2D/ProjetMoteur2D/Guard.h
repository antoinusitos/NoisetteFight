#pragma once

#include "Sequence.h"

class Guard : public Sequence
{
public:
	Guard(Player::State theState);
	~Guard();

	void Execute(Player* thePlayer);
};