#pragma once
#include <vector>
#include "Player1.h"
#include "Player2.h"
#include <iostream>
#include <Windows.h>
#include <SFML/Window.hpp>
#include <time.h> 

class Observer;

class Scene
{
public:
	Scene();
	~Scene();
	void UpdateObservers();


	sf::Window window;
	time_t timer;
	double startTime;
	struct tm y2k;
	float deltatime;
	double newCurrentTime;
	double currentTime;
	
	std::vector<Observer*>* observers;
	Player1* player1;
	Player2* player2;


	void RegisterObserver(Observer* theObserver);
	void UnregisterObserver(Observer* theObserver);
	float GetTime();
	void EndGame();
	void Update();

	void AddPlayer();
	int findPosition(Observer* theObserver);
private:
	float gameTime;
	float test;
	bool inGame;
};