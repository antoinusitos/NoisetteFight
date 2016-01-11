#pragma once

#include "Sequence.h"

class Forward : public Sequence
{
public:
	Forward(Player::State theState);
	~Forward();

	void Execute(Player* thePlayer);
};