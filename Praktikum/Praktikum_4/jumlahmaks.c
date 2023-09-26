/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 22 September 2023
    Soal No : 3
*/

#include <stdio.h>
#include "matrix.h"
#include "boolean.h"

int main(){
    int x, y, k;
    scanf("%d %d",&x, &y);
    scanf("%d",&k);
    if(x == 0 || y== 0){
        printf(0);
    }else{
        Matrix m;
        readMatrix(&m,x,y);
        int i,j,p,q,w,z;
        int max = 0;
        int row, col;
        for(row=1;row<k+1;row++){
            for(col=1;col<k+1;col++){
                if(row*col == k){
                    for(p=0; p<ROW_EFF(m);p++){
                        for(q=0; q<COL_EFF(m);q++){
                            if(row <= ROW_EFF(m)-p+1 && col <= COL_EFF(m)-q+1){
                                int sum = 0;
                                for(i = p; i<row+p; i++){
                                    for(j=q; j<col+q; j++){
                                        sum += ELMT(m,i,j);
                                    }   
                                }
                                if(sum > max){
                                    max = sum;
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n",max);
    }
}