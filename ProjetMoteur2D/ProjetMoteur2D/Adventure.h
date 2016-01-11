#pragma once
#include "Mode.h"

class Adventure : public Mode
{
public:
	virtual Scene* CreateScene();
	Adventure();
	~Adventure();
};