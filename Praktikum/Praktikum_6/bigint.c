/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 3 Oktober 2023
    Soal No : 2
*/

#include <stdio.h>
#include "stack.h"
#include "charmachine.h"
#include "wordmachine.h"

int main(){
    Word listWords[100];
    int countWord = 0;
    START();
    while(currentChar != MARK){
        ADVWORD();
        listWords[countWord] = currentWord;
        countWord++;
    }
    // angka 1 >= angka 2
    // result pasti bukan negatif || result >= 0

    Stack S; // Stack berisi hasil pengurangan 2 digit pada kelipatan 10 yang sama
    CreateEmpty(&S);
    int i,j;
    int diff = listWords[0].Length - listWords[1].Length; // sudah pasti diff >= 0
    for(i=0; i<listWords[0].Length;i++){
        if(i < diff){
            int convert = listWords[0].TabWord[i] - '0';
            Push(&S,convert);
        } else{
            int convert = (listWords[0].TabWord[i] - '0') - (listWords[1].TabWord[i-diff] - '0');
            Push(&S, convert);
        }
    }
    // S berisi hasil pengurangan antar digit
    // Membersihkan S yang bernilai negatif dan sekaligus referse stack
    Stack Srefersed;
    CreateEmpty(&Srefersed);
    boolean carry = false;
    while(!IsEmpty(S)){
        int temp;
        Pop(&S,&temp);
        if(carry){
            temp--;
            carry = false;
        }
        if(temp < 0){
            temp += 10;
            carry = true;
        }
        Push(&Srefersed,temp);
    }

    // Membersihkan 0 yang tidak digunakan
    i = 0;
    while(InfoTop(Srefersed) == 0 && i < listWords[0].Length-1){
        int temp;
        Pop(&Srefersed, &temp);
        i++;
    }

    // menampilkan isi stack
    while(!IsEmpty(Srefersed)){
        int temp;
        Pop(&Srefersed,&temp);
        printf("%d",temp);
    }
    printf("\n");
}


/*
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
*/