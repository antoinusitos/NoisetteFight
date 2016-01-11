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


int main()
{

/*Mode* mode = new Fight();
Scene* currentScene = mode->CreateScene();*/

sf::Window window(sf::VideoMode(0, 0), "My window");

	Player1* p = new Player1();
	Player2* p2 = new Player2();


	while (window.isOpen())
	{
		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;
		while (window.isOpen())
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
		}

	}    
	
	return 0;
}