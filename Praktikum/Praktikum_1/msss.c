/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 1 September 2023
    Soal No : 5
*/

#include <stdio.h>
#include "point.h"

int main()
{
    POINT P1, P2, P3;
    float a, b, c, d, e, f, g, h, i, j, k, l;
    BacaPOINT(&P1);
    BacaPOINT(&P2);
    BacaPOINT(&P3);

    if (Absis(P1) == Absis(P2) || Absis(P1) == Absis(P3) || Absis(P2) == Absis(P3))
    {
        // tidak dapat dibuat sebuah fungsi derajat dua
        printf("0\n");
    }
    else
    {
        a = Absis(P1) * Absis(P1);
        b = Absis(P1);
        c = 1;
        d = Ordinat(P1);

        e = Absis(P2) * Absis(P2);
        f = Absis(P2);
        g = 1;
        h = Ordinat(P2);

        i = Absis(P3) * Absis(P3);
        j = Absis(P3);
        k = 1;
        l = Ordinat(P3);

        /* Gunakan aturan Cramer */
        /*
            | a1 b1 c1 | a1 b1
            | a2 b2 c2 | a2 b2
            | a3 b3 c3 | a3 b3
        */
        float delta, da, db, dc;
        int ra, rb, rc;
        /*mencari determinan delta, da, db, dc*/
        delta = (a * f * k) + (b * g * i) + (c * e * j) - (c * f * i) - (a * g * j) - (b * e * k);
        da = (d * f * k) + (b * g * l) + (c * h * j) - (c * f * l) - (d * g * j) - (b * h * k);
        db = (a * h * k) + (d * g * i) + (c * e * l) - (c * h * i) - (a * g * l) - (d * e * k);
        dc = (a * f * l) + (b * h * i) + (d * e * j) - (d * f * i) - (a * h * j) - (b * e * l);
        ra = da / delta;
        rb = db / delta;
        rc = dc / delta;
        // maka fungsi kuadratiknya adalah y = ra x^2 + rb x + rc
        // dengan rc adalah pin rahasia
        printf("%d\n", rc);
    }
}