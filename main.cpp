#include <cmath>
#include <iostream>
#include <exception>

#include "config.h"

#include "Game.h"

using namespace Graph_lib;

int main()
try
{
   // Game game(Graph_lib::Point{100, 100}, game_width, game_height, "Tic-Tac-Toe");

    Game game{ Point{100, 100} };

    return Graph_lib::gui_main();
}
catch (std::exception& e) {
    std::cout << e.what() << std::endl;
    return 1;
}
catch (...) {
std::cout << "Exiting" << std::endl;
return 2;
}

