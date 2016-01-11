#pragma once
#include "Command.h"

class InputHandler
{
public:
	Command* jumpButton;
	Command* attackButton;
	Command* forwardButton;
	Command* backwardButton;
	Command* crouchButton;
	Command* guardButton;

	InputHandler();
	~InputHandler();
	
	void HandleInput();
};