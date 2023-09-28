/*
Nama : Abel Apriliani
NIM : 18222008
Topik : Prapraktikum 4
Deskripsi : Implementasi deret.h
Tanggal : 27 September 2023
*/

#include<stdio.h>
#include "deret.h"
#include <math.h>

// Deret aritmatika adalah deret angka yang setiap angka berikutnya
// diperoleh dengan menambahkan suatu bilangan tetap ke angka sebelumnya.
// Contoh:
// Deret aritmatika dengan beda 2
// Aritmatika 1: 3
// Aritmatika 2: 3 + 2 = 5
// Aritmatika 3: 5 + 2 = 7
// Aritmatika 4: 7 + 2 = 9
// Aritmatika 5: 9 + 2 = 11


// Deret geometri adalah deret angka yang setiap angka berikutnya
// diperoleh dengan mengalikan angka sebelumnya dengan suatu rasio tetap.
// Contoh:
// Deret geometri dengan rasio 2
// Geometri 1: 2
// Geometri 2: 2 x 2 = 4
// Geometri 3: 4 x 2 = 8
// Geometri 4: 8 x 2 = 16
// Geometri 5: 16 x 2 = 32

// Segitiga Pascal adalah segitiga angka yang dihasilkan dengan aturan berikut:
// 1. Baris pertama hanya berisi angka 1.
// 2. Setiap angka di baris selanjutnya dihasilkan dengan menjumlahkan dua angka di atasnya
//    dalam baris yang sama pada baris sebelumnya.
// Contoh:
// Baris 1: 1
// Baris 2: 1   1
// Baris 3: 1   2   1
// Baris 4: 1   3   3   1
// Baris 5: 1   4   6   4   1
int main(){
    int result[5];
    printf("aritmetika : %d\n",aritmatika(10,10,5)); // U = 10 + (5-1) * 10 = 50 
    printf("geometri : %d\n",geometri(5,2,5)); // U = 5 * 2^(5-1) = 5 * 2^4 = 5 * 16 = 80
    deret_aritmatika(10,10,5,&result);
    printf("aritmetika prosedure : %d %d %d\n",result[0],result[1],result[2]);
}

int aritmatika(int a, int b, int n)
// Menerima argumen sebuah integer a, b dan n dimana a adalah nilai
// awal deret dan b adalah beda, kemudian 
// mengembalikan nilai deret aritmatika ke-n 
// Contoh:
// aritmatika(10, 10, 5) -> 50
{
    int ar ;
    ar = a + (n-1)*b;
    return ar;
}

int geometri(int a, int r, int n)
// Menerima argumen sebuah integer a, r dan n dimana a adalah nilai
// awal deret dan r adalah rasio, kemudian 
// mengembalikan nilai deret geometri ke-n 
// Contoh:
// geometri(10, 2, 5) -> 160
{
    int hasil = a;
    int i;
    for (i = 2; i <= n; i++)
    {
        hasil = hasil * r; 
    }
    return hasil;
}

void deret_aritmatika(int a, int b, int n, int *result[])
// Menerima argumen sebuah integer a, b dan n dimana a adalah nilai
// awal deret dan b adalah beda, kemudian 
// mengisi nilai result dari U1 hingga Un
// Contoh deret_aritmatika(10, 10, 5) maka
// nilai result = [10, 20, 30, 40, 50]
{
    for(int i = 0; i<n;i++)
    {
        result[i]= aritmatika(a,b,i+1);
    }
    
}

void deret_geometri(int a, int r, int n, int *result[])
// Menerima argumen sebuah integer a, r dan n dimana a adalah nilai
// awal deret dan r adalah rasio, kemudian 
// mengisi nilai result dari U1 hingga Un
// Contoh deret_geometri(10, 2, 5) maka
// nilai result = [10, 20, 40, 80, 160]
{
    result[0]= a;
    for (int i=1;i<n;i++){
        result[i] = geometri(a,r,i+1) ;
    }

    //for (int i = 1; i < n; i++) {
    //    result[i] = result[i - 1] * r;

}

// Menerima argumen sebuah integer n, kemudian 
// mengisi nilai result dari segitiga pascal baris ke-n
// Contoh n = 5, result akan bernilai = [1, 4, 6, 4, 1]

int fact(int x)
        {
    int fact = 1;
    for(int i=1;i<=x;i++){
        fact *= i;
        }
    return fact;
}
int Comb(int n, int r){
    return fact(n) / (fact(r) * fact(n-r));
}

void segitiga_pascal(int n, int *result[]){
    int banyak_data = n;

    // kalau cuman 1 elemen langsung return aja
    if(n == 1){
        *result = 1;
        return;
    }

    // set paling kiri, dan paling kanan selalu 1
    *(result) = 1;
    *(result + n -1) = 1;


    // kerjain yang tengah
    // rumusnya pake kombinatorika

    for(int i=1; i<n-1; i++){
        // C^n-1_i
        *(result + i) = Comb(n-1, i);
    }
}
    /* int i; // jumlah baris 
    int j; // jumlah karakter dalam loop
    int prev[n], new[n];

    for(i=0;i<n;i++){
        for(j=1;j<1;j++){
            new[j]=prev[j-1]+prev[j];
        }
        new[i]=1;
        prev[i]=1;
        for(j=0;j<i;j++){
            prev[j]=new[j];
        }
    }
    for(i=0;i<n;i++){
        result[i]=new[i];
    }
    */



/*

#include <stdio.h>

void segitiga_pascal(int n, int *result) {
    // Menginisialisasi array result dengan 1 karena elemen pertama selalu 1
    result[0] = 1;

    for (int i = 1; i <= n; i++) {
        int current = 1;
        int prev = 1;

        for (int j = 1; j < i; j++) {
            // Menggunakan pendekatan yang lebih efisien untuk menghitung koefisien binomial
            current = current * (i - j) / j;
            result[j] = current;
        }

        // Elemen terakhir selalu 1
        result[i] = 1;
    }
}

int main() {
    int n;
    printf("Masukkan jumlah baris segitiga Pascal yang ingin Anda hitung: ");
    scanf("%d", &n);

    int result[n + 1];
    segitiga_pascal(n, result);

    printf("Hasil segitiga Pascal untuk baris ke-%d adalah: ", n);
    for (int i = 0; i <= n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}

*/