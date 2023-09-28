#ifndef DERET
#define DERET

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

// Menerima argumen sebuah integer a, b dan n dimana a adalah nilai
// awal deret dan b adalah beda, kemudian 
// mengembalikan nilai deret aritmatika ke-n 
// Contoh:
// aritmatika(10, 10, 5) -> 50
int aritmatika(int a, int b, int n);

// Menerima argumen sebuah integer a, r dan n dimana a adalah nilai
// awal deret dan r adalah rasio, kemudian 
// mengembalikan nilai deret geometri ke-n 
// Contoh:
// geometri(10, 2, 5) -> 160
int geometri(int a, int r, int n);

// Menerima argumen sebuah integer a, b dan n dimana a adalah nilai
// awal deret dan b adalah beda, kemudian 
// mengisi nilai result dari U1 hingga Un
// Contoh deret_aritmatika(10, 10, 5) maka
// nilai result = [10, 20, 30, 40, 50]
void deret_aritmatika(int a, int b, int n, int *result[]);

// Menerima argumen sebuah integer a, r dan n dimana a adalah nilai
// awal deret dan r adalah rasio, kemudian 
// mengisi nilai result dari U1 hingga Un
// Contoh deret_geometri(10, 2, 5) maka
// nilai result = [10, 20, 40, 80, 160]
void deret_geometri(int a, int r, int n, int *result[]);

// Menerima argumen sebuah integer n, kemudian 
// mengisi nilai result dari segitiga pascal baris ke-n
// Contoh n = 5, result akan bernilai = [1, 4, 6, 4, 1]
void segitiga_pascal(int n, int *result[]);


#endif