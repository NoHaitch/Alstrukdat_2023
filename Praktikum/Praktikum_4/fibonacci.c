/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 22 September 2023
    Soal No : 4
*/

#include <stdio.h>
#include "matrix.h"
#include "boolean.h"

Matrix PangkatMatrix (Matrix m, int pangkat){
    Matrix identitas;
    createMatrix(2,2,&identitas);
    ELMT(identitas,0,0) = 1;
    ELMT(identitas,0,1) = 0;
    ELMT(identitas,1,0) = 0;
    ELMT(identitas,1,1) = 1;
    if(pangkat == 0){
        return identitas;
    }    
    else if(pangkat == 1){
        return m;
    } else{
        Matrix m2 = PangkatMatrix(m,pangkat/2);
        Matrix mulMatrix = multiplyMatrixWithMod(m2,m2,2003);
        if(pangkat % 2 == 1){
            mulMatrix = multiplyMatrixWithMod(mulMatrix,m,2003);
        }
        return mulMatrix;
    }
}

int main(){
    int k;
    scanf("%d",&k);
    if(k <= 0){
        printf("0\n");
    }
    else if(k == 1 || k == 2){
        printf("1\n");
    }
    else{
        Matrix rasio;
        createMatrix(2,2,&rasio); 
        ELMT(rasio,0,0) = 1;
        ELMT(rasio,0,1) = 1;
        ELMT(rasio,1,0) = 1;
        ELMT(rasio,1,1) = 0;
        rasio = PangkatMatrix(rasio,k-2);

        Matrix base;
        createMatrix(2,1,&base);
        ELMT(base,0,0) = 1;
        ELMT(base,1,0) = 1;
        
        Matrix result = multiplyMatrixWithMod(rasio,base,2003);
        printf("%d\n",ELMT(result,0,0));
    }
}