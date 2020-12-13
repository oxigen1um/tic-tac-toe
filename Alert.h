#ifndef TICTACTOE_ALERT_H
#define TICTACTOE_ALERT_H

#include "config.h"

struct Alert : public Graph_lib::Window
{
    Alert (Graph_lib::Point xy, int w, int h, const std::string& title, const std::string& s)
            : Graph_lib::Window { xy, w, h, title }
            , quit_button{ Graph_lib::Point{x_max() - x_max() / 2  - 35, y_max() - 30 }, 70, 20, "Ok", cb_ok }
            , t{Graph_lib::Point{40, 50}, s}
    {
        attach (quit_button);
        attach (t);

        t.set_font_size(22);
    }

    Graph_lib::Text t;
    Graph_lib::Button quit_button;

private:
    static void cb_ok (Graph_lib::Address, Graph_lib::Address addr)
    {
        Graph_lib::reference_to<Alert>(addr).restart();
    }

    void restart() { hide(); }
};

#endif //TICTACTOE_ALERT_H
