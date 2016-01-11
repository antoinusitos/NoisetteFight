#pragma once
#include "Observer.h"

class Player1Life : public Observer
{
public:

	int life;
	Player1Life();
	~Player1Life();
	virtual bool ChangeValor(Scene* scene);
};