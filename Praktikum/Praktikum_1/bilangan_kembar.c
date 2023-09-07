/*  Nama    : Raden Francisco Trianto Bratadiningrat
    NIM     : 13522091
    tanggal : 1 September 2023
    Soal No : 4
*/

#include <stdio.h>
// BRUTE FORCED way
// int limit is 2147483647 or 10 digits

int main()
{
    int a, b, count;
    count = 0;
    scanf("%d %d", &a, &b);
    for (; a <= b; a++)
    {
        if (a % 11 == 0 || a % 111 == 0 || a % 1111 == 0 || a % 11111 == 0 || a % 111111 == 0 || a % 1111111 == 0 || a % 11111111 == 0 || a % 111111111 == 0 || a % 1111111111 == 0 || a % 1111111111 == 0)
        {
            count += 1;
        }
    }
    printf("%d\n", count);
    return 0;
}