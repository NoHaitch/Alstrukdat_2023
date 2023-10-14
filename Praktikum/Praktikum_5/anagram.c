/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 29 September 2023
    Soal No : 3
*/

#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"

int main(){
    // Asumsi banyak kata maksimal adalah 100
    Word words[100];
    int wordCount = 0;
    int anagram = 0;
    STARTWORD();
    while(!EndWord){
        words[wordCount] = currentWord;
        wordCount++;
        ADVWORD();
    }
    int i, j, k;
    for(i = 0; i < wordCount; i++){
        for(j = i+1; j < wordCount; j++){
            if(words[i].Length == words[j].Length){
                boolean notAnagram = false;
                int cIdx = 0;
                char character[NMax];
                int charCount = 0;
                while(!notAnagram && cIdx < words[i].Length){
                    k = 0;
                    boolean found = false;
                    while(!found && k< charCount){
                        if(character[k] == words[i].TabWord[cIdx]){
                            found = true;
                        }
                        k++;
                    }
                    if(!found){
                        character[charCount] = words[i].TabWord[cIdx];
                        charCount ++ ;
                        int countcharA = 0;
                        int countcharB = 0;
                        for(k = 0; k < words[i].Length; k++){
                            if(words[i].TabWord[cIdx] == words[i].TabWord[k]){
                                countcharA++;
                            }
                        }
                        for(k = 0; k < words[i].Length; k++){
                            if(words[i].TabWord[cIdx] == words[j].TabWord[k]){
                                countcharB++;
                            }
                        }
                        if(countcharA != countcharB){
                            notAnagram = true;
                        }
                    }
                    cIdx ++;
                }
                if(!notAnagram){
                    anagram ++;
                }
            }
        } 
    }
    printf("%d\n",anagram);
}

