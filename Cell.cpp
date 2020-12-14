#include "Cell.h"

Cell::Cell (Graph_lib::Point xy, Graph_lib::Callback cb, Graph_lib::Point arr_pos)
        : Button{ xy, size, size, "", cb },
          array_pos{arr_pos}
        { }

void Cell::attach(Graph_lib::Window& win)
{
    Button::attach (win);
}

