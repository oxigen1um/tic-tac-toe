#ifndef TICTACTOE_ALERT_H
#define TICTACTOE_ALERT_H

#include "config.h"

class Alert : public Graph_lib::Widget {
public:
    Alert(Graph_lib::Point, int width, int height, const std::string& str, Graph_lib::Callback cb);


};


#endif //TICTACTOE_ALERT_H
