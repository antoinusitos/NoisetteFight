#pragma once

#include "Sequence.h"

class Attack : public Sequence
{
public:
	Attack(Player::State theState);
	~Attack();

	void Execute(Player* thePlayer);
};