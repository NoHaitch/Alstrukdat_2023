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

boolean DEQ(DATETIME D1, DATETIME D2)
{
    return (D1.DD == D2.DD && D1.MM == D2.MM && D1.YYYY == D2.YYYY && TEQ(D1.T, D2.T));
}

boolean DNEQ(DATETIME D1, DATETIME D2)
{
    return !DEQ(D1, D2);
}

boolean DLT(DATETIME D1, DATETIME D2)
{
    return (D1.YYYY < D2.YYYY || (D1.YYYY == D2.YYYY && D1.MM < D2.MM) || (D1.YYYY == D2.YYYY && D1.MM == D2.MM && D1.DD < D2.DD) || (D1.YYYY == D2.YYYY && D1.MM == D2.MM && D1.DD == D2.DD && TLT(D1.T, D2.T)));
}

boolean DGT(DATETIME D1, DATETIME D2)
{
    return (DLT(D2, D1));
}

DATETIME DATETIMENextNDetik(DATETIME D, int N)
{
    DATETIME Dt;
    TIME T;
    int DD, MM, YYYY;
    // 1 hari = 86400 detik
    if (TIMEToDetik(D.T) + N > 86400)
    {
        while (TIMEToDetik(D.T) + N > 86400)
        {
            N -= 86400;
            DD = D.DD + 1;
            if (DD > GetMaxDay(D.MM, D.YYYY))
            {
                MM = D.MM + 1;
                DD = 1;
                if (MM > 12)
                {
                    YYYY = D.YYYY + 1;
                    MM = 1;
                }
            }
        }
    }
    else
    {
        DD = D.DD;
        MM = D.MM;
        YYYY = D.YYYY;
    }
    T = NextNDetik(D.T, N);
    CreateDATETIME(&Dt, DD, MM, YYYY, T.HH, T.MM, T.SS);
    return Dt;
}

DATETIME DATETIMEPrevNDetik(DATETIME D, int N)
{
    DATETIME Dt;
    TIME T;
    int DD, MM, YYYY;
    // 1 hari = 86400 detik
    if (TIMEToDetik(D.T) - N < 0)
    {
        while (TIMEToDetik(D.T) - N < 0)
        {
            N -= 86400;
            DD = D.DD - 1;
            if (DD < 0)
            {
                MM = D.MM - 1;
                if (MM < 0)
                {
                    YYYY = D.YYYY - 1;
                    MM = 12;
                }
            }
        }
    }
    else
    {
        DD = D.DD;
        MM = D.MM;
        YYYY = D.YYYY;
    }
    T = PrevNDetik(D.T, N);
    CreateDATETIME(&Dt, DD, MM, YYYY, T.HH, T.MM, T.SS);
    return Dt;
}

long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh)
{
    return 0;
}
