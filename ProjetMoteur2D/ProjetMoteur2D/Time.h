#pragma once
#include "Observer.h"

class Time : public Observer
{
public:
	int time;
	Time();
	~Time();
	virtual bool ChangeValor(Scene* scene);
};