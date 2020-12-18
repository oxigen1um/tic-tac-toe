#ifndef TICTACTOE_ALGO_H
#define TICTACTOE_ALGO_H

#include "constants.h"

const int side = field_side; // using different name of variable for conciseness

bool hor(int (&m)[side][side], const int h, const int w);
bool ver(int (&m)[side][side], const int h, const int w);
bool lt_d(int (&m)[side][side], const int h, const int w);
bool rt_d(int (&m)[side][side], const int h, const int w);

bool check_end(int (&m)[side][side],const int height,const int width);

#endif //TICTACTOE_ALGO_H
