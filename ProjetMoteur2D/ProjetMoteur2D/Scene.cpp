#include "stdafx.h"
#include "Scene.h"

Scene::Scene()
{
	Observers = new std::vector<Observer*>();
}

Scene::~Scene()
{
	
}

void Scene::NotifyObservers()
{
	
}

void Scene::RegisterObserver(Observer* theObserver)
{
	
}

void Scene::UnregisterObserver(Observer* theObserver)
{
	
}