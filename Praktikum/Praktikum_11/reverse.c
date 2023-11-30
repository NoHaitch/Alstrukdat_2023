/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 17 November 2023
    Soal No : 3
*/

#include <stdlib.h>
#include <stdio.h>
#include "listrec.h"

void splitOnIdx(List l, int idx ,List *l1, List *l2){
    if (isEmpty(l)){
        *l1 = NULL;
        *l2 = NULL;
    } else{
        if (idx > 0){
            splitOnIdx(tail(l),idx-1, l1, l2);
            *l1 = konso(*l1,head(l));
        }
        else{
            splitOnIdx(tail(l), idx, l1, l2);
            *l2 = konso(*l2,head(l));
        }
    }
}

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

int main(){
    int n, i, q, x, y;
    scanf("%d", &n);
    List l, l1, l2;
    for(i=0; i<n; i++){
        scanf("%d", &x);
        if(i == 0){
            l = newNode(x);
        } else{
            l = insertAt(l, x, length(l));
        }
    }
    scanf("%d", &q);
    for(i=0; i<q; i++){
        scanf("%d",&y);
        splitOnIdx(l, y, &l1, &l2);
        l1 = inverseList(l1);
        l2 = inverseList(l2);
        l = concat(l1, l2);
    }
    while(l != NULL){
        printf("%d\n", INFO(l));
        l = tail(l);
    }
}
