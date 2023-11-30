/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 27 Oktober 2023
    Soal No : Pra - 1
    Extended Soal No : 2
*/
#include <stdio.h>
#include <stdlib.h> 
#include "listlinier.h"

Address newNode(ElType val)
/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

{
    Address p = (Address) malloc(sizeof(Node));
    if(p != NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
/* Mengirim true jika list kosong */
{
    return FIRST(l) == NULL;
}

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
{
    Address p = FIRST(l);
    int i = 0;
    while (i < idx) {
        p = NEXT(p);
        i++;
    }
    return INFO(p);
}

void setElmt(List *l, int idx, ElType val)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
{
    Address p = FIRST(*l);
    int i = 0;
    while (i < idx) {
        p = NEXT(p);
        i++;
    }
    INFO(p) = val;
}

int indexOf(List l, ElType val)
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
{
    Address p = FIRST(l);
    int i = 0;
    while (p != NULL) {
        if (INFO(p) == val) {
            return i;
        }
        p = NEXT(p);
        i++;
    }
    return IDX_UNDEF;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
{
    Address p = newNode(val);
    NEXT(p) = FIRST(*l);
    FIRST(*l) = p;
}

void insertLast(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    if (isEmpty(*l)) {
        insertFirst(l, val);
    }
    else {
        Address p = newNode(val);
        Address Last = FIRST(*l);
        while (NEXT(Last) != NULL) {
            Last = NEXT(Last);
        }
        NEXT(Last) = p;
    }
}

void insertAt(List *l, ElType val, int idx)
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    if(idx == 0){
        insertFirst(l,val);
    } else{
        Address p = newNode(val);
        Address temp = FIRST(*l);
        int i;
        for (i = 0; i < idx - 1; i++) {
            temp = NEXT(temp);
        }
        NEXT(p) = NEXT(temp);
        NEXT(temp) = p;
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val)
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
{
    Address p = FIRST(*l);
    *val = INFO(p);
    FIRST(*l) = NEXT(p);
    free(p);
}

void deleteLast(List *l, ElType *val)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
{
     if (NEXT(FIRST(*l)) == NULL) {
        deleteFirst(l, val);
    }
    else {
        Address Last = FIRST(*l);
        while (NEXT(NEXT(Last)) != NULL) {
            Last = NEXT(Last);
        }
        *val = INFO(NEXT(Last));
        free(NEXT(Last));
        NEXT(Last) = NULL;
    }
}

void deleteAt(List *l, int idx, ElType *val)
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
{
    if (idx == 0) {
        deleteFirst(l, val);
    }
    else {
        Address Prec = FIRST(*l);
        int i;
        for (i = 0; i < idx - 1; i++) {
            Prec = NEXT(Prec);
        }
        Address P = NEXT(Prec);
        *val = INFO(P);
        NEXT(Prec) = NEXT(P);
        free(P);
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l)
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    if (!isEmpty(l)) {
        Address p = FIRST(l);
        while (p != NULL) {
            printf("%d", INFO(p));
            p = NEXT(p);
            if (p != NULL) {
                printf(",");
            }
        }
    }
    printf("]");
}

int length(List l)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    Address p = FIRST(l);
    int i = 0;
    while(p != NULL){
        p = NEXT(p);
        i++;
    }
    return i;
}

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2)
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    List l3;
    CreateList(&l3);
    Address(p) = FIRST(l1);
    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    p = FIRST(l2);
    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    return l3;
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean fSearch(List L, Address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
    Address p = FIRST(L);
    if(p == P){
        return true;
    } else{
        boolean found = false;
        while (p != NULL && !found) {
            if (p == P) {
                found = true;
            }
            p = NEXT(p);
        }
        return found;
    }
}

Address searchPrec(List L, ElType X)
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
    if(isEmpty(L) || length(L) == 1){
        return NULL;
    }
    Address p = L;
    Address previous;
    while(p != NULL && INFO(p)!= X){
        previous = p;
        p = NEXT(p);
    }
    if(p == NULL){
        return NULL;
    }
    else{
        return previous;
    }
}

/*** Prekondisi untuk Max/Min/Rata-rata : List tidak kosong ***/
ElType maxValue(List l)
/* Mengirimkan nilai info(P) yang maksimum */
{
    Address p = FIRST(l);
    int max = INFO(l);
    while(p != NULL){
        if(INFO(p) > max){
            max = INFO(p);
        }
        p = NEXT(p);
    }
    return max;
}

Address adrMax(List l)
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
{
    Address p = FIRST(l);
    Address maxAddr = FIRST(l);
    int max = INFO(l);
    while(p != NULL){
        if(INFO(p) > max){
            max = INFO(p);
            maxAddr = p;
        }
        p = NEXT(p);
    }
    return maxAddr;
}

ElType minValue(List l)
/* Mengirimkan nilai info(P) yang minimum */
{
    Address p = FIRST(l);
    int min = INFO(l);
    while(p != NULL){
        if(INFO(p) < min){
            min = INFO(p);
        }
        p = NEXT(p);
    }
    return min;
}

Address adrMin(List l)
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
{
    Address p = FIRST(l);
    Address minAddr = FIRST(l);
    int min = INFO(l);
    while(p != NULL){
        if(INFO(p) < min){
            min = INFO(p);
            minAddr = p;
        }
        p = NEXT(p);
    }
    return minAddr;
}

float average(List L)
/* Mengirimkan nilai rata-rata info(P) */
{
    Address p = FIRST(L);
    float sum = 0;
    int count = 0;
    while(p != NULL){
        sum += INFO(p);
        p = NEXT(p);
        count++;
    }
    if (count > 0) {
        return sum / count;
    } else {
        return 0;
    }
}

/***************** FUNGSI dan PROSEDUR TAMBAHAN **************/
void deleteAll(List *l)
/* Delete semua elemen list dan alamat elemen di-dealokasi */
{
    Address p = FIRST(*l);
    Address temp;
    while (p != NULL) {
        temp = p;
        p = NEXT(p);
        free(temp);
    }
    FIRST(*l) = NULL;  // Set list to empty
}

void copyList(List *l1, List *l2)
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
{
    FIRST(*l2) = FIRST(*l1);
}

void inverseList(List *l)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
    Address current = FIRST(*l);
    Address prev = NULL;
    Address next;

    while (current != NULL) {
        next = NEXT(current);
        NEXT(current) = prev;
        prev = current;
        current = next;
    }

    FIRST(*l) = prev;
}