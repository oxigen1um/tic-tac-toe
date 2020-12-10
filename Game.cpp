#include "Game.h"
#include "constants.h"
#include "config.h"

 Game::Game(Graph_lib::Point p, int width, int height, std::string title)
    : Graph_lib::Window{ p, width, height, title },
    btn{ Graph_lib::Point {p.x + 20, p.y + 20}, 50, 50, "Btn", cb_button }
{
    attach(btn);
}

void Game::cb_button(Graph_lib::Address a, Graph_lib::Address b)
{
    Graph_lib::reference_to<Game>(b).click(a);
}

void Game::click(Graph_lib::Address a) {
    //Graph_lib::reference_to<Fl_Widget>(a).color(Graph_lib::Color::red);
    btn.label = "hi";
}

