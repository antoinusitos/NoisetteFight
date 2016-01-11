#pragma once

#include "InputHandler.h"

class Player
{
public:

	enum State
	{
		isCrouching,
		isJumping,
		isDead,
		isStanding,
		isGuarding,

	};

	Player();
	~Player();

	void TakeDamage(int amount);
	void Attack();
	int GetPlayerID();

	InputHandler* currentInputHandler;

	State GetCurrentState();

	int playerID;

private:

	int damage;
	int life;
	int keyAttack;

	State currentState;

};