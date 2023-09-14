/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 8 September 2023
    Soal No : 3
*/

#include <stdio.h>
#include "liststatik.h"

int main()
{
    ListStatik rumah, perjalanan;
    readList(&rumah);
    readList(&perjalanan);
    insertFirst(&perjalanan, 0);
    int sum = 0;
    for (int i = 1; i <= 3; i++)
    {
        int idx = 0;
        while (indexOf(rumah, i) != IDX_UNDEF)
        {
            sum += ELMT(perjalanan, idx);
            if (ELMT(rumah, idx) == i)
            {
                sum += 1;
                ELMT(rumah, idx) = 0;
            }
            idx++;
            if (indexOf(rumah, i) == IDX_UNDEF)
            {
                for (int i = 0; i < idx; i++)
                {
                    sum += ELMT(perjalanan, i);
                }
            }
        }
    }
    printf("%d\n", sum);
}