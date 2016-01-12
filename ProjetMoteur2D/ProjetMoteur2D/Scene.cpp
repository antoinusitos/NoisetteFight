#include "stdafx.h"
#include "Scene.h"
#include "Observer.h"
#include "Time.h"
#include "Player1Life.h"
#include "Player2Life.h"

Scene::Scene()
{
	std::cout << "Bienvenue dans la faille de l'invocateur " << std::endl;
	
	observers = new std::vector<Observer*>();
	system("pause");
	AddPlayer();

	theTime = new Time();
	p1Life = new Player1Life();
	p2Life = new Player2Life();
	RegisterObserver(theTime);
	RegisterObserver(p1Life);
	RegisterObserver(p2Life);
	gameTime = 1000.0f;
	
	inGame = false;
	prepare = true;
	prepareToFight = 4.0f;
	prepareToFightPrev = prepareToFight;
	Start();
}

Scene::~Scene()
{
	delete(p1Life);
	delete(p2Life);
	delete(observers);
	delete(theTime);
	delete(player1);
	delete(player2);
}


void Scene::UpdateObservers()
{
	for (int i = 0; i < observers->size(); ++i)
	{
		bool test = observers->at(i)->ChangeValor(this);
		if (test == false && inGame)
		{
			EndGame();
			break;
		}
	}
}

void Scene::EndGame()
{
	inGame = false;
	if (player1->GetCurrentState() == player1->isDead)
	{
		std::cout << "Player 2 win ! " << std::endl;
	}
	else if (player2->GetCurrentState() == player2->isDead)
	{
		std::cout << "Player 1 win ! "<< std::endl;
	}
	else
		std::cout << "Time Out ! " << std::endl;

	std::cout << "PRESS N TO RESTART " << std::endl;
}

float Scene::GetTime()
{
	return gameTime;
}

void Scene::AddPlayer()
{
	player1 = new Player1(this);
	player2 = new Player2(this);
}

void Scene::RegisterObserver(Observer* theObserver)
{
	observers->push_back(theObserver);
}

void Scene::UnregisterObserver(Observer* theObserver)
{
	observers->erase(observers->begin()+(findPosition(theObserver)));
}

void Scene::Start()
{
	startTime = 0;
	y2k = { 0 };
	y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
	y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;
	time(&timer);
	startTime = difftime(timer, mktime(&y2k));
	deltatime = 0;
	newCurrentTime = 0;
	currentTime = 0;
	
	std::cout << "PREPARE TO FIGHT !! " << std::endl;
	

	Update();
}

void Scene::Update()
{
	sf::Window window(sf::VideoMode(0, 0), "My window");
	while (window.isOpen())
	{
		time(&timer);

		newCurrentTime = difftime(timer, mktime(&y2k)) - startTime;
		deltatime = (float)(newCurrentTime - currentTime);
		currentTime = newCurrentTime;

		gameTime -= deltatime;

		UpdateObservers();

		UpdateGame();

		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;
		while (window.pollEvent(event))
		{
			// évènement "fermeture demandée" : on ferme la fenêtre
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(event.key.code) && inGame)
			{
				player1->currentInputHandler->HandleInput(event.key.code);
				player2->currentInputHandler->HandleInput(event.key.code);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N) && inGame == false && prepare == false)
			{
				system("cls");
				//std::cout << "restart!" << std::endl;
				player1->ResetPlayer();
				player2->ResetPlayer();
				gameTime = 1000.0f;
				prepareToFight = 4.0f;
				prepareToFightPrev = prepareToFight;
				prepare = true;
				std::cout << "PREPARE TO FIGHT !! " << std::endl;
			}
		}
	}
}

void Scene::UpdateGame()
{
	if (prepare)
	{
		prepareToFight -= deltatime;
		if (prepareToFight <= prepareToFightPrev - 1.0f)
		{
			prepareToFightPrev = prepareToFight;
			if (prepareToFight <= 0.0f)
			{
				std::cout << "FIGHT!" << std::endl;
				prepare = false;
				inGame = true;
			}
			else
				std::cout << prepareToFight << std::endl;
		}
	}
	else
	{
		player1->Update(deltatime);
		player2->Update(deltatime);
	}
}


int Scene::findPosition(Observer* theObserver)
{
	for (int i = 0; i < observers->size(); ++i)
	{
		if (observers->at(i) == theObserver)
		{
			return i;
		}
	}
	return 0;
}
