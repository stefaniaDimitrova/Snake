#include "ui.hpp"
#include "game.hpp"

class Engine
{
    private:
    UI menus;
    Game game;

    public:
    Engine () = default;
    void start();
};
