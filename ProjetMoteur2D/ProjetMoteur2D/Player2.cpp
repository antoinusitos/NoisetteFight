#include "stdafx.h"
#include "Player2.h"

#include "Jump.h"
#include "Forward.h"
#include "Backward.h"
#include "Crouch.h"

#include "Scene.h"

Player2::Player2(Scene* scene) : Player::Player(scene)
{
	playerID = 2;

	currentInputHandler = new InputHandler(this);

	combos = new std::vector<Hit*>();

	CreateCombos();
}

Player2::~Player2()
{
	delete currentInputHandler;
	delete combos;
}

void Player2::ResetEtat()
{
	SetCurrentState(State::isStanding);
}

void Player2::CreateCombos()
{
	Hit* hit1 = new Hit();
	Hit* hit2 = new Hit();
	Hit* hit3 = new Hit();
	Hit* hit4 = new Hit();
	Hit* hit5 = new Hit();
	Hit* hit6 = new Hit();
	Hit* hit7 = new Hit();
	Hit* hit8 = new Hit();

	Sequence* j = currentInputHandler->jumpButton;
	Sequence* c = currentInputHandler->crouchButton;
	Sequence* f = currentInputHandler->forwardButton;
	Sequence* b = currentInputHandler->backwardButton;

	hit1->AjouteEtat(j);
	hit1->AjouteEtat(f);
	hit1->SetMultiply(2.5f);

	hit2->AjouteEtat(c);
	hit2->AjouteEtat(f);
	hit2->SetMultiply(2.5f);

	hit3->AjouteEtat(f);
	hit3->SetMultiply(1.5f);

	hit4->AjouteEtat(b);
	hit4->SetMultiply(1.5f);

	hit5->AjouteEtat(j);
	hit5->SetMultiply(1.5f);

	hit6->AjouteEtat(c);
	hit6->SetMultiply(1.5f);

	hit7->AjouteEtat(j);
	hit7->AjouteEtat(b);
	hit7->SetMultiply(2.5f);

	hit8->AjouteEtat(c);
	hit8->AjouteEtat(b);
	hit8->SetMultiply(2.5f);

	combos->push_back(hit1);
	combos->push_back(hit2);
	combos->push_back(hit3);
	combos->push_back(hit4);
	combos->push_back(hit5);
	combos->push_back(hit6);
	combos->push_back(hit7);
	combos->push_back(hit8);
}

void Player2::CheckCombo()
{
	bool retour = false;
	int nbCoups = 0;
	Hit* theHit = nullptr;
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
	else if (theHit != nullptr)
	{
		multiply = theHit->GetMultiply();
	}
	else
	{
		multiply = 1.0f;
	}

	//std::cout << "send damage" << std::endl;
	GetScene()->player1->TakeDamage((int)(GetDamage()*multiply));
}