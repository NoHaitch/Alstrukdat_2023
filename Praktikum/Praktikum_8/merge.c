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
    int idxfront = 0;
    int idxback = (length(source)/2);
    if(length(source) % 2 != 0){
        idxback ++;
    } 
    while(idxfront < idxback){
        insertLast(front,getElmt(source,idxfront));
        idxfront++;
    }
    while(idxback < length(source)){
        insertLast(back,getElmt(source,idxback));
        idxback++;
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
    if(length(a) == 1 && length(b) == 1){
        displayList(a);
        printf("\n");
        displayList(b);
        printf("\n");
    }
    if(a == NULL){
        return b;
    } else if(b == NULL){
        return a;
    } else{
        if(INFO(a) <= INFO(b)){
            return concat(a,b);
        } else{
            return concat(b,a);
        }
    }
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
    List front, back;
    CreateList(&front);
    CreateList(&back);
    splitList(*list,&front,&back);
    if(length(front) > 1){
        mergeSort(&front);
    }
    if(length(back) > 1){
        mergeSort(&back);
    }
    *list = merge(front,back);
}