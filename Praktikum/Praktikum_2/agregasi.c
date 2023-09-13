/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 8 September 2023
    Soal No : 2
*/

#include <stdio.h>
#include "liststatik.h"

int main()
{
    ListStatik l;
    int x, i;
    boolean found;
    readList(&l);
    scanf("%d", &x);
    sortList(&l, true);
    printList(l);
    printf("\n");
    // hitung sum
    float sum = 0;
    for (i = 0; i < listLength(l); i++)
    {
        sum += ELMT(l, i);
    }
    float avrg = sum / listLength(l);
    printf("Average: %.02f\n", avrg);
    // cari indeks terkecil
    found = false;
    for (i = 0; i < listLength(l); i++)
    {
        if (ELMT(l, i) == x && found == false)
        {
            printf("%d\n", i);
            found = true;
        }
    }
    if (found == false)
    {
        printf("%d tidak ada\n", x);
    }
    else
    {
        // pengecekan max, min, median
        int max, min, median;
        if (listLength(l) % 2 == 1)
        {
            median = ELMT(l, listLength(l) / 2);
        }
        else
        {
            median = ELMT(l, (listLength(l) / 2) - 1);
        }

        extremeValues(l, &max, &min);
        if (x == max)
        {
            printf("X maksimum\n");
        }
        if (x == min)
        {
            printf("X minimum\n");
        }

        if (x == median)
        {
            printf("X median\n");
        }
    }

    return 0;
}