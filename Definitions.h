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

inline const int doubleToIntX(const double &x)
{
    return 9-(x-1)*-5;
}

inline const int doubleToIntY(const double &y)
{
    return 7-(y+1.)*4;
}

inline const double intToDoubleX(const int &x)
{
    return -1.+(5.*x);
}

inline const double intToDoubleY(const int &y)
{
    return 1.-(4.*y);
}
#endif