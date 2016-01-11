#include "stdafx.h"
#include "Hit.h"
#include "Player.h"
#include "Sequence.h"

void Hit::Add(Combo* newChild)
{
	child = newChild;
}

void Hit::Remove()
{
	delete child;
}

Combo* Hit::GetChildren()
{
	return child;
}

Hit::Hit()
{
	
}

Hit::~Hit()
{
	delete child;
}

std::vector<Sequence*>* Hit::GetSequence()
{
	return theSequence;
}

void Hit::AjouteEtat(Sequence* etat)
{
	theSequence->push_back(etat);
}

bool Hit::CheckSequence(Player* thePlayer)
{
	bool seq1 = false;
	bool seq2 = false;
	for (std::vector<Sequence*>::iterator it = theSequence->begin(); it != theSequence->end(); ++it)
	{
		Player::State theState = (*it)->GetCurrentState();
		if (theState == Player::State::isJumping && thePlayer->GetCurrentState() == theState)
		{
			if(!seq1)
				seq1 = true;
			else
				seq2 = true;
		}
		else if (theState == Player::State::isCrouching && thePlayer->GetCurrentState() == theState)
		{
			if (!seq1)
				seq1 = true;
			else
				seq2 = true;
		}
		else if (theState == Player::State::forward && thePlayer->currentInputHandler->orientation == 1)
		{
			if (!seq1)
				seq1 = true;
			else
				seq2 = true;
		}
		else if (theState == Player::State::backward && thePlayer->currentInputHandler->orientation == -1)
		{
			if (!seq1)
				seq1 = true;
			else
				seq2 = true;
		}
		else
		{
			return false;
		}
	}
	if (theSequence->size() == 1 && seq1)
		return true;
	else if (theSequence->size() == 2 && seq1 && seq2)
		return true;
	else
		return false;
}