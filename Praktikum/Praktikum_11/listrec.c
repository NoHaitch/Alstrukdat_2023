/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 17 November 2023 
    Soal No : Pra - 1
    Soal No : 1
*/

#include "listrec.h"
#include <stdlib.h>
#include <stdio.h>

/* Manajemen Memori */
Address newNode(ElType x)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NIL, dan misalnya
   menghasilkan p, maka INFO(p)=x, NEXT(p)=NIL */
/* Jika alokasi gagal, mengirimkan NIL */
{
    Address p = (Address) malloc(sizeof(Node));
    if (p != NIL) {
        INFO(p) = x;
        NEXT(p) = NIL;
    }
    return p;
}

/* Pemeriksaan Kondisi Lis */
boolean isEmpty(List l)
/* Mengirimkan true jika l kosong dan false jika l tidak kosong */
{
    return l == NIL;
}

boolean isOneElmt(List l)
/* Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong */
{
    return length(l) == 1;   
}

/* Primitif-Primitif Pemrosesan List */
ElType head(List l)
/* Mengirimkan elemen pertama sebuah list l yang tidak kosong */
{
    return INFO(l);
}

List tail(List l)
/* Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong */
{
    return NEXT(l);
}

List konso(List l, ElType e)
/* Mengirimkan list l dengan tambahan e sebagai elemen pertamanya. e dialokasi terlebih dahulu. 
   Jika alokasi gagal, mengirimkan l */
{
    Address p = newNode(e);
    if(p != NIL){
        NEXT(p) = l;
        return p;
    } else{
       return l;
    }
}

List konsb(List l, ElType e)
/* Mengirimkan list l dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan l */ 
{
    Address p = newNode(e);
    if(p != NIL){
        if(isEmpty(l)){
            return p;
        } else{
            NEXT(l) = konsb(tail(l), e);
            return l;
        }
    }
    else{
        return l;
    }
}

List copy(List l)
/* Mengirimkan salinan list Ll (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan l */
{
    if (isEmpty(l)) {
        return NIL;
    } else {
        return konso(copy(tail(l)), head(l));
    }
} 

List concat(List l1, List l2)
/* Mengirimkan salinan hasil konkatenasi list l1 dan l2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan NIL */
{
    if (isEmpty(l1)) {
        return copy(l2);
    } else {
        return konso(concat(tail(l1), l2), head(l1));
    }
}

/* Fungsi dan Prosedur Lain */
int length(List l)
/* Mengirimkan banyaknya elemen list l, mengembalikan 0 jika l kosong */
{
    if (isEmpty(l))
        return 0;
    else
        return 1 + length(tail(l));
}

boolean isMember(List l, ElType x)
/* Mengirimkan true jika x adalah anggota list l dan false jika tidak */
{
    if (isEmpty(l))
        return false;
    else if (head(l) == x)
        return true;
    else
        return isMember(tail(l), x);
}

void displayList(List l)
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke bawah */
/*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
  1
  20
  30
 */
/* Jika list kosong, tidak menuliskan apa-apa  */
{
    if(!isEmpty(l)){
        printf("%d\n", head(l));
        displayList(tail(l));
    }
}

/*** Tambahan primitif pemrosesan list ***/
List insertAt(List l, ElType e, int idx)
/* Fungsi untuk menambahkan e sebagai elemen pada posisi/index idx sebuah list l */
{
    if(idx == 0){
        return konso(l,e);
    }
    else{
        return konso(insertAt(NEXT(l), e, idx-1), INFO(l));
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

List deleteLast(List l)
/* Fungsi untuk menghapus elemen terakhir sebuah list l */
{
    return deleteAt(l, length(l)-1);
}

/*** Operasi-Operasi Lain ***/
List inverseList (List l)
/* Mengirimkan list baru, hasil invers dari l dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */
{
    if (isEmpty(l)){
        return l;
    }
    else if(isOneElmt(l)){
        return l;
    }
    else{
        return konsb(inverseList(tail(l)),head(l));
    }
}

void splitPosNeg (List l, List *l1, List *l2)
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan l, dibentuk dua buah list l1 dan l2 */ 
/* l1 berisi semua elemen l yang positif atau 0, sedangkan l2 berisi
semua elemen l yang negatif; semua dengan urutan yang sama seperti di l */
/* l tidak berubah: Semua elemen l1 dan l2 harus dialokasi */
/* Jika l kosong, maka l1 dan l2 kosong */
{
    if (isEmpty(l)){
        *l1 = NULL;
        *l2 = NULL;
    }
    else{
        if (head(l) >= 0){
            splitPosNeg(tail(l), l1, l2);
            *l1 = konso(*l1,head(l));
        }
        else{
            splitPosNeg(tail(l), l1, l2);
            *l2 = konso(*l2,head(l));
        }
    }
}

void splitOnX (List l, ElType x, List *l1, List *l2)
/* I.S. l dan x terdefinisi, l1 dan l2 sembarang. */
/* F.S. l1 berisi semua elemen l yang lebih kecil dari x, dengan urutan
kemunculan yang sama, l2 berisi semua elemen l yang tidak masuk ke
l1, dengan urutan kemunculan yang sama. */
{
    if (isEmpty(l)){
        *l1 = NULL;
        *l2 = NULL;
    }
    else{
        splitOnX(tail(l),x,l1,l2);
        if (head(l) < x){
            *l1 = konso(*l1,head(l));
        }
        else{
            *l2 = konso(*l2, head(l));
        }
    }
}

List removeDuplicate(List l, List unique)
/* l dan unique terdefinisi, l sembarang dan unique digunakan sebagai tempat menyimpan elemen unik */
/* Mengembalikan list yang berisi elemen unik */
/* Urutan masuk ke dalam list unique menggunakan konso */
{
    if(isOneElmt(l) && isMember(unique, head(l))){
        return unique;
    } else if(isOneElmt(l)){
        unique = konso(unique,head(l));
        return unique;
    } else if(isMember(unique, head(l))){
        return removeDuplicate(tail(l), unique);
    } else{
        unique = konso(unique,head(l));
        return removeDuplicate(tail(l), unique);
    }
}