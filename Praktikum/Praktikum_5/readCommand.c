/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 29 September 2023
    Soal No : 2
*/

#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"

// Prints word from Mesin Kata
void printWord(Word word) {
   int i;
   for (i = 0; i < word.Length; i++) {
      printf("%c", word.TabWord[i]);
   }
}

int main(){
    // ASUMSI TIDAK ADA SPASI LEBIH DARI 1 ANTARA KATA
    START();
    IgnoreBlanks();
    int count = 0;
    while(currentChar != MARK){
        printf("%c",currentChar);
        count += 1;
        ADV();
    }
    printf("\n%d\n", count);
}