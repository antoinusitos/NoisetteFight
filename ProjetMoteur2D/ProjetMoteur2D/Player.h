#pragma once
#include "Observer.h"

class Player
{
public:
	int damage;
	int life;
	int playerID;
	int keyAttack;
	
	void takeDamage(int life);
	void attack();

	Player();
	~Player();
};