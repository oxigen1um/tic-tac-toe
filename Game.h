#ifndef GAME_H
#define GAME_H

#include "config.h"

class Game : public Graph_lib::Window {

public:
    Game(Graph_lib::Point p, int width, int height, std::string title);

private:
    int board_size{10};
    Graph_lib::Button btn;
    static void cb_button(Graph_lib::Address, Graph_lib::Address);

    void click(Graph_lib::Address a);
};

#endif //GAME_H
