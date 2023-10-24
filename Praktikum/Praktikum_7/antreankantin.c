#include <stdio.h>
#include "queue.h"

int main(){
    int time = 0;
    int count = 0;
    int opsi;
    Queue q;
    CreateQueue(&q);
    scanf("%d",&opsi);
    while(opsi != 0){
        if(opsi == 1){
            int val;
            scanf("%d",&val);
            if(isFull(q)){
                printf("Queue penuh\n");
            }
            else{
               enqueue(&q,val); 
            }
        } else if(opsi == 2){
            if(isEmpty(q)){
                printf("Queue kosong\n");
            }
            else{
                int val;
                dequeue(&q,&val); 
                count++;
                time += val;
            }
        }
        scanf("%d",&opsi);
    }
    printf("%d\n",count);
    if(count == 0){
        printf("Tidak bisa dihitung\n");
    }
    else{
        float res = time/(float)count;
        printf("%.2f\n", res);
    }
}