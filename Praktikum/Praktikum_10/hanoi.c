/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 10 November 2023
    Soal No : 1
*/

#include <stdio.h>
#include "stacklinked.h"

int main(){
    int n, i;
    scanf("%d", &n);
    Stack S1, S2, S3;
    CreateStack(&S1);
    push(&S1, 5);
    push(&S1, 4);
    push(&S1, 3);
    push(&S1, 2);
    push(&S1, 1);
    CreateStack(&S2);
    CreateStack(&S3);
    for(i = 0; i < n; i++){
        int in, out;
        scanf("%d", &in);
        scanf("%d", &out);
        Stack* Sin, *Sout;
        if(in == 1){
            Sin = &S1;
        } else if(in == 2){
            Sin = &S2;
        } else{
            Sin = &S3;
        }
        if(out == 1){
            Sout = &S1;
        } else if(out == 2){
            Sout = &S2;
        } else{
            Sout = &S3;
        }

        if(isEmpty(*Sin)){
            printf("Menara kosong\n");
        } else if(isEmpty(*Sout)){
            int temp;
            pop(Sin,&temp);
            push(Sout,temp);
        } else if(TOP(*Sout) < TOP(*Sin)){
            printf("Piringan tidak dapat dipindah\n");
        } else{
            int temp;
            pop(Sin,&temp);
            push(Sout,temp);
        }
    }
    printf("Menara 1: ");
    DisplayStack(S1);
    printf("\nMenara 2: ");
    DisplayStack(S2);
    printf("\nMenara 3: ");
    DisplayStack(S3);
    printf("\n");
}