#pragma once

#include <iostream>

class Command;
class Player;

class InputHandler
{
public:
	Command* jumpButton;
	Command* attackButton;
	Command* forwardButton;
	Command* backwardButton;
	Command* crouchButton;
	Command* guardButton;

	int jumpKey;
	int attackKey;
	int forwardKey;
	int backwardKey;
	int crouchKey;
	int guardKey;

	Player* currentPlayer;

	InputHandler(Player* thePlayer);
	~InputHandler();
	
	void HandleInput(int theKey);
};