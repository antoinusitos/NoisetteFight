#pragma once
#include "Observer.h"

class Player2Life: public Observer
{
public:
	int life;
	Player2Life();
	~Player2Life();
	virtual bool ChangeValor(Scene* scene);
};