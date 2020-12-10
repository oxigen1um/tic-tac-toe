#include "Board.h"

 Board::Board (Graph_lib::Point xy)
        : My_window{ xy, width, height, "Board" }
 {
    size_range (width, height, width, height); // fixed window size
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cells.push_back(new Cell{Graph_lib::Point{margin + j * Cell::size,
                                                      margin + (N - 1 - i) * Cell::size},
                                     cb_clicked, type_of_cell(i, j)});
            attach(cells[cells.size() - 1]);
        }

    for (int i = 0; i < N; ++i)
        {
        // board corners: left up
        constexpr Graph_lib::Point lu{ margin + Cell::size/2,
                            margin + N*Cell::size + 10 };
        // and right bottom
        constexpr Graph_lib::Point rb{ margin - 10,
                            margin + N*Cell::size - Cell::size/2 };

    }

// create figures here, later
 }

void Board::clicked (Graph_lib::Address widget)
{
Fl_Widget& w = Graph_lib::reference_to<Fl_Widget>(widget);
Cell& c = at (Graph_lib::Point{w.x(), w.y()});
// add programm response here, later

    c.label = "O";
    Fl::redraw();
 }

Cell& Board::at (Graph_lib::Point p)
{
    int i = N-1 - (p.y - margin) / Cell::size;
    int j = (p.x - margin) / Cell::size;
    return cells[i*N + j];
}

 Cell& Board::at (char c, int i)
 {
    --i;
    // the first cell has index 1

    int j = c - 'a';

    return cells[i*N + j];
 }