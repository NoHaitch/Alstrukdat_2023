#include <stdio.h>

int main()
{
    int n, x, hasilKali, count;
    hasilKali = 1;
    count = 0;
    scanf("%d", &n);
    // iterasi setiap digit
    while (n > 0)
    {
        // x adalah satu digit
        x = n % 10;
        if (x != 0)
        {
            hasilKali *= x;
        }
        n /= 10;
    }
    // hasil kali didapat
    printf("%d ", hasilKali);
    // hitung digit
    while (hasilKali > 0)
    {
        // x adalah satu digit
        x = hasilKali % 10;
        if (x != 0)
        {
            count += 1;
        }
        hasilKali /= 10;
    }
    printf("%d\n", count);
    return 0;
}