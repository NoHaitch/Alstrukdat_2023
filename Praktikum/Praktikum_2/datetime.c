#include <stdio.h>
#include "datetime.h"
#include "time.h"

int GetMaxDay(int M, int Y)
{
    if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12)
    {
        return 31;
    }
    else if (M == 4 || M == 6 || M == 9 || M == 11)
    {
        return 30;
    }
    else if (Y % 400 == 0 || (Y % 100 != 0 && Y % 4 == 0))
    {
        // kabisat
        return 29;
    }
    else
    {
        return 28;
    }
}

boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s)
{
    return (IsTIMEValid(h, m, s) && D >= 1 && D <= GetMaxDay(M, Y) && M >= 1 && M <= 12 && Y >= 1);
}

void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss)
{
    (*D).DD = DD;
    (*D).MM = MM;
    (*D).YYYY = YYYY;
    TIME T;
    CreateTime(&T, hh, mm, ss);
    (*D).T = T;
}

void BacaDATETIME(DATETIME *D)
{
    int DD, MM, YYYY;
    TIME T;
    BacaTIME(&T);
    CreateDATETIME(D, DD, MM, YYYY, T.HH, T.MM, T.SS);
}

void TulisDATETIME(DATETIME D)
{
    printf("%d/%d/%d ", D.DD, D.MM, D.YYYY);
    TulisTIME(D.T);
}

boolean DEQ(DATETIME D1, DATETIME D2) {}
boolean DNEQ(DATETIME D1, DATETIME D2) {}
boolean DLT(DATETIME D1, DATETIME D2) {}
boolean DGT(DATETIME D1, DATETIME D2) {}
DATETIME DATETIMENextNDetik(DATETIME D, int N) {}
DATETIME DATETIMEPrevNDetik(DATETIME D, int N) {}
long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh) {}
