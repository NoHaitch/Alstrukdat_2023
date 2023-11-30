#ifndef LISTREC_H
#define LISTREC_H

#include "boolean.h"
#include <stdio.h>

#define NIL NULL

typedef int ElType;
typedef struct node* Address;
typedef struct node { 
    ElType info;
    Address next;
} Node;

typedef Address List;

/* Selektor */
#define INFO(p) (p)->info
#define NEXT(p) (p)->next

/* Manajemen Memori */
Address newNode(ElType x);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NIL, dan misalnya
   menghasilkan p, maka INFO(p)=x, NEXT(p)=NIL */
/* Jika alokasi gagal, mengirimkan NIL */

/* Pemeriksaan Kondisi List */
boolean isEmpty(List l);
/* Mengirimkan true jika l kosong dan false jika l tidak kosong */
boolean isOneElmt(List l);
/* Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong */

/* Primitif-Primitif Pemrosesan List */
ElType head(List l);
/* Mengirimkan elemen pertama sebuah list l yang tidak kosong */
List tail(List l);
/* Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong */
List konso(List l, ElType e);
/* Mengirimkan list l dengan tambahan e sebagai elemen pertamanya. e dialokasi terlebih dahulu. 
   Jika alokasi gagal, mengirimkan l */
List konsb(List l, ElType e);
/* Mengirimkan list l dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan l */ 
List copy(List l);
/* Mengirimkan salinan list Ll (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan l */ 
List concat(List l1, List l2);
/* Mengirimkan salinan hasil konkatenasi list l1 dan l2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan NIL */

/* Fungsi dan Prosedur Lain */
int length(List l);
/* Mengirimkan banyaknya elemen list l, mengembalikan 0 jika l kosong */
boolean isMember(List l, ElType x);
/* Mengirimkan true jika x adalah anggota list l dan false jika tidak */
void displayList(List l);
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke bawah */
/*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
  1
  20
  30
 */
/* Jika list kosong, tidak menuliskan apa-apa  */

/*** Tambahan primitif pemrosesan list ***/
List insertAt(List l, ElType e, int idx);
/* Fungsi untuk menambahkan e sebagai elemen pada posisi/index idx sebuah list l */

List deleteFirst(List l);
/* Fungsi untuk menghapus elemen pertama sebuah list l */

List deleteAt(List l, int idx);
/* Fungsi untuk menghapus elemen pada posisi/index idx sebuah list l */

List deleteLast(List l);
/* Fungsi untuk menghapus elemen terakhir sebuah list l */

/*** Operasi-Operasi Lain ***/
List inverseList (List l);
/* Mengirimkan list baru, hasil invers dari l dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */

void splitPosNeg (List l, List *l1, List *l2);
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan l, dibentuk dua buah list l1 dan l2 */ 
/* l1 berisi semua elemen l yang positif atau 0, sedangkan l2 berisi
semua elemen l yang negatif; semua dengan urutan yang sama seperti di l */
/* l tidak berubah: Semua elemen l1 dan l2 harus dialokasi */
/* Jika l kosong, maka l1 dan l2 kosong */

void splitOnX (List l, ElType x, List *l1, List *l2);
/* I.S. l dan x terdefinisi, l1 dan l2 sembarang. */
/* F.S. l1 berisi semua elemen l yang lebih kecil dari x, dengan urutan
kemunculan yang sama, l2 berisi semua elemen l yang tidak masuk ke
l1, dengan urutan kemunculan yang sama. */

List removeDuplicate(List l, List unique);
/* l dan unique terdefinisi, l sembarang dan unique digunakan sebagai tempat menyimpan elemen unik */
/* Mengembalikan list yang berisi elemen unik */
/* Urutan masuk ke dalam list unique menggunakan konso */

#endif