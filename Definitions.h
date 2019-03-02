#ifndef DEFINITIONS_H
#define DEFINITIONS_H

enum Team
{
    BLACK,
    RED,
    NEITHER
};

int const col = 9;
int const row = 6;

inline int doubleToIntX(double x)
{
    return 9-(x-1)*-5;
}

inline int doubleToIntY(double y)
{
    return 7-(y+1.)*4;
}

inline double intToDoubleX(int x)
{
    return -1.+(5.*x);
}

inline double intToDoubleY(int y)
{
    return 1.-(4.*y);
}
#endif