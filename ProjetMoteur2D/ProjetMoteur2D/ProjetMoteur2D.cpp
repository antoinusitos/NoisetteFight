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
	int choix = 0;
	while (choix != 1 && choix != 4)
	{
		system("cls");
		std::cout << "Choisissez un mode de jeu : " << std::endl;
		std::cout << "1 - Combat rapide " << std::endl;
		std::cout << "2 - Tournois " << std::endl;
		std::cout << "3 - Aventure " << std::endl;
		std::cout << "4 - Quitter " << std::endl;
		std::cin >> choix;
		if (choix == 1)
		{
			system("cls");
			Mode* mode = new Fight();
			Scene* currentScene = mode->CreateScene();
		}
		else if (choix == 4)
		{
			system("exit");
		}
	}

	//system("pause");
    return 0;
}