#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Game_window.h"
#include "config.h"
#include "constants.h"
#include "Cell.h"

class Game : public Game_window {
public:
    Game(Graph_lib::Point xy);

    Graph_lib::Button restart_button;

    void update_state (Graph_lib::Point p, int type);

    Cell& at (Graph_lib::Point p);

    static constexpr int N = field_side;
    static constexpr int N_max = 20;

    static_assert (N <= N_max, "do not allow board larger than N_max by N_max");

    void toggle_current_player() { current_player = (current_player % 2) + 1; } // 1 => 2 or 2 => 1

    void init_new_game();

    int get_current_player() const { return current_player; }

    Graph_lib::Rectangle rect{Graph_lib::Point{0, 0}, width, 70};
    Graph_lib::Text t{Graph_lib::Point{30, 50}, ""};

private:
    bool cells_blocked = false;

    void handle_restart()
    {
        init_new_game();
        detach( rect );
        detach(t);
    }

    static void cb_restart (Graph_lib::Address, Graph_lib::Address addr)
    {
        Graph_lib::reference_to<Game>(addr).handle_restart();
    }

    static constexpr int margin = 30;
    static constexpr int width = N * Cell::size + 2 * margin + 70;
    static constexpr int height = (N * Cell::size + 2 * margin) + 50;

    Graph_lib::Vector_ref<Cell> cells;

    int game_state[field_side][field_side];
    int current_player = 1; // 1 - for 'x' and  2 - for 'o'
    int clicked_buttons = 0;

    static void cb_clicked (Graph_lib::Address widget, Graph_lib::Address win)
    {
            Graph_lib::reference_to<Game>(win).clicked(widget);
    }

    void clicked (Graph_lib::Address widget);
};

#endif //GAME_H
