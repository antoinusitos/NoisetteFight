#include "stdafx.h"
#include "Player2.h"

#include "Jump.h"
#include "Forward.h"
#include "Backward.h"
#include "Crouch.h"

#include "Scene.h"

Player2::Player2(Scene* scene) : Player::Player()
{
	playerID = 2;

	currentInputHandler = new InputHandler(this);

	combos = new std::vector<Hit*>();

	theScene = scene;

	CreateCombos();
}

Player2::~Player2()
{
	delete currentInputHandler;
}

void Player2::ResetEtat()
{
	SetCurrentState(State::isStanding);
}

void Player2::CreateCombos()
{
	Hit* hit1 = new Hit();
	Sequence* j = currentInputHandler->jumpButton;
	Sequence* f = currentInputHandler->forwardButton;

	hit1->AjouteEtat(j);
	hit1->AjouteEtat(f);




	combos->push_back(hit1);
}

void Player2::CheckCombo()
{
	bool retour = false;
	int nbCoups = 0;
	for (std::vector<Hit*>::iterator it = combos->begin(); it != combos->end(); ++it)
	{
		//recherche dans tous les combos
		retour = (*it)->CheckSequence(this);
		if (retour)
		{
			nbCoups = (*it)->GetNumberSequence();
			break;
		}
	};

	if (retour == false) //pas de combo trouve
	{
		multiply = 1.0f;
	}
	else
	{
		if (nbCoups == 1)
			multiply = 1.5f;
		else if (nbCoups == 2)
			multiply = 2.5f;
	}

	//std::cout << "send damage" << std::endl;
	theScene->player1->TakeDamage((int)(GetDamage()*multiply));
}