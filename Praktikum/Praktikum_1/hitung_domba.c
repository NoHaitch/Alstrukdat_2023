/*  Nama    : Raden Francisco Trianto Bratadiningrat
    NIM     : 13522091
    tanggal : 25 Agustus 2023
    Soal No : 3
*/

#include <stdio.h>

int main()
{
    int n, m, i;
    i = 1;
    scanf("%d %d", &n, &m);
    // n domba, m kesayangan
    while (i < n + 1)
    {
        if (i % m == 0)
        {
            printf("happy\n");
        }
        else
        {
            printf("%d\n", i);
        }
        i++;
    }
    return 0;
}