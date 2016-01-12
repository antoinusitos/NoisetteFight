#pragma once

#include "Player.h"

class Player1 : public Player
{
public:
	Player1(Scene* scene);
	~Player1();

	void CreateCombos() override;
	void ResetEtat();
	void CheckCombo();

private:
	std::vector<Hit*>* combos;

	float multiply;
	
};