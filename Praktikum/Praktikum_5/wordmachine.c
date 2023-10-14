/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 29 September 2023
    Soal No : Pra - 1
*/

#include <stdio.h>
#include "boolean.h"
#include "wordmachine.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
   while (currentChar == BLANK) {
      ADV();
   }
}
void STARTWORD()
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
   START();
   IgnoreBlanks();
   if (currentChar == MARK){
      EndWord = true;
   }
   else{
      EndWord = false;
      CopyWord();
   }
}

void ADVWORD()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
{  
   IgnoreBlanks();
   if (currentChar == MARK){
      EndWord = true;
   }
   else{
      CopyWord();
      IgnoreBlanks();
   }
}

void CopyWord()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
   int i = 0;
   while (currentChar != MARK && currentChar != BLANK){
      currentWord.TabWord[i] = currentChar;
      ADV();
      i++;
   }

   if (i > NMax){
      currentWord.Length = NMax;
   }

   else{
      currentWord.Length = i;
   }
}

/*
int main(){
    STARTWORD();
    while(!EndWord){
        int i;
        for(i = 0; i<currentWord.Length; i++){
            printf("%c",currentWord.TabWord[i]);
        }
        printf("\n");
        ADVWORD();
    }
    return 0;
}


$ cc -c mesinkar.c
$ cc -c mesinkata1.c
$ cc -c mainkata.c
$ cc -o mainkata mesinkar.o mesinkata1.o mainkata.o

$ cc -o mainkata mesinkar.c mesinkata1.c mainkata.c
*/