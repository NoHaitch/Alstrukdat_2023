/* File : prioqueuechar.h */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen prio */

#include <stdlib.h>
#include <stdio.h>
#include "prioqueuechar.h"

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return (Head(Q) == Nil && Tail(Q) == Nil);
}

boolean IsFull (PrioQueueChar Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return NBElmt(Q) == MaxEl(Q);
}

int NBElmt (PrioQueueChar Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if(IsEmpty(Q)){
        return 0;
    } else if(Tail(Q) >= Head(Q)){
        return Tail(Q)-Head(Q) + 1;
    } else {
        return Tail(Q)-Head(Q) + MaxEl(Q) + 1;
    }
}

/* *** Kreator *** */
void MakeEmpty (PrioQueueChar * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    MaxEl(*Q) = Max + 1;
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{    
    MaxEl(*Q) = 0;
}

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueChar * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
{
    if(IsEmpty(*Q)){
        Head(*Q) = 0;
        Tail(*Q) = 0;
        MaxEl(*Q) ++;
    } else{
        boolean found;
        int idx = 0;
        while(Prio(X) >= Prio(Elmt(*Q,idx)) && idx<NBElmt(*Q)){
            idx ++;
        }
        if(idx == NBElmt(*Q)){
            Elmt(*Q,idx) = X;
            MaxEl(*Q) ++;
            Tail(*Q) ++;
        }
        else{
            // shift right
            MaxEl(*Q) ++;
            Tail(*Q) ++;
            // from tail to idx shift right
            int i;
            for(i = Tail(*Q); i != idx;i--){
                Elmt(*Q,i) = Elmt(*Q,i-1);
            }
            Elmt(*Q,idx) = X;
        }
    }
}

void Dequeue (PrioQueueChar * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    X = Head(*Q);
    if(Head(*Q) == MaxEl(*Q)-1){
        Head(*Q) = 0;
    }else{
        Head(*Q) ++;
    }
}

/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
{
    int i;
    for(int i=0 ; i<NBElmt(Q); i++){
        infotype val;
        Dequeue(&Q,&val);
        printf("%d %d\n",Prio(val), Info(val));
    }
}