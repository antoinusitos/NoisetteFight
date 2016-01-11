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
	void UpdateObservers();
	
	std::vector<Observer*>* observers;
	Player1* player1;
	Player2* player2;

	void RegisterObserver(Observer* theObserver);
	void UnregisterObserver(Observer* theObserver);

	void AddPlayer();
	int findPosition(Observer* theObserver);
};