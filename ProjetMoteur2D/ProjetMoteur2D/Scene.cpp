#include "stdafx.h"
#include "Scene.h"

Scene::Scene()
{
	observers = new std::vector<Observer*>();
	
}

Scene::~Scene()
{
	
}

void Scene::UpdateObservers()
{

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
