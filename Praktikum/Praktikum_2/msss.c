/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 1 September 2023
    Soal No : 5
*/

#include <stdio.h>
#include <math.h>
#include "point.h"
#include "point.c"

int main()
{
    POINT P1, P2, P3;
    int a, b, c;
    BacaPOINT(&P1);
    BacaPOINT(&P2);
    BacaPOINT(&P3);
    TulisPOINT(P1);
    TulisPOINT(P2);
    TulisPOINT(P3);
    printf("\n");
    // (x1,y1) (x2,y2) (x3,y3)
    // y = ax^2 + bx + c
    // y1 = a(x1)^2 + b(x1) + c
    // y2 = a(x2)^2 + b(x2) + c
    // y3 = a(x3)^2 + b(x3) + c
    // ======================== +
    // y1 + y2 + y3 = a(x1^2 + x2^2 + x3^2) + b(x1 + x2 + x3) + 3c
    // a(x1^2 + x2^2 + x3^2) + b(x1 + x2 + x3) + 3c - (y1 + y2 + y3) = 0
    // saat x = 0, 3c - (y1+y2+y3) = 0
    //             3c = y1+y2+y3
    // c = (Ordinat(P1) + Ordinat(P2) + Ordinat(P3)) / 3;
    // printf("c = %d\n", c);

    // y1 - y2 = a(x1)^2 - a(x2)^2 + b(x1) + b(x2)
    // b(x1+x2) = (y1-y2) - a(x1^2 - x2^2)
    // printf("b * (%d) = (%d) - a *(%d)\n", (Absis(P1) + Absis(P2)), (Ordinat(P1) - Ordinat(P2)), (Absis(P1) * Absis(P1) - Absis(P2) * Absis(P2)));
    // printf("%f", Ordinat(P1));
    // TulisPOINT(P1);
    // C sudah ditemukan
    // y1 = a(x1)^2 + b(x1) + c
    // y2 = a(x2)^2 + b(x2) + c
    // y2-y1 = a(x2^2-x1^2) + b(x2^2-x1^2)
    // PERLU MENCARI NILAI a

    /*  y = c + bx + ax**2
        a = pin, b, c = bil. acak
    */

    a = ((P1.Y - P2.Y) * (P2.X - P3.X) - (P2.Y - P3.Y) * (P1.X - P2.X)) / ((P1.X - P2.X) * (P2.X - P3.X) * (P3.X - P1.X));
    printf("a = %d", a);
    return 0;
}