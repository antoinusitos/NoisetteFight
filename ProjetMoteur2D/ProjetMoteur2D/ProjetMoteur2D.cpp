// ProjetMoteur2D.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Fight.h"
#include "Scene.h"


int main()
{
	Mode* mode = new Fight();
	Scene* currentScene = mode->CreateScene();

    return 0;
}

