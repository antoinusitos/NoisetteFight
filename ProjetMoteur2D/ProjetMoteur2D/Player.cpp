#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	currentState = State::isStanding;
	life = 100;
	damage = 5;
}

Player::~Player()
{
	delete currentInputHandler;
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
int Player::GetPlayerID()
{
	return playerID;
}

void Player::SetCurrentState(State theState)
{
	currentState = theState;
}

Player::State Player::GetCurrentState()
{
	return currentState;
}

void Player::Crouch()
{
	currentState = State::isCrouching;
}

void Player::Jump()
{
	currentState = State::isJumping;
}

void Player::Stand()
{
	currentState = State::isStanding;
}