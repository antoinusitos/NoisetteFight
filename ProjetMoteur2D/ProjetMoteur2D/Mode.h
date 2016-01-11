#pragma once
#include "Scene.h"

class Mode
{
public:
	virtual Scene* CreateScene() = 0;
	Mode();
	~Mode();
};