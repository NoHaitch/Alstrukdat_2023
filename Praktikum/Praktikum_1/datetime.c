/*  Nama    : Raden Francisco Trianto Bratadiningrat
    NIM     : 13522091
    tanggal : 1 September 2023
    Soal No : 4
*/

#include <stdio.h>
#include "datetime.h"
#include "time.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
int GetMaxDay(int M, int Y)
/* Mengirimkan jumlah hari maksimum pada bulan M dan tahun Y */
/* Prekondisi: 1 <= M <= 12*/
/* Hint: Perhatikan Leap Year. Leap Year adalah tahun dengan 29 hari pada bulan Februari */
/* Aturan Leap Year: */
/* 1. Jika angka tahun itu habis dibagi 400, maka tahun itu sudah pasti tahun kabisat. 8*/
/* 2. Jika angka tahun itu tidak habis dibagi 400 tetapi habis dibagi 100, maka tahun itu sudah pasti bukan merupakan tahun kabisat. */
/* 3. Jika angka tahun itu tidak habis dibagi 400, tidak habis dibagi 100 akan tetapi habis dibagi 4, maka tahun itu merupakan tahun kabisat. */
/* 4. Jika angka tahun tidak habis dibagi 400, tidak habis dibagi 100, dan tidak habis dibagi 4, maka tahun tersebut bukan merupakan tahun kabisat. */
{
    boolean kabisat;
    if ((Y % 400 == 0))
    {
        kabisat = true;
    }
    else
    {
        if (Y % 100 == 0)
        {
            kabisat = false;
        }
        else if (Y % 4 == 0)
        {
            kabisat = true;
        }
        else
        {
            kabisat = false;
        }
    }

    if (M == 2)
    {
        if (kabisat)
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
    else if ((M % 2 == 1) && (M <= 7))
    {
        return 31;
    }
    else if ((M % 2 == 0) && (M <= 7))
    {
        return 30;
    }
    else if ((M % 2 == 1) && (M > 7))
    {
        return 30;
    }
    else if ((M % 2 == 0) && (M > 7))
    {
        return 31;
    }
    else
    {
        return 30;
    }
}
boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s)
/* Mengirim true jika D,M,Y,h,m,s dapat membentuk D yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah DATETIME */
{
    return (IsTIMEValid(h, m, s) && D >= 1 && D <= GetMaxDay(M, Y) && M >= 1 && M <= 12 && Y >= 1900 && Y <= 2030);
}

/* *** Konstruktor: Membentuk sebuah DATETIME dari komponen-komponennya *** */
void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss)
/* Membentuk sebuah DATETIME dari komponen-komponennya yang valid */
/* Prekondisi : DD, MM, YYYY, h, m, s valid untuk membentuk DATETIME */
{
    (*D).DD = DD;
    (*D).MM = MM;
    (*D).YYYY = YYYY;
    TIME T;
    CreateTime(&T, hh, mm, ss);
    (*D).T = T;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaDATETIME(DATETIME *D)
/* I.S. : D tidak terdefinisi */
/* F.S. : D terdefinisi dan merupakan DATETIME yang valid */
/* Proses : mengulangi membaca komponen DD, MM, YY, h, m, s sehingga membentuk D */
/* yang valid. Tidak mungkin menghasilkan D yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen DD, MM, YY, h, m, s
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika DATETIME tidak valid maka diberikan pesan: "DATETIME tidak valid", dan pembacaan
    diulangi hingga didapatkan DATETIME yang valid. */
/* Contoh:
    32 13 2023 12 34 56
    DATETIME tidak valid
    31 12 2023 12 34 56
    --> akan terbentuk DATETIME <31,12,2023,12,34,56> */
{
    int DD, MM, YYYY, h, m, s;
    scanf("%d %d %d %d %d %d", &DD, &MM, &YYYY, &h, &m, &s);
    while (!IsDATETIMEValid(DD, MM, YYYY, h, m, s))
    {
        printf("DATETIME tidak valid\n");
        scanf("%d %d %d %d %d %d", &DD, &MM, &YYYY, &h, &m, &s);
    }
    CreateDATETIME(D, DD, MM, YYYY, h, m, s);
}

void TulisDATETIME(DATETIME D)
/* I.S. : D sembarang */
/* F.S. : Nilai D ditulis dg format DD/MM/YYYY HH:MM:SS */
/* Proses : menulis nilai setiap komponen D ke layar dalam format DD/MM/YYYY HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/
{
    printf("%d/%d/%d %d:%d:%d", Day(D), Month(D), Year(D), Hour(Time(D)), Minute(Time(D)), Second(Time(D)));
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok operasi relasional terhadap DATETIME *** */
boolean DEQ(DATETIME D1, DATETIME D2)
/* Mengirimkan true jika D1=D2, false jika tidak */
{
    return (Day(D1) == Day(D2) && Month(D1) == Month(D2) && Year(D1) == Year(D2) && TEQ(Time(D1), Time(D2)));
}

boolean DNEQ(DATETIME D1, DATETIME D2)
/* Mengirimkan true jika D1 tidak sama dengan D2 */
{
    return !DEQ(D1, D2);
}

boolean DLT(DATETIME D1, DATETIME D2)
/* Mengirimkan true jika D1<D2, false jika tidak */
{
    if (Year(D1) < Year(D2))
    {
        return true;
    }
    else if (Year(D1) == Year(D2))
    {
        if (Month(D1) < Month(D2))
        {
            return true;
        }
        else if (Month(D1) == Month(D2))
        {
            if (Day(D1) < Day(D2))
            {
                return true;
            }
            else if (Day(D1) == Day(D2))
            {
                if (TLT(Time(D1), Time(D2)))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

boolean DGT(DATETIME D1, DATETIME D2)
/* Mengirimkan true jika D1>D2, false jika tidak */
{
    return (DLT(D2, D1));
}

DATETIME DATETIMENextNDetik(DATETIME D, int N)
/* Mengirim salinan D dengan detik ditambah N */
{
    DATETIME D1;
    Second(Time(D)) += N;

    while (Second(Time(D)) > 59)
    {
        Second(Time(D)) -= 60;
        Minute(Time(D))++;
    }

    while (Minute(Time(D)) > 59)
    {
        Minute(Time(D)) -= 60;
        Hour(Time(D))++;
    }

    while (Hour(Time(D)) > 23)
    {
        Hour(Time(D)) -= 24;
        Day(D)++;
    }

    while (Day(D) > GetMaxDay(Month(D), Year(D)))
    {
        Day(D) -= GetMaxDay(Month(D), Year(D));
        Month(D)++;
    }

    while (Month(D) > 12)
    {
        Month(D) -= 12;
        Year(D)++;
    }

    CreateDATETIME(&D1, Day(D), Month(D), Year(D), Hour(Time(D)), Minute(Time(D)), Second(Time(D)));
    return D1;
}

DATETIME DATETIMEPrevNDetik(DATETIME D, int N)
/* Mengirim salinan D dengan detik dikurang N */
{
    DATETIME D1;
    Second(Time(D)) -= N;

    while (Second(Time(D)) < 0)
    {
        Second(Time(D)) += 60;
        Minute(Time(D))--;
    }

    while (Minute(Time(D)) < 0)
    {
        Minute(Time(D)) += 60;
        Hour(Time(D))--;
    }

    while (Hour(Time(D)) < 0)
    {
        Hour(Time(D)) += 24;
        Day(D)--;
    }

    while (Day(D) < 1)
    {
        Month(D)--;
        Day(D) += GetMaxDay(Month(D), Year(D));
    }

    while (Month(D) < 1)
    {
        Month(D) += 12;
        Year(D)--;
    }

    CreateDATETIME(&D1, Day(D), Month(D), Year(D), Hour(Time(D)), Minute(Time(D)), Second(Time(D)));
    return D1;
}

/* *** Kelompok Operator Aritmetika terhadap DATETIME *** */
long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh)
/* Mengirim DAkh-DAw dlm Detik, dengan kalkulasi */
/* Prekondisi: DAkh > DAw */
{
    long int hasil;
    DATETIME D;
    Year(D) = Year(DAw);
    Month(D) = Month(DAw);
    Day(D) = Day(DAw);
    int countDays = 0;

    hasil = Durasi(Time(DAw), Time(DAkh));

    Time(D) = Time(DAkh);

    if (TGT(Time(DAw), Time(DAkh)))
    {
        Day(D)++;
    }

    while (DNEQ(D, DAkh))
    {
        D = DATETIMENextNDetik(D, 24 * 60 * 60);
        countDays++;
    }
    return hasil + countDays * 86400;
}