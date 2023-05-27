#include "game.hpp"
#include <windows.h>
#include <thread>

Game::Game()
{
    this->board.setHeight(23);
    this->board.setWidth(46);
    this->board.generateGrid();

    this->food.setSymbol('+');
    this->food.spawn(this->board);

    this->poison.setSymbol('~');
    this->poison.spawn(this->board);

    this->players.resize(this->player);
    this->players[0] = Snake('o',this->board,Direction::RIGHT,Control('w','s','a','d'));
    this->players[1] = Snake('*',this->board,Direction::DOWN,Control('i','k','j','l'));

}

std::vector<Snake> Game::getPlayers() const
{
    return this->players;
}

bool Game::gameOver()
{
    for (size_t i = 0; i < this->player; i++)
    {
        if (this->players[i].getLength() <= 0) return true;
        if (this->players[i].getHit() == true) return true;
    }
     return false;
}

void Game::setPlayers(unsigned num)
{
    this->player = num;
}

int Game::generateRandomFood()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution <> dis_x(1,2);
    int random = dis_x(gen);
    return random;
    
}

void Game::start()
{
    char input;
    input = _getch();
    while (!gameOver() && input != 'q')
    {   
        while(!_kbhit() && !gameOver())
        {
            this->food.render(this->board);
            this->poison.render(this->board);

           if (this->player == 2)
            {
                if (this->players[1].getAssisted() == true)
                {
                    
                    this->players[0].update(input, board);
                    this->players[0].render(this->board);
                    this->players[1].assistedMove(this->board);
                    this->players[1].render(this->board);
                }
                else if(this->players[1].getAssisted() == false)
                { 
                    this->players[0].update(input, board);
                    this->players[0].render(board);
                    this->players[1].update(input,board);
                    this->players[1].render(board);
                }
            }
            else if (this->player == 1)
            {
                this->players[0].update(input, board);
                this->players[0].render(board);
            }
        
            this->food.update(this->board);
            this->poison.update(this->board);
            this->board.render();
            this->board.clear();
        }
        input = _getch();

        if(input == 'p')
        {
            std::cout << "Your game is paused!\nPlease press any key to continue!";
            std::cin.get();
        }
        Sleep(5);
    }


    if (gameOver())
    {
        std::cout << "Game Over! \n";
    }   
    return;
}
