/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 29 September 2023
    Soal No : 4
*/

#include <stdio.h>
#include "charmachine.c"
#include "wordmachine.c"

// Prints word from Mesin Kata
int printWord(Word word) {
    int i;
    for (i = 0; i < word.Length; i++) {
        printf("%c", word.TabWord[i]);
    }
}

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
    for(i = 1; i < maxWordLength+1; i++){
        //cek jumlah kata dengan maxWordLength
        printf("maxlength : %d\n",i);
        int countWord = 0;
        int j = currentIdx;
        while(words[j].Length == i){
            countWord ++;
            j++;
        }
        if(countWord != 1){
            for(k = currentIdx; k<j-1; k++){
                int x = 0;
                boolean checked = false;
                while(!checked && x < i){
                    printf("> %c vs %c\n",words[k].TabWord[x],words[k+1].TabWord[x]);
                    if(words[k].TabWord[x] == words[k+1].TabWord[x]){
                        x++;
                    }
                    else if((int) words[k].TabWord[x] > (int) words[k+1].TabWord[x]){
                        Word temp = words[k];
                        words[k] = words[k+1];
                        words[k+1] = temp;
                        checked = true;
                    }
                    else{
                        checked = true;
                    }
                }
            }
        }
        currentIdx == j;
    }
    printf("\n====\n");
    for(i=0; i<wordCount ; i++){
        printWord(words[i]);
        printf("\n");
    }

}