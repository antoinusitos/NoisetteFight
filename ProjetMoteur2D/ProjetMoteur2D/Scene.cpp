#include "Scene.h"

Scene::Scene()
{
	observers = new std::vector<Observer*>();
	
}

Scene::~Scene()
{
	
}

void Scene::AddPlayer()
{
	player1 = new Player1();
	player2 = new Player2();
}

void Scene::NotifyObservers()
{
	
}

void Scene::RegisterObserver(Observer theObserber)
{
	
}

void Scene::UnregisterObserver(Observer theObserber)
{
	
}