/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 29 September 2023
    Soal No : 4
*/

#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"

int main(){
    Word words[100];
    int wordCount = 0;
    int maxWordLength = 0;
    STARTWORD();
    while(!EndWord){
        words[wordCount] = currentWord;
        if(currentWord.Length > maxWordLength){
            maxWordLength = currentWord.Length;
        }
        wordCount++;
        ADVWORD();
    }
    int i,j,k,l;
    boolean sorted = false;
    while (!sorted){
        /* Periksa apakah semua kata sudah terurut atau belum */
        int countCorrect = 0;
        for(i = 0; i < wordCount-1; i++){
            boolean checked = false;
            int charIdx = 0;
            while(!checked){
                if((int)words[i].TabWord[charIdx] < (int)words[i+1].TabWord[charIdx]){
                    countCorrect ++;
                    checked = true;
                } else if((int)words[i].TabWord[charIdx] > (int)words[i+1].TabWord[charIdx]){
                    checked = true;
                } else{
                    charIdx++;
                    if((charIdx == words[i].Length && words[i].Length == words[i+1].Length) || charIdx == words[i].Length){
                        checked = true;
                        countCorrect ++;
                    } else if(charIdx == words[i+1].Length){
                        checked = true;
                    } 
                }        
            }
        }
        if(countCorrect != wordCount-1){
            for(i = 0; i < wordCount-1; i++){
                boolean checked = false;
                int charIdx = 0;
                while(!checked && charIdx < words[i].Length){
                    if((int)words[i].TabWord[charIdx] < (int)words[i+1].TabWord[charIdx]){
                        checked = true;
                    } else if((int)words[i].TabWord[charIdx] > (int)words[i+1].TabWord[charIdx]){
                        // swapped
                        checked = true;
                        Word temp = words[i];
                        words[i] = words[i+1];
                        words[i+1] = temp;
                    } else{
                        charIdx++;
                        if((charIdx == words[i].Length && words[i].Length == words[i+1].Length) || charIdx == words[i].Length){
                            checked = true;
                        } else if(charIdx == words[i+1].Length){
                            checked = true;
                            Word temp = words[i];
                            words[i] = words[i+1];
                            words[i+1] = temp;
                        } 
                    }        
                }
            }
        }else{
            sorted = true;
        }
    }

    for(i=0; i<wordCount; i++){
        for (j = 0; j < words[i].Length; j++) {
            printf("%c", words[i].TabWord[j]);
        }
        printf("\n");
    }
    return 0; 
}

//abcde ab cde ac cc bb daca bababa wac aaaa.
//z x y v w q r z m n s x a a b c a c d e f g a h.
//ab bcda.