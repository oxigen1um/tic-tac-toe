#include "algo.h"

/*
 * 0 - пусто
 * 1 - нолик
 * 2 - крестик
*/

bool hor(int (&m)[side][side], const int h, const int w)
{
    const int type = m[h][w]; //тип клетки с которым будем сверять все остальные
    int iter = 1;
    int w1 = w - 1;
    while((w1 >= 0) && (m[h][w1] == type) && (iter < 5))
    {
        --w1;
        ++iter;
    }

    w1 = w + 1;
    while((w1 < side) && (m[h][w1] == type)&&(iter < 5))
    {
        ++w1;
        ++iter;
    }

    if (iter == 5) return true;
    else return false;
}

bool ver(int (&m)[side][side], const int h, const int w)
{
    const int type = m[h][w];
    int iter = 1;
    int h1 = h - 1;
    while((h1 >= 0) && (m[h1][w] == type) && (iter < 5))
    {
        --h1;
        ++iter;
    }

    h1 = h + 1;
    while((h1 < side) && (m[h1][w] == type)&&(iter < 5))
    {
        ++h1;
        ++iter;
    }

    if (iter == 5) return true;
    else return false;
}

bool lt_d(int (&m)[side][side], const int h, const int w) // *\*
{
    const int type = m[h][w];
    int iter = 1;

    //идем в левый  верхний угол:
    int h1 = h - 1;
    int w1 = w - 1;
    while((h1 >= 0) && (w1 >= 0) && (m[h1][w1] == type) && (iter < 5))
    {
        --h1;
        --w1;
        ++iter;
    }

    //идем в правый нижний угол:
    h1 = h + 1;
    w1 = w + 1;
    while((h1 < side) && (w1 < side) && (m[h1][w1] == type) && (iter < 5))
    {
        ++h1;
        ++w1;
        ++iter;
    }

    if (iter == 5) return true;
    else return false;
}

bool rt_d(int (&m)[side][side], const int h, const int w)// */*
{
    const int type = m[h][w];
    int iter = 1;

    //идем в левый нижний угол:
    int h1 = h + 1;
    int w1 = w - 1;
    while((h1 < side ) && (w1 >= 0) && (m[h1][w1] == type) && (iter < 5))
    {
        ++h1;
        --w1;
        ++iter;
    }

    //идем в правый верхний угол:
    h1 = h - 1;
    w1 = w + 1;
    while((h1 >= 0) && (w1 < side) && (m[h1][w1] == type) && (iter < 5))
    {
        --h1;
        ++w1;
        ++iter;
    }

    if (iter == 5) return true;
    else return false;
}

bool check_end(int (&m)[side][side],const int height,const int width)
// аргументы: матрица поля, координаты последнего хода (высота, ширина)
{
    bool res = false;
    res = hor(m, height, width);           // Проверка по горизонтали
    if(!res) res = ver(m, height, width);  // Проверка по вертикали
    if(!res) res = lt_d(m, height, width); // Проверка по левой диагонали *\*
    if(!res) res = rt_d(m, height, width); // Проверка по правой диагонали */*

    return res;
}
