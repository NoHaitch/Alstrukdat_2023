/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 3 Oktober 2023
    Soal No : 4
*/

#include <stdio.h>
#include "stack.h"
#include "charmachine.h"
#include "wordmachine.h"
// pastikan file stack.h sementara dimodifikasi dengan line di bawah
// ubah tipe infotype menjadi char
#define typedef char infotype;

void readWord(Word *input) {
    int i;
    START();
    IgnoreBlanks();

    (*input).Length = 0;
    i = 0;

    while ((currentChar != MARK) && (i < NMax)) {
        (*input).TabWord[i] = currentChar;
        ADV();
        i++;
    }

    (*input).Length = i;

    (*input).TabWord[i] = '\0';
}

int main(){
    Word input;
    readWord(&input);
    Stack S;
    CreateEmpty(&S);
    int maxdepth = 0;
    int depth = 0;
    int i = 0;
    boolean valid = true;
    while(valid && i < input.Length){
        if(input.TabWord[i] == '('){
            depth++;
            Push(&S,'(');
        } else{
            if(InfoTop(S) == '('){
                depth--;
                char temp;
                Pop(&S,&temp);
            } else{
                valid = false;
            }
        }
        if(maxdepth < depth){
            maxdepth = depth;
        }
        i++;
    }
    if(valid){
        if(!IsEmpty(S)){
            printf("-1");
        } else{
            printf("%d",maxdepth);
        }
    }
    else{
        printf("-1");
    }
    printf("\n");
}