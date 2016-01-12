#include "stdafx.h"
#include "Scene.h"
#include "Observer.h"
#include "Time.h"
#include "Player1Life.h"
#include "Player2Life.h"

Scene::Scene()
{
	std::cout << "yolo " << std::endl;
	observers = new std::vector<Observer*>();
	system("pause");
	AddPlayer();

	Time* time_t = new Time();
	Player1Life* p1Life = new Player1Life();
	Player2Life* p2Life = new Player2Life();
	RegisterObserver(time_t);
	RegisterObserver(p1Life);
	RegisterObserver(p2Life);
	gameTime = 1000.0f;
	
	

	Update();
}

Scene::~Scene()
{
	
}


void Scene::UpdateObservers()
{
	for (int i = 0; i < observers->size(); ++i)
	{
		bool test = observers->at(i)->ChangeValor(this);
		if (test == false)
		{
			EndGame();
			break;
		}
	}
}

void Scene::EndGame()
{
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
}

float Scene::GetTime()
{
	return gameTime;
}

void Scene::AddPlayer()
{
	player1 = new Player1();
	player2 = new Player2();
}

void Scene::RegisterObserver(Observer* theObserver)
{
	observers->push_back(theObserver);
}

void Scene::UnregisterObserver(Observer* theObserver)
{
	observers->erase(observers->begin()+(findPosition(theObserver)));
}

void Scene::Update()
{
	sf::Window window(sf::VideoMode(0, 0), "My window");	startTime = 0;
	y2k = { 0 };
	y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
	y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;
	time(&timer);
	startTime = difftime(timer, mktime(&y2k));
	deltatime = 0;
	newCurrentTime = 0;
	currentTime = 0;
	while (window.isOpen())
	{
		time(&timer);

		newCurrentTime = difftime(timer, mktime(&y2k)) - startTime;
		deltatime = newCurrentTime - currentTime;
		currentTime = newCurrentTime;

		gameTime -= deltatime;
		
		UpdateObservers();
		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;

		test += deltatime;
		if (test > 1)
		{
			player1->TakeDamage(20);
			test = 0;
		}

		/*while (window.isOpen())
		{
		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;
		while (window.pollEvent(event))
		{
		// évènement "fermeture demandée" : on ferme la fenêtre
		if (event.type == sf::Event::Closed)
		window.close();

		if (sf::Keyboard::isKeyPressed(event.key.code))
		{
		p->currentInputHandler->HandleInput(event.key.code);
		p2->currentInputHandler->HandleInput(event.key.code);
		}
		}
		}*/

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
