#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "charmachine.h"
#include "wordmachine.h"

int main(){
    Stack number;
    CreateEmpty(&number);
    STARTWORD();
    int i, n, a, b;
    for(n=0;n<2;n++){
        int temp = 0;
        for (i = 0; i < currentWord.Length; i++) {
            int convert;
            if(currentWord.TabWord[i] == '0'){
                convert = 0;
            } else if(currentWord.TabWord[i] == '1'){
                convert = 1;
            } else if(currentWord.TabWord[i] == '2'){
                convert = 2;
            } else if(currentWord.TabWord[i] == '3'){
                convert = 3;
            } else if(currentWord.TabWord[i] == '4'){
                convert = 4;
            } else if(currentWord.TabWord[i] == '5'){
                convert = 5;
            } else if(currentWord.TabWord[i] == '6'){
                convert = 6;
            } else if(currentWord.TabWord[i] == '7'){
                convert = 7;
            } else if(currentWord.TabWord[i] == '8'){
                convert = 8;
            } else{
                convert = 9;
            }
            Push(&number, convert);
        }
        int digitrasio = 1;
        while(!IsEmpty(number)){
            int digit;
            Pop(&number,&digit);
            temp += digit * digitrasio;
            digitrasio *= 10;
        }
        if(n == 0){
            a = temp;
        }
        else{
            b = temp;
        }
        ADVWORD();
    }
    printf("%d\n",(a-b));
    
    return 0;
}