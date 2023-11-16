/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 3 November 2023
    Soal No : 2
*/

#include <stdio.h>
#include "list_circular.h"

int main(){
    int n, i;
    scanf("%d",&n);
    List l;
    CreateList(&l);
    for(i=1; i<n+1; i++){
        insertLast(&l,i);
    }
    boolean shiftleft = false;
    for(i=0; i<n-1; i++){
        int a;
        scanf("%d",&a);
        while (a != 0)
        {
            int temp;
            if(a > 0){
                // shift right
                deleteFirst(&l,&temp);
                insertLast(&l,temp);
                a--;
            } else{
                // shift left
                deleteLast(&l,&temp);
                insertFirst(&l,temp);
                a++;
                shiftleft = true;
            }
        }
        int val;
        if(i == n-2){
            int temp;
            deleteLast(&l,&temp);
            insertFirst(&l,temp);
            shiftleft = false;
        }
        deleteFirst(&l, &val);
        if(shiftleft){
            int temp;
            deleteLast(&l,&temp);
            insertFirst(&l,temp);
            shiftleft = false;
        }
    }
    printf("%d\n",INFO(FIRST(l)));
}