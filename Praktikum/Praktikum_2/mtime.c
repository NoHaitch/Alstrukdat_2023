#include <stdio.h>
#include "time.h"

TIME waktuAwal(TIME T1, TIME T2)
{
    if (TEQ(T1, T2))
    {
        return T1;
    }
    else
    {
        if (TLT(T1, T2))
        {
            return T1;
        }
        else
        {
            return T2;
        }
    }
}

TIME waktuAkhir(TIME T1, TIME T2)
{
    if (TEQ(T1, T2))
    {
        return T1;
    }
    else
    {
        if (TGT(T1, T2))
        {
            return T1;
        }
        else
        {
            return T2;
        }
    }
}

int main()
{
    int n, i;
    TIME awal, akhir;
    boolean loopKeSatu = true;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("[%d]\n", i + 1);
        TIME T1, T2;
        BacaTIME(&T1);
        if (loopKeSatu)
        {
            awal = T1;
            akhir = T1;
            loopKeSatu = false;
        }
        BacaTIME(&T2);
        awal = waktuAwal(awal, T1);
        awal = waktuAwal(awal, T2);
        akhir = waktuAkhir(akhir, T1);
        akhir = waktuAkhir(akhir, T2);

        if (TEQ(T1, T2))
        {
            printf("0\n");
        }
        else
        {
            if (TLT(T1, T2))
            {
                printf("%ld\n", Durasi(T1, T2));
            }
            else
            {
                printf("%ld\n", Durasi(T2, T1));
            }
        }
    }
    TulisTIME(awal);
    printf("\n");
    TulisTIME(akhir);
    printf("\n");
    return 0;
}