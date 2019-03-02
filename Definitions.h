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

inline int doubleToIntX(const double &x)
{
    return (x+1)/(2./9.);
}

inline int doubleToIntY(const double &y)
{
    return (y-1)/(-2./7.);
}

inline double intToDoubleX(const int &x)
{
    return -1+(2./9.)*x;
}

inline double intToDoubleY(const int &y)
{
    return 1-(2./7.)*y;
}
#endif