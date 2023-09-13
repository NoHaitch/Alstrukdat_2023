#include <stdio.h>

int main()
{
    int n, i, x, countAngka, countDigit;
    scanf("%d\n", &n);

    // menghitung jumlah angka yang berdigit genap
    countAngka = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d\n", &x);
        // asumsi masukan valid

        // Mengecek apakah angka berdigit genap
        countDigit = 0;
        while (x > 0)
        {
            x /= 10; // x = x / 10
            // Karena x dalam bentuk integer, maka pembagian yang menghasilkan koma akan di floor secara otomatis
            // contoh : 1/2 = 0; 5/2 = 2
            // jadi contoh : 12345/10 = 1234, 1234/10 = 123, 123/10 = 12, 12/10 = 1, 1/10 = 0, [loop berhenti]
            countDigit++;
        }
        if (countDigit % 2 == 0)
        {
            countAngka++;
        }
    }
    printf("%d\n", countAngka);
}