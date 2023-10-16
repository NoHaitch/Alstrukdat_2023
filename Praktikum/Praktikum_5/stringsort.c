/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 29 September 2023
    Soal No : 4
    
    File ini bukan unutk praktikum namun kesalahan membaca soal sehingga cara sort yang salah
    file ini melakukan sort string yang dilakukan dengan ketentuan:
    sort berdasarkan panjang kata
    sort berdasarkan karakter dari hasil sort berdasarkan panjang kata
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

    // Sort berdasarkan panjang kata
    boolean sortPanjang = false;
    while(!sortPanjang){
        int countcorrect = 0;
        for(i = 0; i < wordCount-1; i++){
            if(words[i].Length <= words[i+1].Length){
                countcorrect ++;
            }
        }    
        if(countcorrect == wordCount-1){
            sortPanjang = true;
        }
        else{
            for(i = 0; i < wordCount-1; i++){
                if(words[i].Length > words[i+1].Length){
                    Word temp = words[i];
                    words[i] = words[i+1];
                    words[i+1] = temp;
                }
            }  
        }
    }
    // Sort berdasarkan karakter
    int currentIdx = 0;
    for(int len = words[0].Length; len < maxWordLength+1; len++){
        int idxStart = currentIdx;
        while(words[currentIdx].Length == len && currentIdx < wordCount){
            currentIdx ++;
        }
        int idxEnd = currentIdx-1;
        if(idxEnd < idxStart){
            idxEnd = idxStart;
        }
        boolean sortString = false;
        while(!sortString){
            int countCorrect = 0;
            for(i = idxStart; i < idxEnd; i ++){
                j = 0;
                boolean checked = false;
                while(!checked && j < len){
                    if((int)words[i].TabWord[j] < (int)words[i+1].TabWord[j]){
                        countCorrect ++;
                        checked = true;
                    } else if((int)words[i].TabWord[j] > (int)words[i+1].TabWord[j]){
                        checked = true;
                    }  else if(j == len-1 && (int)words[i].TabWord[j] == (int)words[i+1].TabWord[j]){
                        countCorrect ++; 
                        checked = true;
                    } else if(j == len-1){
                        checked = true;
                    } 
                    else{
                        j++;
                    }
                }
            }
            if(countCorrect != idxEnd-idxStart && idxStart != idxEnd){
                for(i = idxStart; i < idxEnd; i ++){
                    j = 0;
                    boolean checked = false;
                    while(!checked && j < len){
                        if((int)words[i].TabWord[j] > (int)words[i+1].TabWord[j]){
                            Word temp = words[i];
                            words[i] = words[i+1];
                            words[i+1] = temp;
                            checked = true;
                        } else if(j == len-1 || (int)words[i].TabWord[j] < (int)words[i+1].TabWord[j]){
                            checked = true;
                        } else if((int)words[i].TabWord[j] == (int)words[i+1].TabWord[j]){
                            j++;
                        }
                    }
                }
            } else{
                sortString = true;
            }
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