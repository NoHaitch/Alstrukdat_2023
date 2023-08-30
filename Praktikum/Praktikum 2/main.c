#include <stdio.h>
#include "point.c"

int main()
{
    POINT p1, p2;
    BacaPOINT(&p1);
    BacaPOINT(&p2);
    TulisPOINT(p1);
    TulisPOINT(p2);
    PersamaanLinearDuaVariabel(p1, p2);
    return 0;
}