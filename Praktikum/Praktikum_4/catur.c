/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 22 September 2023
    Soal No : 1
*/

#include <stdio.h>
#include "matrix.h"

int main(){
    Matrix m;
    readMatrix(&m,8,8);
    int i,j, countHitam, countPutih;
    countHitam = 0;
    countPutih = 0; 
    for(i=0; i<ROW_EFF(m);i++){
        for(j=0; j<COL_EFF(m);j++){
            if(ELMT(m,i,j) == 1){
                if((i+j) % 2 == 0){
                    countHitam += 1;
                }
                else{
                    countPutih += 1;
                }
            }
        }
    }
    printf("%d %d\n",countHitam,countPutih);
    return 0;
}