#include <iostream>
#include <ctime>
using namespace std;

const int side = 15;

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

void print(int (&m)[side][side])
{
    for(int i = 0; i < side; ++i)
    {
        for(int j = 0; j < side; ++j)
            cout << m[i][j] << " ";
        cout<<endl;
    }

}
int main()
{
    srand(time(NULL));
    int m[side][side];
    for(int i = 0; i < side; ++i)
        for(int j = 0; j < side; ++j)
            m[i][j] = 0;

    m[4][4] = 1;
    m[3][5] = 1;
    m[2][6] = 1;
    m[1][7] = 1;
    m[0][8] = 1;
    //проверить на конец
    bool res = check_end(m, 2, 6); // добавить if на наличие значения в клетке
    print(m);

    if(res) cout<<"YES";
    else cout<<"NO";
    return 0;
}
