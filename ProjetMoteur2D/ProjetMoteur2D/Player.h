#pragma once
#include <vector>
#include "InputHandler.h"
#include "Hit.h"

class Scene;

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

	Player(Scene* scene);
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
	void Block();

	Scene* GetScene();

	void Update(float deltaTime);

	void HasHit();
	bool CanHit();

	int GetDamage();

	virtual void CreateCombos() = 0;

	void ResetPlayer();

private:

	int damage;
	int life;
	int keyAttack;

	float cooldown;
	float timeToCooldown;

	State currentState;
	Scene* theScene;

};