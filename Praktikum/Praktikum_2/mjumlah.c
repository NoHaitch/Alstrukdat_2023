/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 8 September 2023
    Soal No : 1
*/

#include <stdio.h>
#include "liststatik.h"

int main()
{
    ListStatik l1, l2, l3;
    int i;
    readList(&l1);
    readList(&l2);
    if (listLength(l1) >= listLength(l2))
    {
        int distance = listLength(l1) - listLength(l2);
        for (i = listLength(l2) - 1; i >= 0; i--)
        {
            ELMT(l1, i + distance) += ELMT(l2, i);
        }
        l3 = l1;
    }
    else
    {
        int distance = listLength(l2) - listLength(l1);
        for (i = listLength(l1) - 1; i >= 0; i--)
        {
            ELMT(l2, i + distance) += ELMT(l1, i);
        }
        l3 = l2;
    }
    int x = 1;
    while (x == 1)
    {
        int cek_count = 0;
        for (i = 0; i < listLength(l3); i++)
        {
            if (ELMT(l3, i) <= 9)
            {
                cek_count += 1;
            }
        }
        if (cek_count == listLength(l3))
        {
            x = 2;
            break;
        }
        for (i = 0; i < listLength(l3); i++)
        {
            if (ELMT(l3, i) > 9 && i != 0)
            {
                ELMT(l3, i) -= 10;
                ELMT(l3, i - 1) += 1;
            }
        }
        if (ELMT(l3, 0) > 9)
        {
            insertFirst(&l3, ELMT(l3, 0) / 10);
            ELMT(l3, 1) %= 10;
        }
    }
    printList(l3);
    printf("\n");
    return 0;
}