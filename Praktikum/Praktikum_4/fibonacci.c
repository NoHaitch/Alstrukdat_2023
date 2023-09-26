/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 22 September 2023
    Soal No : 4
*/

#include <stdio.h>
#include "matrix.c"
#include "boolean.h"

Matrix PangkatMatrix (Matrix m, int pangkat){
    Matrix identitas;
    createMatrix(2,2,&identitas);
    ELMT(identitas,0,0) = 1;
    ELMT(identitas,0,1) = 1;
    ELMT(identitas,1,0) = 1;
    ELMT(identitas,1,1) = 0;
    if(pangkat == 0){
        return identitas;
    }    
    else if(pangkat == 1){
        return m;
    } else{
        Matrix m2 = PangkatMatrix(m,pangkat/2);
        Matrix mulMatrix = multiplyMatrix(m2,m2);
        if(pangkat % 2 == 1){
            mulMatrix = multiplyMatrix(mulMatrix,m);
        }
        return mulMatrix;
    }
}

int main(){
    int k;
    scanf("%d",&k);
    if(k == 1 || k == 2){
        printf("1\n");
    }else{
        Matrix base;
        createMatrix(2,1,&base);
        ELMT(base,0,0) = 1;
        ELMT(base,1,0) = 1;
        Matrix new;
        createMatrix(2,1,&new); 
        new = PangkatMatrix(base,k-2);
        multiplyMatrixWithMod(new,base,2003);
        printf("%d\n",ELMT(new,0,0));
    }
}