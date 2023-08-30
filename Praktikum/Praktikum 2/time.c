#include <stdio.h>
#include "time.h"

boolean IsTIMEValid(int H, int M, int S)
{
    if (0 <= H <= 23 && 0 <= M <= 59 && 0 <= S <= 59)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CreateTime(TIME *T, int HH, int MM, int SS)
{
    Hour(*T) = HH;
    Minute(*T) = MM;
    Second(*T) = SS;
}
