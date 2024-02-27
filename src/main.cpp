#include "headers/Game.h"
#include <ctime>

int main()
{
    srand(time(0));

    Game game;

    while (game.windowOpen()) {
        game.update();

        game.render();

    }

    return 0;
}