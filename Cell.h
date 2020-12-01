#ifndef GAME_CELL_H
#define GAME_CELL_H

#include "config.h"

class Cell : public Graph_lib::Button {
public:

    Cell(Graph_lib::Point xy, int size);

private:
    bool is_pushed {false};
    bool is_marked {false};
    bool is_open {false};
    int bombs_around {0};
};

#endif //GAME_CELL_H
