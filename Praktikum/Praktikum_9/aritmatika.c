/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 3 November 2023
    Soal No : 1
*/

#include <stdio.h>
#include "list_circular.h"

int main(){
    int n, i;
    scanf("%d",&n);
    List l;
    CreateList(&l);
    for(i=0; i<n; i++){
        int val;
        scanf("%d",&val);
        insertLast(&l,val);
    }
    int b = INFO(FIRST(l));
    if(NEXT(FIRST(l)) == FIRST(l)){
        printf("%d %d\n", 0 ,b);
    }
    else{
        int a = INFO(NEXT(FIRST(l))) - b;
        boolean aritmetics = true;
        int i = 0;
        Address p = FIRST(l);
        while(aritmetics && NEXT(p) != FIRST(l)){
            if(INFO(p) != (a*i + b)){
                aritmetics = false;
            }
            p = NEXT(p);
            i++;
        }
        if(INFO(p) != (a*i + b)){
            aritmetics = false;
        }
        if(aritmetics){
            printf("%d %d\n", a ,b);
        } else{
            printf("%d %d\n",0,0);
        }
    }
}