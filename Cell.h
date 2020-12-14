#ifndef CELL_H
#define CELL_H

#include "config.h"

class Cell : public Graph_lib::Button
{
public:

    Cell (Graph_lib::Point xy, Graph_lib::Callback cb, Graph_lib::Point arr_pos);

    void attach(Graph_lib::Window& win) override;

    bool is_full() const { return full; }
    void set_full(bool value) { full = value; }

    void toggle_full() { full = !full; }

    Graph_lib::Point center() const { return Graph_lib::Point{ loc.x + width / 2,loc.y + height / 2};}
    static constexpr int size = 40;

    Graph_lib::Point get_point() const { return array_pos; }

private:
    bool full = false;
    Graph_lib::Point array_pos;
};

#endif // CELL_H

