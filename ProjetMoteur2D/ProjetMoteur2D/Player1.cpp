#include "stdafx.h"
#include "Player1.h"
#include <iostream>

#include "Jump.h"
#include "Forward.h"
#include "Backward.h"
#include "Crouch.h"

#include "Scene.h"

Player1::Player1(Scene* scene) : Player::Player()
{
	std::cout << "creation Player " << std::endl;
	playerID = 1;

	currentInputHandler = new InputHandler(this);

	combos = new std::vector<Hit*>();

	theScene = scene;

	CreateCombos();

}

Player1::~Player1()
{
	delete currentInputHandler;
}

void Player1::ResetEtat()
{
	SetCurrentState(State::isStanding);
}

void Player1::CreateCombos()
{
	Hit* hit1 = new Hit();
	Hit* hit2 = new Hit();
	Hit* hit3 = new Hit();

	Sequence* j = currentInputHandler->jumpButton;
	Sequence* c = currentInputHandler->crouchButton;
	Sequence* f = currentInputHandler->forwardButton;

	hit1->AjouteEtat(j);
	hit1->AjouteEtat(f);

	hit2->AjouteEtat(c);
	hit2->AjouteEtat(f);

	hit3->AjouteEtat(f);


	combos->push_back(hit1);
	combos->push_back(hit2);
	combos->push_back(hit3);
}

void Player1::CheckCombo()
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
		else if(nbCoups == 2)
			multiply = 2.5f;
	}

	//std::cout << "send damage" << std::endl;
	theScene->player2->TakeDamage((int)(GetDamage()*multiply));
}