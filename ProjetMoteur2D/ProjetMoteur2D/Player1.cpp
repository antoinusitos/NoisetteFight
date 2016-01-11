#include "stdafx.h"
#include "Player1.h"
#include <iostream>

#include "Jump.h"
#include "Forward.h"
#include "Backward.h"
#include "Crouch.h"

Player1::Player1() : Player::Player()
{
	std::cout << "creation Player " << std::endl;
	playerID = 1;

	currentInputHandler = new InputHandler(this);

	combos = new std::vector<Hit*>();

	CreateCombos();
}

Player1::~Player1()
{
	
}

void Player1::ResetEtat()
{
	SetCurrentState(State::isStanding);
}

void Player1::CreateCombos()
{
	Hit* hit1 = new Hit();
	Sequence* j = currentInputHandler->jumpButton;
	Sequence* f = currentInputHandler->forwardButton;

	hit1->AjouteEtat(j);
	hit1->AjouteEtat(f);




	combos->push_back(hit1);
}

void Player1::CheckCombo()
{
	bool retour = false;
	for (std::vector<Hit*>::iterator it = combos->begin(); it != combos->end(); ++it)
	{
		//recherche dans tous les combos
		retour = (*it)->CheckSequence(this);
		if (retour)
			break;
	};

	if (retour == false) //pas de combo trouve
	{

	}
	else
	{
		//envoyer les degats
	}
}