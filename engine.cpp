#include "engine.hpp"

void Engine::start()
{
    int option = interface.DisplayMenu();

    if(option == 1) 
    {
        game.setPlayers(1);
        game.start();
    }

    else if (option == 2)
    {
        game.setPlayers(2);
        int player = interface.playerSettings();
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
        int dificulty = interface.DisplayDifficultyMenu();
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
        interface.DisplayHelp();

        std::cout << "Press Enter to leave! \n";
        std::cin.get();
        start();
    }

    else return;

}