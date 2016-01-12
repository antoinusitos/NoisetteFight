#include "stdafx.h"
#include "Player2Life.h"

Player2Life::Player2Life()
{
	
}

Player2Life::~Player2Life()
{
	
}

bool Player2Life::ChangeValor(Scene* scene)
{
	if (scene->player2->GetCurrentState() == scene->player2->isDead)
		return false;
	else
		return true;
}