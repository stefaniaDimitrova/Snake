#include "../Headers/engine.hpp"

void Engine::start()
{
    int option = menus.DisplayMenu();

    if(option == 1) 
    {
        game.setPlayers(1);
        game.start();
    }

    else if (option == 2)
    {
        game.setPlayers(2);
        int player = menus.playerSettings();
        switch (player)
        {
        case 1:
            game.start();
            break;
        case 2:
            game.setAssisted(true);
            game.start();
        default:
            break;
        }
    }
    
    else if (option == 3)
    {
        int dificulty = menus.DisplayDifficultyMenu();
        switch (dificulty)
        {
        case 1:
            game.setSpeed(1);
            break;

        case 2:
            game.setSpeed(2);
            break;

        case 3:
            game.setSpeed(3);
            break;
        }

        std::cout << "Dificulty set! \n";
        start();
    }

    else if(option == 4) this->game.start();

    else if (option == 5) 
    {
        menus.DisplayHelp();
        start();
    }

    else return;

}