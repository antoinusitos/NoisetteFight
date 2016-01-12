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

	int GetNumberSequence();

	Hit();
	~Hit();

private:
	Combo* child;
	//Sequence* theSequence;
	std::vector<Sequence*>* theSequence;
};