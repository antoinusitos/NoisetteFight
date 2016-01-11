#pragma once
#include "Scene.h"
#include "Observer.h"
#include <vector>

class Scene
{
public:
	std::vector<Observer*>* Observers; 
	Scene();
	~Scene();
	
	void RegisterObserver(Observer* theObserver);
	void UnregisterObserver(Observer* theObserver);
	void NotifyObservers();
};