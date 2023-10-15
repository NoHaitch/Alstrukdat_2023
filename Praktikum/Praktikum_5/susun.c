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
        printf("len: %d ====================\n",len);
        while(!sortString){
            printf("-------------\n");
            int countCorrect = 0;
            for(i = idxStart; i < idxEnd+1; i ++){
                for(j=0; j<wordCount ; j++){
                    printWord(words[j]);
                    printf("-");
                } printf("\n");
                j = 0;
                boolean checked = false;
                while(!checked && j < len-1){
                    printf("idx : %d , %d %c vs %d %c\n",i,(int)words[i].TabWord[j],words[i].TabWord[j],(int)words[i+1].TabWord[j],words[i+1].TabWord[j]);
                    if((int)words[i].TabWord[j] < (int)words[i+1].TabWord[j]){
                        countCorrect ++;
                        checked = true;
                    } else if((int)words[i].TabWord[j] > (int)words[i+1].TabWord[j]){
                        checked = true;
                    }  else if(j == len-1){
                        countCorrect ++; 
                        checked = true;
                    } else{
                        j++;
                    }
                    printf("-> %d\n",countCorrect);
                }
            }
            printf("%d != %d  start: %d  end: %d\n",countCorrect,idxEnd-idxStart,idxStart,idxEnd);
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
                            printWord(words[i+1]);
                            printf("==swapped==");
                            printf("/n");
                            printWord(words[i]);
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
    for(i=0; i<wordCount ; i++){
        printWord(words[i]);
        printf("\n");
    }
    return 0; 
}

//abcde ab cde ac cc bb daca bababa wac aaaa.
//z x y v w q r z m n s x a a b c a c d e f g a h.
//ab bcda.