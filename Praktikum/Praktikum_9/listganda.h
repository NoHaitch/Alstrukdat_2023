/* File : listsirkular.h */
/* contoh ADT list sirkular berkait dengan representasi pointer ganda  */

#ifndef listlinier_H
#define listlinier_H

#include "boolean.h"

/* Definisi Node : */
typedef int ElType;
typedef struct node *Address;
typedef struct node
{
    ElType info;
    Address next;
    Address prev;
} Node;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next
#define PREV(p) (p)->prev

Address newNode(ElType val);

/* Definisi List : */
/* List kosong : CURRENT(l) = NULL */
/* CURRENT: Elemen yang ditunjuk saat ini. Karena sirkular, tidak ada elemen pertama ataupun terakhir. */

typedef struct ListGanda
{
    Address current;
} ListGanda;

#define CURRENT(l) (l).current

/* PROTOTYPE */

void createListGanda(ListGanda *l);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

boolean isEmpty(ListGanda l);
/* Mengirim true jika list kosong */

boolean isOneElement(ListGanda l);
/* Mengirim true jika list terdiri atas 1 elemen saja*/

int length(ListGanda l);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

void rotate(ListGanda *l, int k);
/* I.S. l terdefinisi, l mungkin kosong
    k mungkin positif, nol, maupun negatif, abs(k) mungkin lebih besar dari length(l) */
/* F.S. CURRENT menunjuk ke elemen ke-k dari CURRENT sebelumnya
    dengan k positif artinya ke arah NEXT dan k negatif artinya ke arah PREV */

void insertAfterCurrent(ListGanda *l, ElType x);
/* I.S. l terdefinisi, l mungkin kosong */
/* F.S.
    1. Terbentuk node baru E,
    2. E disisipkan pada NEXT dari CURRENT,
    3. CURRENT menunjuk ke E
 */

void deleteCurrent(ListGanda *l, ElType *x);
/* I.S. l terdefinisi, l tidak kosong */
/* F.S.
    1. Elemen CURRENT (E) dikeluarkan dari list,
    2. CURRENT menunjuk pada NEXT dari E
    3. x berisi nilai E
    4. E dihapus
 */

#endif