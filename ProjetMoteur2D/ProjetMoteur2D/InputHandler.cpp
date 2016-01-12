#include "stdafx.h"
#include "InputHandler.h"
#include "Jump.h"
#include "Attack.h"
#include "Backward.h"
#include "Forward.h"
#include "Crouch.h"
#include "Guard.h"
#include <iostream>
#include <SFML/Window.hpp>

InputHandler::InputHandler(Player* thePlayer)
{
	currentPlayer = thePlayer;

	if (currentPlayer->GetPlayerID() == 1)
	{
		jumpKey = sf::Keyboard::Z;
		attackKey = sf::Keyboard::T;
		forwardKey = sf::Keyboard::D;
		backwardKey = sf::Keyboard::Q;
		crouchKey = sf::Keyboard::S;
		guardKey = sf::Keyboard::R;
	}
	else if (currentPlayer->GetPlayerID() == 2)
	{
		jumpKey = sf::Keyboard::O;
		attackKey = sf::Keyboard::Y;
		forwardKey = sf::Keyboard::K;
		backwardKey = sf::Keyboard::M;
		crouchKey = sf::Keyboard::L;
		guardKey = sf::Keyboard::U;
	}

	jumpButton = new Jump(Player::State::isJumping);
	attackButton = new Attack(Player::State::isStanding);
	forwardButton = new Forward(Player::State::forward);
	backwardButton = new Backward(Player::State::backward);
	crouchButton = new Crouch(Player::State::isCrouching);
	guardButton = new Guard(Player::State::isGuarding);

	//std::cout << "creation InputHandler " << currentPlayer->GetPlayerID() << std::endl;

	inCombo = false;

	orientation = 0;
}

InputHandler::~InputHandler()
{
	delete jumpButton;
	delete attackButton;
	delete forwardButton;
	delete backwardButton;
	delete crouchButton;
	delete guardButton;
}

void InputHandler::HandleInput(int theKey)
{
	if (inCombo == false)
	{
		orientation = 0;
		inCombo = true;
	}

	if (theKey == jumpKey)
	{
		jumpButton->Execute(currentPlayer);
	}
	else if (theKey == forwardKey)
	{
		orientation = 1;
		forwardButton->Execute(currentPlayer);
	}
	else if (theKey == backwardKey)
	{
		orientation = -1;
		backwardButton->Execute(currentPlayer);
	}
	else if (theKey == crouchKey)
	{
		crouchButton->Execute(currentPlayer);
	}
	else if (theKey == guardKey)
	{
		inCombo = false;
		guardButton->Execute(currentPlayer);
	}
	else if (theKey == attackKey && currentPlayer->CanHit())
	{
		inCombo = false; 
		currentPlayer->HasHit();
		attackButton->Execute(currentPlayer);
		currentPlayer->SetCurrentState(Player::State::isStanding);
	}
}