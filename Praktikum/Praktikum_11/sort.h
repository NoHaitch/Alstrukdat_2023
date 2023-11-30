#ifndef LISTREC_SORT_H
#define LISTREC_SORT_H

#include "listrec.h"

Address findMiddle(List l);
/* Fungsi untuk mencari middle dari list l.
   Fungsi akan mengembalikan Address dari middle tersebut.
   Apabila list ganjil, maka middle adalah elemen tengah.
   Apabila list genap, maka middle adalah elemen tengah kiri.
*/

List merge(List l1, List l2);
/* melakukan merge sort list a dan b secara rekursif.
   Sort dilakukan secara ascending berdasarkan nilai elemen.
*/

List mergeSort(List l);
/* Fungsi untuk melakukan inisialisasi merge sort secara rekursif.
   Apabila head atau NEXT(head) kosong, maka mengembalikan list tersebut.
   Fungsi akan membagi list menjadi dua terlebih dahulu, kemudian
   secara rekursif melakukan merge untuk mengurutkan.
*/

List zigZagSort(List l);
/* Fungsi untuk melakukan zig-zag sort.
   Zig-zag sort adalah suatu teknik pengurutan dengan cara
   mengurutkan elemen-elemen dengan pola:
   terbesar 1 - terkecil 1 - terbesar 2 - terkecil 2 .. dst.
   Contoh:
   2 8 5 3 1
   1 8 2 4 3
*/

void splitList(List l, List* l1, List* l2);

List insertSorted(List l, ElType x);

List deleteAt(List l, int idx);


#endif