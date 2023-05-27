#include "ui.hpp"
#include "game.hpp"

class Engine
{
    private:
    UI interface;
    Game game;

    public:
    Engine () = default;
    void start();
};
