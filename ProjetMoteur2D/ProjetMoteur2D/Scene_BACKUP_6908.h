#pragma once
#include "Scene.h"
#include "Observer.h"
#include <vector>
#include "Observer.h"
#include "Player1.h"
#include "Player2.h"

class Scene
{
public:
<<<<<<< HEAD
=======
	std::vector<Observer*>* Observers; 
>>>>>>> Antoine
	Scene();
	~Scene();
	void UpdateObservers();
	
<<<<<<< HEAD
	std::vector<Observer*>* observers;
	Player1* player1;
	Player2* player2;

	void RegisterObserver(Observer* theObserver);
	void UnregisterObserver(Observer* theObserver);

	void AddPlayer();
	int findPosition(Observer* theObserver);
=======
	void RegisterObserver(Observer* theObserver);
	void UnregisterObserver(Observer* theObserver);
	void NotifyObservers();
>>>>>>> Antoine
};