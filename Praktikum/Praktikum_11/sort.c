/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 17 November 2023
    Soal No : 2
*/

#include "sort.h"
#include <stdlib.h>

List insertSorted(List l, ElType x) {
    if (isEmpty(l) || x <= INFO(l)) {
        return konso(l, x);
    } else {
        NEXT(l) = insertSorted(NEXT(l), x);
        return l;
    }
}

List deleteFirst(List l)
/* Fungsi untuk menghapus elemen pertama sebuah list l */
{
    Address p = l;
    l = NEXT(l);
    free(p);
    return l;
}

List deleteAt(List l, int idx)
/* Fungsi untuk menghapus elemen pada posisi/index idx sebuah list l */
{
    if(idx == 0){
        return deleteFirst(l);
    } else{
        return konso(deleteAt(NEXT(l),idx-1),INFO(l));
    }
}


Address findMiddle(List l)
/* Fungsi untuk mencari middle dari list l.
   Fungsi akan mengembalikan Address dari middle tersebut.
   Apabila list ganjil, maka middle adalah elemen tengah.
   Apabila list genap, maka middle adalah elemen tengah kiri.
*/
{
    int len = length(l);
    int i = 0;
    if(len % 2 == 0){
        len--;
    }
    Address p = l;
    while(i < (int)(len/2)){
        p = tail(p);
        i++;
    }
    return p;
}

List merge(List l1, List l2)
/* melakukan merge sort list a dan b secara rekursif.
   Sort dilakukan secara ascending berdasarkan nilai elemen.
*/
{
    List result = NULL;
    Address p1 = l1, p2 = l2;

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

void splitList(List l, List* l1, List* l2) {
    int len = length(l);
    int mid = len / 2;
    
    *l1 = l;
    *l2 = NULL;

    if (len > 1) {
        Address p = l;
        for (int i = 0; i < mid - 1; i++) {
            p = NEXT(p);
        }   

        *l2 = NEXT(p);
        NEXT(p) = NULL;
    }
}

List mergeSort(List l)
/* Fungsi untuk melakukan inisialisasi merge sort secara rekursif.
   Apabila head atau NEXT(head) kosong, maka mengembalikan list tersebut.
   Fungsi akan membagi list menjadi dua terlebih dahulu, kemudian
   secara rekursif melakukan merge untuk mengurutkan.
*/
{
    if(isEmpty(l) || isEmpty(NEXT(l))){
        return l;
    } else{
        List l1, l2;
        splitList(l, &l1, &l2);
        
        l1 = mergeSort(l1);
        l2 = mergeSort(l2);

        return merge(l1, l2);
    }
}

List zigZagSort(List l)
/* Fungsi untuk melakukan zig-zag sort.
   Zig-zag sort adalah suatu teknik pengurutan dengan cara
   mengurutkan elemen-elemen dengan pola:
   terbesar 1 - terkecil 1 - terbesar 2 - terkecil 2 .. dst.
   Contoh:
   2 8 5 3 1
   1 8 2 4 3
*/
{  
    if (isEmpty(l) || isOneElmt(l)) {
        return l;
    } else {
        List result = NULL;
        boolean smallest = true;

        while (l != NULL) {
            Address p = l;
            if (smallest) {
                ElType min = head(p);
                int idx = 0;
                int i = 0;
                while(p != NULL){
                    if(head(p) < min){
                        min = head(p);
                        idx = i;
                    }
                    p = tail(p);
                    i++;
                }
                result = konsb(result, min);
                l = deleteAt(l, idx);
                smallest = false;
            } else {
                ElType max = head(p);
                int idx = 0;
                int i = 0;
                while(p != NULL){
                    if(head(p) > max){
                        max = head(p);
                        idx = i;
                    }
                    p = tail(p);
                    i++;
                }
                result = konsb(result, max);
                l = deleteAt(l, idx);
                smallest = true;
            }
        }
        return result;
    }
}

