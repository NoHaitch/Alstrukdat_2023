/*  Nama    : Raden Francisco Trianto Bratadiningrat
    NIM     : 13522091
    tanggal : 1 September 2023
    Soal No : 5
*/

#include <stdio.h>
// BRUTE FORCED way
// find maximum1 using a loop,
// find maximum2 using the same loop but condition not equal the first max

int main()
{
    int n, i, m1, m2, x;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    m1 = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] > m1)
        {
            m1 = a[i];
        }
    }
    m2 = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] > m2 && a[i] != m1)
        {
            m2 = a[i];
        }
    }
    printf("%d\n", m2);
    return 0;
}