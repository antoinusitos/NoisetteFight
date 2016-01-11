#pragma once
#include "Scene.h"

class Observer
{
public:

	virtual bool ChangeValor(Scene* scene)=0;

	Observer();
	~Observer();
};