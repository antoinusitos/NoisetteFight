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

	InputHandler* currentInputHandler;

	int GetPlayerID();
	State GetCurrentState();

	int playerID;

	void Crouch();
	void Jump();
	void Stand();

private:

	int damage;
	int life;
	int keyAttack;

	State currentState;

};