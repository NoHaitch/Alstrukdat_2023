/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 3 Oktober 2023
    Soal No : 3
*/

#include <stdio.h>
#include "stack.h"


void SortirKeranjang (Stack * S1, Stack * S2)
/* Menyortir keranjang S1 menggunakan bantuan S2 */
/* I.S. S1 tidak terurut dan S2 kosong */
/* F.S. S1 kosong dan S2 terurut */
/* Contoh: */
/*            TOP */
/* I.S. S1 = [23, 92, 98, 31, 3, 34]; S2 = [] */
/*                     TOP */
/* I.S. S1 = []; S2 = [3, 23, 31, 34, 92, 98] */
{
    Stack Stemp;
    CreateEmpty(&Stemp);
    CreateEmpty(S2);
    int val;
    Pop(S1,&val);
    Push(S2,val);
    while(!IsEmpty(*S1)){;
        if(InfoTop(*S1) <= InfoTop(*S2)){
            Pop(S1,&val);
            Push(S2,val);
        } else{
            while(InfoTop(*S1) > InfoTop(*S2) && !IsEmpty(*S2)){
                int temp;
                Pop(S2,&temp);
                Push(&Stemp,temp);
            }
            Pop(S1,&val);
            Push(S2,val);
            while(!IsEmpty(Stemp)){
                int temp;
                Pop(&Stemp,&temp);
                Push(S2,temp);
            }
        }
    }
}

/* Driver

void printStack(Stack S){
    printf("[");
    while(!IsEmpty(S)){
        int val;
        Pop(&S,&val);
        printf("%d",val);
        if(!IsEmpty(S)){
            printf(", ");
        }
    }
    printf("]\n");
}

int main(){
    Stack S1, S2;
    CreateEmpty(&S1);
    CreateEmpty(&S2);
    for(int i = 0; i < 10; i++){
        int x;
        scanf("%d",&x);
        Push(&S1,x);
    }
    SortirKeranjang(&S1,&S2);
    printStack(S2);
}
*/
