#include <stdio.h>
#include "queue.h"

int main(){
    int i, n, k, val;
    scanf("%d", &n);
    scanf("%d", &k);
    Queue Q;
    int ref[k];
    CreateQueue(&Q);
    for(i=0; i<n ; i++){
        scanf("%d", &val);
        enqueue(&Q, val);
    }
    for(i=0;i<k;i++){
        dequeue(&Q, &val);
        ref[k-i-1] = val; 
    }
    for(i=0;i<k;i++){
        enqueue(&Q, ref[i]);
    }
    for(i=0; i<n-k;i++){
        dequeue(&Q,&val);
        enqueue(&Q,val);
    }
    displayQueue(Q);
}