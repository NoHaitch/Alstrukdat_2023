/* File: deque.h */

#ifndef DEQUE_H
#define DEQUE_H
#include "boolean.h"
#include <stdlib.h>

#define NIL NULL
/* Deklarasi infotype */
typedef int ElType;
/* Deque dengan representasi berkait dengan pointer */
typedef struct node* Address;
typedef struct node { 
    ElType info;
    Address next; 
} Node; 
/* Type Deque dengan ciri HEAD dan TAIL: */
typedef struct {
    Address addrHead; /* alamat head */
    Address addrTail; /* alamat tail */
} Deque;

/* Selektor */
#define NEXT(p) (p)->next
#define INFO(p) (p)->info

#define ADDR_HEAD(q) (q).addrHead
#define ADDR_TAIL(q) (q).addrTail
#define      HEAD(q) (q).addrHead->info
#define      TAIL(q) (q).addrTail->info

/* Prototype manajemen memori */
Address newNode(ElType x);
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau NIL jika alokasi gagal */
boolean isEmpty(Deque q);
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NIL and ADDR_TAIL(q)=NIL */
int length(Deque q);
/* Mengirimkan banyaknya elemen Deque. Mengirimkan 0 jika q kosong */

/*** Kreator ***/
void CreateDeque(Deque *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */
void DisplayDeque(Deque q);
/* Proses : Menuliskan isi Deque, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Deque kosong : menulis [] */

/*** Primitif Enqueue/Dequeue ***/
void EnqueueHead(Deque *q, ElType x);
/* Proses: Mengalokasi x dan menambahkan x pada bagian HEAD dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertFirst */
/* I.S. q mungkin kosong */
/* F.S. x menjadi HEAD, HEAD "maju" */
void DequeueHead(Deque *q, ElType *x);
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
void EnqueueTail(Deque *q, ElType x);
/* Proses: Mengalokasi x dan menambahkan x pada bagian TAIL dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi TAIL, TAIL "mundur" */
void DequeueTail(Deque *q, ElType *x);
/* Proses: Menghapus x pada bagian TAIL dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteLast */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen TAIL pd I.S., TAIL "maju" */

#endif