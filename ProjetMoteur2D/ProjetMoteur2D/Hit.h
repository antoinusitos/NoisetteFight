#pragma once
#include "Combo.h"
#include "Player.h"

class Sequence;

class Hit : public Combo
{
public:
	void Add(Combo* newChild);
	void Remove();
	Combo* GetChildren();
	std::vector<Sequence*>* GetSequence();

	void AjouteEtat(Sequence* etat);

	bool CheckSequence(Player* thePlayer);

	void SetMultiply(float m);

	int GetNumberSequence();
	float GetMultiply();

	Hit();
	~Hit();

private:
	Combo* child;
	std::vector<Sequence*>* theSequence;
	float multiply;
};