#include "Cell.h"


Cell::Cell (Graph_lib::Point xy, Graph_lib::Callback cb, Type t )
        : Button{ xy, size, size, "", cb }
        , type{ t } {}

void Cell::attach(Graph_lib::Window& win)
{
    Button::attach (win);
    reset_color();
}

void Cell::reset_color()
{
    if(!pw) std::runtime_error("Cell is not attached to a window");

    if(is_black())
        pw->color(Graph_lib::Color::black);
    else
        pw->color (Graph_lib::Color::white);
}

Cell::Type type_of_cell (int i, int j)
{
    return Cell::white;
//    if (i % 2 == 0)
//        return (j % 2 == 0) ? Cell::black : Cell::white;
//    else
//         return (j % 2 == 0) ? Cell::white : Cell::black;
 }
