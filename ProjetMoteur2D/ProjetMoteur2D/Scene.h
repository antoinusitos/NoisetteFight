#pragma once
#include "Scene.h"
#include <vector>

class Scene
{
public:
	vector<Observer> Observers; 
	Scene();
	~Scene();
	
	void RegisterObserver(Observer theObserber);
	void UnregisterObserver(Observer theObserver);
	void NotifyObservers();
};