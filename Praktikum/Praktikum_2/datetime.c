#include <stdio.h>
#include "datetime.h"
#include "time.h"

int GetMaxDay(int M, int Y)
{
    if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12)
    {
        return 31;
    }
    else
    {
        if (M == 4 || M == 6 || M == 9 || M == 11)
        {
            return 30;
        }
        else
        {
            if (Y % 400 == 0 || (Y % 100 != 0 && Y % 4 == 0))
            {
                // kabisat
                return 29;
            }
            else
            {
                return 28;
            }
        }
    }
}

boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s)
{
    return (IsTIMEValid(h, m, s) && D >= 1 && D <= GetMaxDay(M, Y) && M >= 1 && M <= 12 && Y >= 1900 && Y <= 2030);
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
    int DD, MM, YYYY, h, m, s;
    scanf("%d %d %d %d %d %d", &DD, &MM, &YYYY, &h, &m, &s);
    while (!IsDATETIMEValid(DD, MM, YYYY, h, m, s))
    {
        printf("DATETIME tidak valid\n");
        scanf("%d %d %d %d %d %d", &DD, &MM, &YYYY, &h, &m, &s);
    }
    CreateDATETIME(D, DD, MM, YYYY, h, m, s);
}

void TulisDATETIME(DATETIME D)
{
    printf("%d/%d/%d ", D.DD, D.MM, D.YYYY);
    TulisTIME(D.T);
    printf("\n");
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
    if (D1.YYYY < D2.YYYY)
    {
        return true;
    }
    else
    {
        if (D1.YYYY > D2.YYYY)
        {
            return false;
        }
        else
        {
            if (D1.MM < D2.MM)
            {
                return true;
            }
            else
            {
                if (D1.MM > D2.MM)
                {
                    return false;
                }
                else
                {
                    if (D1.DD < D2.DD)
                    {
                        return true;
                    }
                    else
                    {
                        if (D1.DD > D2.DD)
                        {
                            return false;
                        }
                        else
                        {
                            if (TLT(D1.T, D2.T))
                            {
                                return true;
                            }
                            else
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }

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
    DD = D.DD;
    MM = D.MM;
    YYYY = D.YYYY;
    // 1 hari = 86400 detik
    if (TIMEToDetik(D.T) + N > 86400)
    {
        while (TIMEToDetik(D.T) + N > 86400)
        {
            N -= 86400;
            DD += 1;
            if (DD > GetMaxDay(D.MM, D.YYYY))
            {
                MM += +1;
                DD = 1;
                if (MM > 12)
                {
                    YYYY += +1;
                    MM = 1;
                }
            }
        }
    }
}

DATETIME DATETIMEPrevNDetik(DATETIME D, int N)
{
    DATETIME Dt;
    Dt.DD = D.DD;
    Dt.MM = D.MM;
    Dt.YYYY = D.YYYY;
    Dt.T = PrevNDetik(D.T, N);
    // 1 hari = 86400 detik
    if (TIMEToDetik(D.T) - N < 0)
    {
        // diperlukan pergantian tanggal
        while (TIMEToDetik(D.T) - N < 0)
        {
            N -= 86400;
            Dt.DD -= 1;
            if (Dt.DD < 1)
            {
                Dt.MM -= 1;
                if (Dt.MM < 1)
                {
                    Dt.YYYY -= 1;
                    Dt.MM = 12;
                }
                Dt.DD = GetMaxDay(Dt.MM, Dt.YYYY);
            }
        }
    }
    return Dt;
}

long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh)
{
    long int durasi;
    // DNew adalah waktu yang akan perlahan menjadi sama dengan DAkh
    DATETIME DNew;
    Year(DNew) = Year(DAw);
    Month(DNew) = Month(DAw);
    Day(DNew) = Day(DAw);
    Time(DNew) = Time(DAkh);

    // dikarenakan ada prekondisi pada DURASI() dimana tidak boleh waktu sama
    if (TEQ(Time(DAw), Time(DAkh)))
    {
        durasi = 0;
    }
    else
    {
        durasi = Durasi(Time(DAw), Time(DAkh));
    }

    // Jika waktu Awal > waktu Akhir cth : 15:0:0 > 12:0:0 maka berubah hari
    if (TGT(Time(DAw), Time(DAkh)))
    {
        Day(DNew) += 1;
    }

    // Jika Hari belum sama maka tambah 1 hari ke durasi dan ke waktu Dnew hingga Dnew sama persis dengan Dakh
    while (!DEQ(DNew, DAkh))
    {
        DNew = DATETIMENextNDetik(DNew, 24 * 60 * 60);
        durasi += 24 * 60 * 60;
    }
    return durasi;
}
