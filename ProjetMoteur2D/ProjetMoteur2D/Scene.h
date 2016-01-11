#pragma once
#include "Scene.h"
#include <vector>
#include "Observer.h"
#include "Player1.h"
#include "Player2.h"

class Scene
{
public:
	Scene();
	~Scene();
	
	std::vector<Observer*>* observers;
	Player1* player1;
	Player2* player2;

	void RegisterObserver(Observer theObserber);
	void UnregisterObserver(Observer theObserver);
	void NotifyObservers();
	void AddPlayer();
};