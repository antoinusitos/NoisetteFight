#pragma once

#include "Sequence.h"

class Backward : public Sequence
{
public:
	Backward(Player::State theState);
	~Backward();

	void Execute(Player* thePlayer);
};