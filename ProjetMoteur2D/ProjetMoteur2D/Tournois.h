#pragma once
#include "Mode.h"

class Tournois : public Mode
{
public:
	virtual Scene* CreateScene();
	Tournois();
	~Tournois();
};