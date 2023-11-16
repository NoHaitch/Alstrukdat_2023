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
    Address E = newNode(x);
    if(E != NULL){
        if(isEmpty(*l)){
            CURRENT(*l) = E;
            NEXT(E) = E;
            PREV(E) = E;
        } else{
            Address p = CURRENT(*l);
            NEXT(E) = NEXT(p);
            PREV(NEXT(p)) = E;
            NEXT(p) = E;
        }
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
    Address E = CURRENT(*l);
    *x = INFO(E);
    if(isOneElement(*l)){
        CURRENT(*l) = NULL;
    }else{
        CURRENT(*l) = NEXT(E);
        PREV(NEXT(E))= PREV(E);
    }
    free(E);
}