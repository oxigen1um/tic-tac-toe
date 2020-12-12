#ifndef TICTACTOE_GAME_WINDOW_H
#define TICTACTOE_GAME_WINDOW_H

#include "config.h"

struct Game_window : public Graph_lib::Window
{
    Game_window (Graph_lib::Point xy, int w, int h, const std::string& title)
    : Window{ xy, w, h, title }
    , quit_button{ Graph_lib::Point{x_max() - 80, 80}, 70, 25, "Quit", cb_quit }
    , restart_button{ Graph_lib::Point{ x_max() - 80, 115 }, 70, 25, "Restart", cb_restart }
    , t{Graph_lib::Point{30, 50}, "Current player:"}
    , tt{Graph_lib::Point{280, 50}, "1"}
    {
        t.set_font_size(36);
        tt.set_font_size(36);
        tt.set_color(Graph_lib::Color::dark_green);

        attach (quit_button);
        attach (restart_button);
        attach (t);
        attach (tt);
    }

    Graph_lib::Button quit_button;
    Graph_lib::Button restart_button;
    Graph_lib::Text t, tt;

    void wait_for_button()
    {
        while (!button_pushed) Fl::wait();
        button_pushed = false;
        Fl::redraw();
    }

private:

    bool button_pushed = false;

    static void cb_quit (Graph_lib::Address, Graph_lib::Address addr)
    {
        Graph_lib::reference_to<Game_window>(addr).quit();
    }

    static void cb_restart (Graph_lib::Address, Graph_lib::Address addr)
    {
        Graph_lib::reference_to<Game_window>(addr).handle_restart();
    }

      void handle_restart()
    {
        button_pushed = true;
    }

    void quit() { hide(); }
};

#endif //TICTACTOE_GAME_WINDOW_H
