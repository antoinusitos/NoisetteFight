#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	currentState = State::isStanding;
	life = 100;
	damage = 5;
}

void Player::TakeDamage(int amount)
{
	if (currentState != State::isGuarding && currentState != State::isDead)
	{
		life -= amount;
		if (life <= 0)
		{
			currentState = State::isDead;
		}
	}
}

void Player::Attack()
{
	
}


int Player::GetPlayerID()
{
	
	return playerID;
}

Player::~Player()
{
	delete currentInputHandler;
}

Player::State Player::GetCurrentState()
{
	
	return currentState;
}