#pragma once

#include "Sequence.h"

class Jump : public Sequence
{
public:
	Jump(Player::State theState);
	~Jump();

	void Execute(Player* thePlayer);
};