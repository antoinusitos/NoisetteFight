#pragma once

#include <vector>

class Hit;

class Combo
{
public:
	Combo();
	~Combo();
	void CreateCombos();

private:
	std::vector<Hit*>* combos;
};

