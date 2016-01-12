#include "stdafx.h"
#include "Time.h"
#include <iostream>

Time::Time()
{
	
}

Time::~Time()
{
	
}


bool Time::ChangeValor(Scene* scene)
{
	time = (int)scene->GetTime();
	if (time <= 0)
	{
		return false;
	}
	return true;
}