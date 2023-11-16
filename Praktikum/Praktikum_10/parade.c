/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 10 November 2023
    Soal No : 2
*/

#include <stdio.h>
#include "stacklinked.h"

int main(){
    int t, i;
    scanf("%d", &t);
    for(i=0; i<t; i++){
        int n, j;
        scanf("%d", &n);

        Stack main, side;
        CreateStack(&main);
        CreateStack(&side);
        int currentMainWanted = 1;
        for(j=0; j<n; j++){
            if(!isEmpty(side)){
                boolean stop = false;
                while(!isEmpty(side) && !stop){
                    if(TOP(side) == currentMainWanted){
                        int temp;
                        pop(&side, &temp);
                        push(&main, temp);
                        currentMainWanted ++;
                    } else{
                        stop = true;
                    }
                }
            }
            int p;
            scanf("%d", &p);
            if(p == currentMainWanted){
                push(&main, p);
                currentMainWanted ++;
            } else{
                push(&side, p);
            }
        }
        while(!isEmpty(side)){
            int temp;
            pop(&side, &temp);
            push(&main, temp);
        }
        boolean sorted = true;
        j = 0;
        while(length(main) != 1 && sorted){
            int top;
            pop(&main, &top);
            if(TOP(main) > top){
                sorted = false;
            }
        }
        if(sorted){
            printf("yes\n");
        } else{
            printf("no\n");
        }
    }
}

/*

3
5
5 1 2 4 3

*/