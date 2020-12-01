#include <cmath>
#include <iostream>
#include <exception>

#include "config.h"
#include "constants.h"

#include "Game.h"

int main ()
try
{
    Game game(Graph_lib::Point{100, 100}, game_width, game_height, "Tic-Tac-Toe");



    return Graph_lib::gui_main();
}
catch (std::exception& e)
{
    std::cerr << e.what() << std::endl;
    return 1;
}
catch (...)
{
    std::cerr << "Oops, something went wrong..." << std::endl;
    return 2;
}
