/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 8 September 2023
    Soal No : 1
*/

#include <stdio.h>
#include "liststatik.h"

int main()
{
    ListStatik l;
    readList(&l);
    int n, i, x;
    scanf("%d\n", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        insertFirst(&l, x);
    }
    sortList(&l, true);
    printList(l);
    printf("\n");
    return 0;
}