#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H

#include "My_window.h"
#include "Cell.h"

class Board : public My_window {
public:
    Board(Graph_lib::Point xy);

    Cell& at (Graph_lib::Point p);
    Cell& at (char c, int i);

    static constexpr int N = 15;
    static constexpr int N_max = 20;

    static_assert (N <= N_max, "do not allow board larger than N_max by N_max");

private:
    static constexpr int margin = 30;
    static constexpr int width = N * Cell::size + 2 * margin + 70;
    static constexpr int height = N * Cell::size + 2 * margin;

    Graph_lib::Vector_ref<Cell> cells; // Vector of link

    static void cb_clicked (Graph_lib::Address widget, Graph_lib::Address win)
    {
        Graph_lib::reference_to<Board>(win).clicked(widget);
    }

    void clicked (Graph_lib::Address widget);
};


#endif //TICTACTOE_BOARD_H
