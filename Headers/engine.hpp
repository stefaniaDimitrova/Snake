#include "ui.hpp"
#include "game.hpp"

/*! Class engine that runs the game */
class Engine
{
    /*! It has UI and a game in its body */
    private:
    UI menus;
    Game game;

    public:
    /*! Default constructor */
    Engine () = default;

    /*! Method that starts the game */
    void start();
};
