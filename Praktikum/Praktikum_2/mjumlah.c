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
    printList(l1);
    printf("\n");
    printList(l2);
    printf("\n");
    if (listLength(l1) == listLength(l2))
    {
        l1 = plusMinusList(l1, l2, true);
    }
    else if (listLength(l1) > listLength(l2))
    {
        for (i = listLength(l2); i >= 0; i--)
        {
            ELMT(l1, listLength(l1) - i) += ELMT(l2, i);
        }
        l3 = l1;
    }
    else
    {
        for (i = listLength(l1); i >= 0; i--)
        {
            ELMT(l2, listLength(l2) - i) += ELMT(l1, i);
        }
        l3 = l2;
    }
}