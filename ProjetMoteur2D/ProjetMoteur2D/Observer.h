#pragma once
#include "Scene.h"

class Observer
{
public:

	virtual bool ChangeValor(Scene* scene);

	Observer();
	~Observer();
};