#include "stdafx.h"
#include "Player1Life.h"


Player1Life::Player1Life()
{
	
}

Player1Life::~Player1Life()
{
	
}

bool Player1Life::ChangeValor(Scene* scene)
{
	if (scene->player1->GetCurrentState() == scene->player1->isDead)
		return false;
	else
		return true;
}