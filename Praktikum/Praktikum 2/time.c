#include <stdio.h>
#include "time.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */

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
    (*T).HH = HH;
    (*T).MM = MM;
    (*T).SS = SS;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */

void BacaTIME(TIME *T)
{
    int HH, MM, SS;
    do
    {
        scanf("%d %d %d", &HH, &MM, &SS);
    } while (!IsTIMEValid(HH, MM, SS));
    CreateTime(T, HH, MM, SS);
}

void TulisTIME(TIME T)
{
    printf("%02d:%02d:%02d", T.HH, T.MM, T.SS);
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */

long TIMEToDetik(TIME T)
{
    return 3600 * T.HH + 60 * T.MM + T.SS;
}

TIME DetikToTIME(long N)
{
    TIME T;
    N = N % 86400;
    T.HH = N / 3600;
    T.MM = (N % 3600) / 60;
    T.SS = (N % 3600) % 60;
    return T;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */

boolean TEQ(TIME T1, TIME T2)
{
    return T1.HH == T2.HH && T1.MM == T2.MM && T1.SS == T2.SS;
}

boolean TNEQ(TIME T1, TIME T2)
{
    return !(TEQ(T1, T2));
}