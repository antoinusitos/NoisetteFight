// ProjetMoteur2D.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <SFML/Window.hpp>
#include "Fight.h"
#include "Scene.h"
#include "Player1.h"
#include "Player2.h" 
#include <time.h> 


int main()
{
	
	

	Mode* mode = new Fight();
	Scene* currentScene = mode->CreateScene();

	system("pause");
    return 0;
}