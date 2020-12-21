#include "Game.h"
#include "constants.h"
#include "config.h"
#include "algo.h"
#include <sstream>
#include <memory>

Game::Game (Graph_lib::Point xy)
        : Game_window{ xy, width, height, "Tic-Tac-Toe" }
        , restart_button{ Graph_lib::Point{ x_max() - 80, 115 }, 70, 25, "Restart", cb_restart }
        , current_player{&p1}
        , p1{1, 'X', &p2}
        , p2{2, 'O', &p1}
{

    attach (restart_button);

    rect.set_fill_color(FL_GRAY);
    rect.set_color(FL_GRAY);

    t.set_font_size(36);
    t.set_color(Graph_lib::Color::dark_green);

    size_range (width, height, width, height); // fixed window size
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
             std::unique_ptr<Cell> cell {new Cell{Graph_lib::Point{margin + j * Cell::size,
                                                   (margin + (N - 1 - i) * Cell::size) + offset_top},
                                  cb_clicked, Graph_lib::Point{ field_side - 1 - i, j }} };

            // throw...

            attach(*cell);
            cells.push_back(cell.release());
        }

    // initial game state
    for(int i = 0; i < field_side; ++i)
        for(int j = 0; j < field_side; ++j)
            game_state[i][j] = 0;
}

void Game::init_new_game()
{
    current_player = &p1; // reset current player
    tt.set_label(std::to_string(current_player->id));

    for(int i = 0; i < field_side; ++i)
        for(int j = 0; j < field_side; ++j)
            game_state[i][j] = 0;

    for (int i = 0; i < cells.size(); ++i)
    {
        cells[i].set_full(false);
        cells[i].label = "";
    }

    clicked_buttons = 0; // update condition of draw end

    Fl::redraw();

    cells_blocked = false;
}


void Game::clicked (Graph_lib::Address widget)
{
    if (!cells_blocked) {

        // get coordinates of cell
        Fl_Widget &w = Graph_lib::reference_to<Fl_Widget>(widget);
        Cell &c = at(Graph_lib::Point{w.x(), w.y()});

        Graph_lib::Point array_pos = c.get_point();

        if (!c.is_full()) {

            c.label = current_player->label; // current
            tt.set_label(std::to_string(current_player->next->id)); // next

            c.toggle_full();
            Fl::redraw();

            // update game state
            update_state(array_pos, current_player->id);

            // check end of game condition
            bool is_finished = check_end(game_state, array_pos.x, array_pos.y);

            if (is_finished) {
                std::cout << "Winner: " << current_player->id << std::endl;

                cells_blocked = true;

                std::ostringstream oss;

                oss << "Winner player: " << current_player->id;
                std::string message = oss.str();

                t.set_label(message);

                attach( rect );
                attach(t);
            }
            else
                toggle_current_player();

            clicked_buttons += 1;
        }

        if ((clicked_buttons == field_side * field_side) && (!cells_blocked)) {
            t.set_label("It's a draw!");

            attach( rect );
            attach(t);
        }
    }
}

Cell& Game::at (Graph_lib::Point p)
{
    int i = N - 1 - (p.y - margin - offset_top) / Cell::size;
    int j = (p.x - margin) / Cell::size;

    return cells[i*N + j];
}

void Game::update_state (Graph_lib::Point p, int type)
{
    game_state[p.x][p.y] = type;
}

