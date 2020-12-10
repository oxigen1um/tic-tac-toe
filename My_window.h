#ifndef TICTACTOE_MY_WINDOW_H
#define TICTACTOE_MY_WINDOW_H

#include "config.h"

struct My_window : public Simple_window
{
    My_window (Graph_lib::Point xy, int w, int h, const std::string& title)
    : Simple_window{ xy, w, h, title }
    , quit_button{ Graph_lib::Point{x_max() - 70, 20}, 70, 20, "Quit", cb_quit }
    {
        attach (quit_button);
    }

    Graph_lib::Button quit_button;

private:
    static void cb_quit (Graph_lib::Address, Graph_lib::Address addr)
    {
        Graph_lib::reference_to<My_window>(addr).quit();
    }

    void quit() { hide(); }
};

#endif //TICTACTOE_MY_WINDOW_H
