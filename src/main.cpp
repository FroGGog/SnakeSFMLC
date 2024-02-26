#include "headers/Game.h"


int main()
{
    Game game;


    while (game.windowOpen()) {
        game.update();

        game.render();

    }

    return 0;
}