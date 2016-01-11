#pragma once
#include "stdafx.h"
#include "Scene.h"

class Mode
{
public:
	virtual Scene* CreateScene() = 0;
	Mode();
	~Mode();
};