#pragma once

#include <iostream>

class Sequence;
class Player;

class InputHandler
{
public:
	Sequence* jumpButton;
	Sequence* attackButton;
	Sequence* forwardButton;
	Sequence* backwardButton;
	Sequence* crouchButton;
	Sequence* guardButton;

	int jumpKey;
	int attackKey;
	int forwardKey;
	int backwardKey;
	int crouchKey;
	int guardKey;

	int orientation; //-1 backward, 0 stand, 1 forward

	bool inCombo;

	Player* currentPlayer;

	InputHandler(Player* thePlayer);
	~InputHandler();
	
	void HandleInput(int theKey);
};