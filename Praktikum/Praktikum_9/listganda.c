/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 3 November 2023
    Soal No : 3
*/

#include <stdlib.h>
#include "listganda.h"

/* Definisi Node : 
typedef int ElType;
typedef struct node *Address;
typedef struct node
{
    ElType info;
    Address next;
    Address prev;
} Node;

*/

Address newNode(ElType val){
    Address p = (Address) malloc(sizeof(Node));
    if(p != NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

/* Definisi List : */
/* List kosong : CURRENT(l) = NULL */
/* CURRENT: Elemen yang ditunjuk saat ini. Karena sirkular, tidak ada elemen pertama ataupun terakhir. */

/*
typedef struct ListGanda
{
    Address current;
} ListGanda;

#define CURRENT(l) (l).current

/* PROTOTYPE */

void createListGanda(ListGanda *l)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    CURRENT(*l) = NULL;
}

boolean isEmpty(ListGanda l)
/* Mengirim true jika list kosong */
{
    return (CURRENT(l) == NULL);
}

boolean isOneElement(ListGanda l)
/* Mengirim true jika list terdiri atas 1 elemen saja*/
{
    return (NEXT(CURRENT(l)) == CURRENT(l));
}

int length(ListGanda l)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    if(isEmpty(l)){
        return 0;
    } else{
        int count = 0;
        Address first = CURRENT(l);
        Address p = first;
        while(NEXT(p) != first){
            p = NEXT(p);
            count ++;
        }
        count ++;
        return count;
    }
}

void rotate(ListGanda *l, int k)
/* I.S. l terdefinisi, l mungkin kosong
    k mungkin positif, nol, maupun negatif, abs(k) mungkin lebih besar dari length(l) */
/* F.S. CURRENT menunjuk ke elemen ke-k dari CURRENT sebelumnya
    dengan k positif artinya ke arah NEXT dan k negatif artinya ke arah PREV */
{
    if(!isEmpty(*l)){
        Address p = CURRENT(*l);
        if(k > 0){
            while(k > 0){
                p = NEXT(p);
                k--;
            }
        }
        else if(k<0){
            while(k < 0){
                p = PREV(p);
                k++;
            }
        }
        CURRENT(*l) = p;
    }
}


void insertAfterCurrent(ListGanda *l, ElType x)
/* I.S. l terdefinisi, l mungkin kosong */
/* F.S.
    1. Terbentuk node baru E,
    2. E disisipkan pada NEXT dari CURRENT,
    3. CURRENT menunjuk ke E
 */
{
    Address p = newNode(x);
    if (p != NULL) {
        if (isEmpty(*l)) {
            // Jika list kosong, CURRENT menunjuk pada dirinya sendiri
            NEXT(p) = p;
            PREV(p) = p;
        } else {
            // Jika list tidak kosong
            Address currentNext = NEXT(CURRENT(*l));

            // Sisipkan node baru setelah CURRENT
            NEXT(CURRENT(*l)) = p;
            PREV(p) = CURRENT(*l);
            NEXT(p) = currentNext;
            PREV(currentNext) = p;
        }

        // CURRENT menunjuk ke node baru
        CURRENT(*l) = p;
    }
}

void deleteCurrent(ListGanda *l, ElType *x)
/* I.S. l terdefinisi, l tidak kosong */
/* F.S.
    1. Elemen CURRENT (E) dikeluarkan dari list,
    2. CURRENT menunjuk pada NEXT dari E
    3. x berisi nilai E
    4. E dihapus
 */
{
    // Elemen yang akan dihapus
    Address p = CURRENT(*l);
    *x = INFO(p);

    if (NEXT(p) == p) {
        // Jika CURRENT adalah satu-satunya elemen dalam list
        free(p);
        CURRENT(*l) = NULL;
    } else {
        // Jika CURRENT bukan satu-satunya elemen
        Address currentPrev = PREV(p);
        Address currentNext = NEXT(p);

        // Hapus elemen CURRENT dari list
        NEXT(currentPrev) = currentNext;
        PREV(currentNext) = currentPrev;

        // CURRENT menunjuk ke NEXT dari E (elemen yang dihapus)
        CURRENT(*l) = currentNext;

        // Hapus elemen yang dihapus
        free(p);
    }
}