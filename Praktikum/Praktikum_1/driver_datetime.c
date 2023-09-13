#include <stdio.h>
#include "datetime.c"
#include "time.c"

int main()
{
    printf("start \n");

    DATETIME D1, D2;
    printf("DAY 1 : ");
    BacaDATETIME(&D1);
    int nextdetik = 12 * 31 * 24 * 3600;
    TulisDATETIME(DATETIMENextNDetik(D1, nextdetik));
    // printf("DAY 2 : ");
    // BacaDATETIME(&D2);

    // printf("DURASI : %ld", DATETIMEDurasi(D1, D2));
    return 0;
}

/*
    long int durasi;
    DATETIME DNew;
    Year(DNew) = Year(DAw);
    DNew.MM = 10;
    Day(DNew) = Day(DAw);
    Time(DNew) = Time(DAkh);
    if (TEQ(Time(DAw), Time(DAkh)))
    {
        durasi = 0;
    }
    else
    {
        durasi = Durasi(Time(DAw), Time(DAkh));
    }
    if (TGT(Time(DAw), Time(DAkh)))
    {
        Day(DNew) += 1;
    }
    while (!DEQ(DNew, DAkh))
    {
        DNew = DATETIMENextNDetik(DNew, 24 * 60 * 60);
        durasi += 24 * 60 * 60;
    }
    return durasi;
    */