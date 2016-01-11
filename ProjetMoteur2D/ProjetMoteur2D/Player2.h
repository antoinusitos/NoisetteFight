#pragma once

#include "Player.h"

class Player2 : public Player
{
public:
	Player2();
	~Player2();

	void CreateCombos() override;
	void ResetEtat();

private:
	std::vector<Hit*>* combos;
};