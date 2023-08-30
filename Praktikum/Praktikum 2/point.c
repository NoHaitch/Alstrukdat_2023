// File point.c
// Raden Francicso Trianto Bratadiningrat
// 13522091
// Pra Praktikum 2 Algoritma dan Struktur Data
// 30 Agustus 2022

#include <stdio.h>
#include <math.h>
#include "point.h"

void CreatePoint(POINT *P, float X, float Y)
{
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

void BacaPOINT(POINT *P)
{
    float X, Y;
    scanf("%f %f", &X, &Y);
    CreatePoint(P, X, Y);
}

void TulisPOINT(POINT P)
{
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

boolean EQ(POINT P1, POINT P2)
{
    return Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2);
}

boolean NEQ(POINT P1, POINT P2)
{
    return !(EQ(P1, P2));
}

boolean IsOrigin(POINT P)
{
    return Absis(P) == 0 && Ordinat(P) == 0;
}

boolean IsOnSbX(POINT P)
{
    return Ordinat(P) == 0;
}

boolean IsOnSbY(POINT P)
{
    return Absis(P) == 0;
}

int Kuadran(POINT P)
{
    /* Prekondisi : P bukan titik origin, */
    /*              dan P tidak terletak di salah satu sumbu */
    if (Absis(P) > 0)
    {
        if (Ordinat(P) > 0)
        {
            return 1;
        }
        else
        {
            return 4;
        }
    }
    else
    {
        if (Ordinat(P) > 0)
        {
            return 2;
        }
        else
        {
            return 3;
        }
    }
}

POINT NextX(POINT P)
{
    POINT Pt;
    CreatePoint(&Pt, Absis(P) + 1, Ordinat(P));
    return Pt;
}

POINT NextY(POINT P)
{
    POINT Pt;
    CreatePoint(&Pt, Absis(P), Ordinat(P) + 1);
    return Pt;
}

POINT PlusDelta(POINT P, float deltaX, float deltaY)
{
    POINT Pt;
    CreatePoint(&Pt, Absis(P) + deltaX, Ordinat(P) + deltaY);
    return Pt;
}

POINT MirrorOf(POINT P, boolean SbX)
{
    POINT Pt;
    if (SbX)
    {
        CreatePoint(&Pt, Absis(P), Ordinat(P) * -1);
    }
    else
    {
        CreatePoint(&Pt, Absis(P) * -1, Ordinat(P));
    }
    return Pt;
}

float Jarak0(POINT P)
{
    return sqrt(pow(Absis(P), 2) + pow(Ordinat(P), 2));
}

float Panjang(POINT P1, POINT P2)
{
    return sqrt(pow((Absis(P2) - Absis(P1)), 2) + pow((Ordinat(P2) - Ordinat(P1)), 2));
}

void Geser(POINT *P, float deltaX, float deltaY)
{
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

void GeserKeSbX(POINT *P)
{
    Ordinat(*P) = 0;
}

void GeserKeSbY(POINT *P)
{
    Absis(*P) = 0;
}

void Mirror(POINT *P, boolean SbX)
{
    if (SbX)
    {
        Ordinat(*P) = Ordinat(*P) * -1;
    }
    else
    {
        Absis(*P) = Absis(*P) * -1;
    }
}

void Putar(POINT *P, float sudut)
{
    float X, Y;
    X = Absis(*P);
    Y = Ordinat(*P);
    sudut = sudut * 3.141592 / 180;
    // Ubah menjadi radian
    Absis(*P) = X * cos(sudut) + Y * sin(sudut);
    Ordinat(*P) = -1 * X * sin(sudut) + Y * cos(sudut);
}

void PersamaanLinearDuaVariabel(POINT P1, POINT P2)
{
    int a = (Ordinat(P2) - Ordinat(P1)) / (Absis(P2) - Absis(P1));
    int b = Ordinat(P1) - (a * Absis(P1));
    printf("(%d,%d)", a, b);
}