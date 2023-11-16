/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 10 November 2023
    Soal No : 3
*/

#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

/* Prototype manajemen memori */
Address newNode(ElType x)
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau NIL jika alokasi gagal */
{
    Address p = (Address) malloc (sizeof(Node));
        if(p != NULL){
            INFO(p) = x;
            NEXT(p) = NULL;
        }
}

boolean isEmpty(Deque q)
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NIL and ADDR_TAIL(q)=NIL */
{
    return (ADDR_HEAD(q) == NULL) && (ADDR_TAIL(q) == NULL);
}

int length(Deque q)
/* Mengirimkan banyaknya elemen Deque. Mengirimkan 0 jika q kosong */
{
    if(isEmpty(q)){
        return 0;
    } else{
        int count = 0;
        Address p = ADDR_HEAD(q);
        while(p != NULL){
            p = NEXT(p);
            ++count;
        }
        return count;
    }
}

/*** Kreator ***/
void CreateDeque(Deque *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */
{
    ADDR_HEAD(*q) = NULL;
    ADDR_TAIL(*q) = NULL;
}

void DisplayDeque(Deque q)
/* Proses : Menuliskan isi Deque, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Deque kosong : menulis [] */
{
    printf("[");
    Address p = ADDR_HEAD(q);
    while(p != NULL){
        if(NEXT(p) != NULL){
            printf("%d,", INFO(p));
        } else{
            printf("%d", INFO(p));
        }
        p = NEXT(p);
    }
    printf("]");
}

/*** Primitif Enqueue/Dequeue ***/
void EnqueueHead(Deque *q, ElType x)
/* Proses: Mengalokasi x dan menambahkan x pada bagian HEAD dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertFirst */
/* I.S. q mungkin kosong */
/* F.S. x menjadi HEAD, HEAD "maju" */
{
    Address p = newNode(x);
    if(p != NULL){
        if(isEmpty(*q)){
            ADDR_HEAD(*q) = p;
            ADDR_TAIL(*q) = p;
        } else{
            Address n = ADDR_HEAD(*q);
            NEXT(p) = n;
            ADDR_HEAD(*q) = p;
        }
    }
}

void DequeueHead(Deque *q, ElType *x)
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
    Address p = ADDR_HEAD(*q);
    *x = HEAD(*q);
    ADDR_HEAD(*q) = NEXT(ADDR_HEAD(*q));
    if(ADDR_HEAD(*q) == NULL){
        ADDR_TAIL(*q) = NULL;
    }
    NEXT(p) = NULL;
    free(p);
}

void EnqueueTail(Deque *q, ElType x)
/* Proses: Mengalokasi x dan menambahkan x pada bagian TAIL dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi TAIL, TAIL "mundur" */
{
    Address p = newNode(x);
    if(p != NULL){
        if(isEmpty(*q)){
            ADDR_HEAD(*q) = p;
            ADDR_TAIL(*q) = p;
        } else{
            Address n = ADDR_TAIL(*q);
            NEXT(n) = p;
            ADDR_TAIL(*q) = p;
        }
    }
}

void DequeueTail(Deque *q, ElType *x)
/* Proses: Menghapus x pada bagian TAIL dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteLast */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen TAIL pd I.S., TAIL "maju" */
{
    if(length(*q) == 1){
        DequeueHead(q,x);
    } else{
        Address p = ADDR_TAIL(*q);
        *x = TAIL(*q);

        Address n = ADDR_HEAD(*q);
        while(NEXT(NEXT(n)) != NULL){
            n = NEXT(n);
        }
        NEXT(n) = NULL;
        ADDR_TAIL(*q) = n;
        free(p);
    }
}
// 17 - 22, 24 25