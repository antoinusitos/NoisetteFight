#pragma once

class Scene;

class Observer
{
public:

	virtual bool ChangeValor(Scene* scene) = 0;

	Observer();
	~Observer();
};