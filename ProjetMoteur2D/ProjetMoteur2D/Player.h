#pragma once
#include "Observer.h"
#include <vector>
#include "InputHandler.h"
#include "Hit.h"

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
		forward,
		backward
	};

	Player();
	~Player();

	void TakeDamage(int amount);

	InputHandler* currentInputHandler;

	int GetPlayerID();
	State GetCurrentState();
	void SetCurrentState(State theState);

	int playerID;

	void Crouch();
	void Jump();
	void Stand();

	int GetDamage();

	virtual void CreateCombos() = 0;

private:

	int damage;
	int life;
	int keyAttack;

	State currentState;

};