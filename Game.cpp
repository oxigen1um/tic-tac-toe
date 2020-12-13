#include "Game.h"
#include "constants.h"
#include "config.h"
#include "algo.cpp"
#include "Alert.h"

Game::Game (Graph_lib::Point xy)
        : Game_window{ xy, width, height, "Tic-Tac-Toe" }
        , restart_button{ Graph_lib::Point{ x_max() - 80, 115 }, 70, 25, "Restart", cb_restart }
        , button_pushed{false}
{

    attach (restart_button);

    size_range (width, height, width, height); // fixed window size
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cells.push_back(new Cell{Graph_lib::Point{margin + j * Cell::size,
                                                      (margin + (N - 1 - i) * Cell::size) + offset_top},
                                     cb_clicked, Graph_lib::Point{ field_side - 1 - i, j }}); // we use (field_side - 1 - i) because we store cell in 1-dimensional array but algorithm calculates the winner using matrix
            attach(cells[cells.size() - 1]);

        }


    // initial game state
    for(int i = 0; i < field_side; ++i)
        for(int j = 0; j < field_side; ++j)
            game_state[i][j] = 0;

// create figures here, later
}


void Game::init_new_game(std::string type)
{

    if (type == "winner" || type == "draw")
    {
        std::string str;

        if (type == "draw") str = "It's a draw!";
        else if (current_player == 1) str = "Player 1 win!";
        else str = "Player 2 win!";

    Alert winner{Graph_lib::Point{200, 200}, 200, 100, "Game over", str}; //make widget => press ok button => FL::redraw();
    wait_for_button();
    }


    current_player = 1; // reset current player
    tt.set_label("1");

    for(int i = 0; i < field_side; ++i)
        for(int j = 0; j < field_side; ++j)
            game_state[i][j] = 0;

    for (int i = 0; i < cells.size(); ++i) {
        cells[i].set_full(false);
        cells[i].label = "";
    }

    Fl::redraw();
}


void Game::clicked (Graph_lib::Address widget)
{
    // get coordinates of cell
    Fl_Widget& w = Graph_lib::reference_to<Fl_Widget>(widget);
    Cell& c = at (Graph_lib::Point{w.x(), w.y()});

    Graph_lib::Point array_pos = c.get_point();

    if (!c.is_full()) {

        // fill cell with symbol
        if (get_current_player() == 1)
        {
            c.label = 'X';
            tt.set_label("2");
        }
        else
        {
            c.label = 'O';
            tt.set_label("1");
        }

        c.toogle_full();

        Fl::redraw();

//        std::cout << w.x() << " " << w.y() << std::endl; // coordinates
//        std::cout << array_pos.x << " " << array_pos.y << std::endl;


        // todo: update game state

        update_state(array_pos, get_current_player());

        // todo: check_end
        bool is_finished = check_end(game_state, array_pos.x, array_pos.y);

        if (is_finished)
        {
            std::cout << "Winner: " << get_current_player() << std::endl;

             //Graph_lib::Line l = {Graph_lib::Point{w.x(), w.y()}, Graph_lib::Point{w.x() - 50, w.y() - 50}};

           // l.set_color(Graph_lib::Color::red);


           // attach (l);
            init_new_game("winner");

            //detach(l);
        }
        else
            toggle_current_player();
    }

    clicked_buttons += 1;

    if (clicked_buttons >= field_side * field_side)
    {
        init_new_game("draw");
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

