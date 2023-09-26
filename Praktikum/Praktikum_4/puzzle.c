/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 22 September 2023
    Soal No : 3
*/

#include <stdio.h>
#include "matrix.h"
#include "boolean.h"

int main(){
    int row,col, k;
    scanf("%d %d",&row,&col);
    Matrix m;
    readMatrix(&m,row,col);
    scanf("%d",&k);
    int  n;
    boolean solvable = true;
    for(n = 0; n<k;n++){
        int newRow, newCol;
        scanf("%d %d",&newRow, &newCol);
        Matrix mp;
        readMatrix(&mp,newRow,newCol);
        boolean found = false;
        int i = 0;
        int j = 0;
        while( i<ROW_EFF(m) && found == false){
            while(j<COL_EFF(m) && found == false){
                // find element 0 0 of mp
                if(ELMT(m,i,j) == ELMT(mp,0,0)){
                    // cek apakah cukup dari posisi elemen terbentuk matriks mp
                    if(ROW_EFF(mp) <= ROW_EFF(m)-j+1 && COL_EFF(mp) <= COL_EFF(m)-i+1){
                        //check semua elemen mp
                        int x = 0;
                        int y = 0;
                        boolean check = true;
                        while( x<ROW_EFF(mp) && check == true){
                            while(y<COL_EFF(mp) && check == true){
                                if(ELMT(m,i+x,j+y) != ELMT(mp,x,y)){
                                    check = false;
                                }
                                y++;
                            }
                            x++;
                        }
                        if(check == false){
                            found = true;
                        }
                    }
                }
                j++;
            }
            i++;
        }
        if(found){
            solvable = false;
        }
    }
    if(solvable){
        printf("Puzzle dapat diselesaikan.\n");
    }else{
        printf("Puzzle tidak dapat diselesaikan.\n");
    }
}