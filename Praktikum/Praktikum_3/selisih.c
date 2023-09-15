/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 15 September 2023
    Soal No : 1
*/

#include <stdio.h>
#include "listdin.h"

int main()
{
    int n, i, x, max, min;
    max = -999;
    min = -999;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (max == -999 || min == -999)
        {
            max = x;
            min = x;
        }
        else
        {
            if (x > max)
            {
                max = x;
            }
            if (x < min)
            {
                min = x;
            }
        }
    }
    if (n <= 1)
    {
        printf("0\n");
    }
    else
    {
        printf("%d\n", max + 1 - min);
    }

    return 0;
}