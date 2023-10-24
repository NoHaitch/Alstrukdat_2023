#include <stdio.h>
#include "queue.h"

int main(){
    int N;
    scanf("%d",&N);
    int i;
    Queue Q;
    CreateQueue(&Q);
    for(i = 0; i<N; i++){
        int ni;
        int count = 0;
        scanf("%d",&ni);
        int min = ni;
        while(ni != 0){
            int div = 2;
            boolean found = false;
            while(!found && div < ni-1){
                if(ni%div == 0){
                    found = true;
                    ni = ni / div;
                    count ++;
                }
                div ++;
            }
            if(!found){
                count ++;
                ni --;
            }
        }
        if(count < min){
            min = count;
        }
        enqueue(&Q,min);
    }
    int res = 1;
    while(!isEmpty(Q)){
        int val;
        dequeue(&Q,&val);
        res *= val;
    }
    printf("%d\n",res);
}