#ifndef CELL_H
#define CELL_H

#include "config.h"

//using Graph_lib::Point;

class Cell : public Graph_lib::Button
{
public:
    enum Type {black, white};

    Cell (Graph_lib::Point xy, Graph_lib::Callback cb, Type t);

    void attach(Graph_lib::Window& win) override;

    void activate(){ if (pw) pw->color (FL_SELECTION_COLOR);}
    void deactivate(){ reset_color(); }

    bool is_black() const { return type == black;}
    Graph_lib::Point center() const { return Graph_lib::Point{ loc.x + width/2,
                                                    loc.y + height/2};}
    static constexpr int size = 40;

private:
    Type type;
    void reset_color();
};

Cell::Type type_of_cell (int i, int j);

#endif // CELL_H

