/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 27 Oktober 2023
    Soal No : 1
*/
#include <stdio.h>
#include "listlinier.h"

int main(){
    int n;
    scanf("%d", &n);
    int i, x, temp;
    List l;
    CreateList(&l);
    int q;
    scanf("%d", &q);
    float hit = 0;
    if (q > 0){
        for (i = 0 ; i < q ; i ++){
            scanf("%d", &x);
            if (isEmpty(l)){
                if (length(l) < n)
                {
                    insertFirst(&l, x);
                }
                printf("miss ");
                displayList(l);
                printf("\n");
            }
            else if (indexOf(l, x) != IDX_UNDEF){
                hit++;
                deleteAt(&l, indexOf(l, x), &temp);
                insertFirst(&l, x);
                printf("hit ");
                displayList(l);
                printf("\n");
            }
            else if (length(l) == n){
                deleteLast(&l, &temp);
                insertFirst(&l, x);

                printf("miss ");
                displayList(l);
                printf("\n");
            }
            else{
                insertFirst(&l, x);
                printf("miss ");
                displayList(l);
                printf("\n");
            }
	    }

        double ratio = hit / q;
        printf("hit ratio: %.2f\n",ratio);
    }

    else{
        printf("hit ratio: %.2f\n",0.00);
    }
    return 0;
}
/*
int main(){
    List l;
    CreateList(&l);
    int n, q, i;
    int hit = 0;
    int miss = 0;
    scanf("%d",&n);
    scanf("%d",&q);
    for(i=0; i<q; i++){
        int x;
        scanf("%d",&x);

        if(isEmpty(l)){
            insertFirst(&l,x);
            printf("miss ");
            displayList(l);
            printf("\n");
            miss++;
        } else{
            int idx = 0;
            boolean found = false;
            while(idx < length(l) && !found){
                if(getElmt(l,idx) == x){
                    found = true;
                }
                else{
                    idx ++;
                }
            }
            if(!found){
                // not found
                if(length(l) < n){
                    insertFirst(&l,x);
                } else{
                    int temp;
                    deleteLast(&l,&temp);
                    insertFirst(&l,x);
                }
                printf("miss ");
                displayList(l);
                printf("\n");
                miss++;
            }
            else{
                int temp;
                deleteAt(&l,idx,&temp);
                insertFirst(&l,x);
                printf("hit ");
                displayList(l);
                printf("\n");
                hit++;
            }
        }
    }
    if(miss+hit == 0){
        printf("hit rasio: 0.00\n");
    }
    else{
        printf("hit rasio: %.2f\n",hit/(float)(miss+hit));
    }
}*/