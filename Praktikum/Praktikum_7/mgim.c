/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 3 Oktober 2023
    Soal No : 3
*/

#include <stdio.h>
#include "queue.c"

int getStep(int x){
    int count = 0;
    while(x != 0){
        printf("%d-",x);
        int div = 2;
        boolean found = false;
        while(!found && div < x-1){
            if(x%div == 0){
                found = true;
                x = x / div;
                count ++;
            }
            div ++;
        }
        if(!found){
            count ++;
            x --;
        }
    }
    printf("%d ",x);
    return count;
}

int main(){
    int N;
    scanf("%d",&N);
    int i, j, x;
    Queue Q;
    CreateQueue(&Q);
    for(j = 0; j < N; j++){
        scanf("%d",&x);
        int minStep = x;
        int currStep = 0;
        for(i = 0; i < x; i++){
            currStep = i + getStep(x-i);
            if(currStep < minStep){
                minStep = currStep;
            }
            printf("> %d\n",currStep);
        }
        enqueue(&Q,minStep);
        printf("%d ---> %d\n",x,minStep);
    }
    int res = 1;
    while(!isEmpty(Q)){
        int temp;
        dequeue(&Q,&temp);
        res = res * temp;
    }
    printf("%d\n",res);
}