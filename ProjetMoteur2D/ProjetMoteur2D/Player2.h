#pragma once

#include "Player.h"

class Player2 : public Player
{
public:
	Player2(Scene* scene);
	~Player2();

	void CreateCombos() override;
	void ResetEtat();
	void CheckCombo();

private:
	std::vector<Hit*>* combos;

	float multiply;
};