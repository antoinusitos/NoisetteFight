#pragma once
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

	State GetCurrentState();
	void SetCurrentState(State theState);

	int playerID;

	int GetPlayerID();

	virtual void CheckCombo() = 0;

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