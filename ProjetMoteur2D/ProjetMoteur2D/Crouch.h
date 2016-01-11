#pragma once

#include "Sequence.h"

class Crouch : public Sequence
{
public:
	Crouch(Player::State theState);
	~Crouch();

	void Execute(Player* thePlayer);
};