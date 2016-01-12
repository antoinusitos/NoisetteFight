#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	currentState = State::isStanding;
	life = 100;
	damage = 5;
	timeToCooldown = 0.3f;
}

Player::~Player()
{

}

void Player::TakeDamage(int amount)
{
	if (currentState != State::isGuarding && currentState != State::isDead)
	{
		life -= amount;
		std::cout << "Player " << playerID << " dispose de " << life << " points de vie !" << std::endl;
		if (life <= 0)
		{
			//std::cout << "mort" << std::endl;
			currentState = State::isDead;
		}
	}
	else if (currentState == State::isGuarding)
	{
		//std::cout << "je pars les degats !" << std::endl;
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

void Player::Block()
{
	//std::cout << "je block" << std::endl;
	currentState = State::isGuarding;
}

void Player::ResetPlayer()
{
	life = 100;
	currentState = State::isStanding;
}

void Player::Stand()
{
	currentState = State::isStanding;
}

int Player::GetDamage()
{
	return damage;
}

void Player::HasHit()
{
	cooldown = timeToCooldown;
}

bool Player::CanHit()
{
	if (cooldown < 0.0f)
		return true;
	return false;
}

void Player::Update(float deltaTime)
{
	cooldown -= deltaTime;
}