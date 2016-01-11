#pragma once

#include "Player.h"
#include "Combo.h"
#include <iostream>
#include <Vector>

class Sequence : public Combo
{
public:
	Sequence(Player::State theState);
	~Sequence();	

	virtual void Execute(Player* thePlayer) = 0;

	Player::State GetCurrentState();

private:
	Player::State currentState;
};