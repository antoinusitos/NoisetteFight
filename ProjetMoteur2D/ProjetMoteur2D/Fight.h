#pragma once
#include "Mode.h"

class Fight : public Mode
{
public:
	virtual Scene* CreateScene();
	Fight();
	~Fight();
};