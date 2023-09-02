#include <stdio.h>
#include <math.h>
#include "garis.h"
#include "point.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */

void CreateGaris(GARIS *L, POINT P1, POINT P2)
{
    PAwal(*L) = P1;
    PAkhir(*L) = P2;
}

void BacaGARIS(GARIS *L)
{
    POINT P1, P2;
    BacaPOINT(&P1);
    BacaPOINT(&P2);
    CreateGaris(L, P1, P2);
}

void TulisGARIS(GARIS L)
{
    printf("(");
    TulisPOINT(L.PAw);
    printf(",");
    TulisPOINT(L.PAkh);
    printf(")");
}

float PanjangGARIS(GARIS L)
{
    return Panjang(L.PAw, L.PAkh);
}

float Gradien(GARIS L)
{
    return (L.PAkh.Y - L.PAw.Y) / (L.PAkh.X - L.PAw.X);
}

void GeserGARIS(GARIS *L, float deltaX, float deltaY)
{
    (*L).PAw.X += deltaX;
    (*L).PAw.Y += deltaY;
    (*L).PAkh.X += deltaX;
    (*L).PAkh.Y += deltaY;
}

boolean IsTegakLurus(GARIS L1, GARIS L2)
{
    // m1 * m2 = -1
    return Gradien(L1) * Gradien(L2) == -1;
}

boolean IsSejajar(GARIS L1, GARIS L2)
{
    return Gradien(L1) == Gradien(L2);
}

float JarakGARIS(GARIS L, POINT P)
{
    return 0;
} /*{
     float m1, b, d;
     m1 = Gradien(L);
     b = L.PAw.Y - (m1 * L.PAw.X);

     // Buat garis sejajar
     // y = ax + b
     // ax + b - y = 0
     // ax - y + b = 0
     // y = -1
     // d = |a * x + b * y + c| / akar kuadrat dari a * a + b * b
     d = sqrt(a * )
     return()
 }*/

boolean IsPointMemenuhiGaris(GARIS L, POINT P)
{
    float a, b, c, d;
    a = Gradien(L);
    b = L.PAw.Y - (a * L.PAw.X);
    // y = ax + b
    return P.Y == (a * P.X) + b;
}
