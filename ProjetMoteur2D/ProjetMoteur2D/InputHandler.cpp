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

	jumpButton = new Jump();
	attackButton = new Attack();
	forwardButton = new Forward();
	backwardButton = new Backward();
	crouchButton = new Crouch();
	guardButton = new Guard();

	std::cout << "creation InputHandler " << currentPlayer->GetPlayerID() << std::endl;
}

InputHandler::~InputHandler()
{
	
}

void InputHandler::HandleInput(int theKey)
{
	if (theKey == jumpKey)
	{
		jumpButton->Execute(currentPlayer);
	}
	else if (theKey == attackKey)
	{
		attackButton->Execute(currentPlayer);
	}
	else if (theKey == forwardKey)
	{
		forwardButton->Execute(currentPlayer);
	}
	else if (theKey == backwardKey)
	{
		backwardButton->Execute(currentPlayer);
	}
	else if (theKey == crouchKey)
	{
		crouchButton->Execute(currentPlayer);
	}
	else if (theKey == guardKey)
	{
		guardButton->Execute(currentPlayer);
	}
}