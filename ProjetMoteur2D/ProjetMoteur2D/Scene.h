#pragma once
#include <vector>
#include "Player1.h"
#include "Player2.h"

class Observer;

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