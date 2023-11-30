/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 27 Oktober 2023
    Soal No : 3
*/

#include "merge.h"

void splitList(List source, List* front, List* back)
/* Fungsi untuk memecah sebuah list dengan head source menjadi dua buah 
   list baru, yaitu front dan back. Apabila panjang list ganjil, maka
   list front akan lebih panjang dibandingkan list back.
   Sebagai contoh untuk list dengan panjang 5, maka list front memiliki
   3 elemen dan list back memiliki 2 elemen.
*/
{
    int len = length(source);
    if(len % 2 == 1){
        len++;
    }
    int mid = len / 2;

    *front = source;
    *back = NULL;

    if (len > 1) {
        Address p = source;
        for (int i = 0; i < mid - 1; i++) {
            p = NEXT(p);
        }

        *back = NEXT(p);
        NEXT(p) = NULL;
    }
}

List merge(List a, List b)
/* Fungsi untuk melakukan merge sort list a dan b secara rekursif.
   Sort dilakukan secara ascending berdasarkan nilai elemen.
   Apabila List a = NULL, maka kembalikan List b
   Apabila List b = NULL, maka kembalikan List a
   Selain itu, lakukan perbandingan antara INFO(a) dengan 
   INFO(b) untuk mendapatkan urutannya
*/
{
    List result = NULL;
    Address p1 = a, p2 = b;

    while (p1 != NULL && p2 != NULL) {
        if (INFO(p1) <= INFO(p2)) {
            result = concat(result, newNode(INFO(p1)));
            p1 = NEXT(p1);
        } else {
            result = concat(result, newNode(INFO(p2)));
            p2 = NEXT(p2);
        }
    }

    while (p1 != NULL) {
        result = concat(result, newNode(INFO(p1)));
        p1 = NEXT(p1);
    }

    while (p2 != NULL) {
        result = concat(result, newNode(INFO(p2)));
        p2 = NEXT(p2);
    }

    return result;
}

void mergeSort(List* list)
/* Fungsi untuk melakukan inisialisasi merge sort secara rekursif.
   Setiap kali fungsi dipanggil, maka tampilkan list yang sekarang
   sedang diproses.
   Apabila head atau NEXT(head) kosong, maka lakukan return
   Fungsi akan membagi list menjadi dua terlebih dahulu, kemudian 
   secara rekursif melakukan merge untuk mengurutkan
*/
{
    displayList(*list);
    printf("\n");
    if (isEmpty(*list) || NEXT(*list) == NULL) {
        return;
    } else {
        List l1, l2;
        splitList(*list, &l1, &l2);

        mergeSort(&l1);
        mergeSort(&l2);

        *list = merge(l1, l2);
    }
}