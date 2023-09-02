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
    BacaPOINT(&(*L).PAw);
    BacaPOINT(&(*L).PAkh);
    while (EQ((*L).PAw, (*L).PAkh))
    {
        printf("Garis tidak valid\n");
        BacaPOINT(&(*L).PAw);
        BacaPOINT(&(*L).PAkh);
    }
    CreateGaris(L, (*L).PAw, (*L).PAkh);
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
    Geser(&PAwal(*L), deltaX, deltaY);
    Geser(&PAkhir(*L), deltaX, deltaY);
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
}

boolean IsPointMemenuhiGaris(GARIS L, POINT P)
{
    float a, b, c, d;
    a = Gradien(L);
    b = L.PAw.Y - (a * L.PAw.X);
    // y = a1x + b1
    // ax + by + c = 0
    // a = a1, b = -1, c = b
    return P.Y == (a * P.X) + b;
}
