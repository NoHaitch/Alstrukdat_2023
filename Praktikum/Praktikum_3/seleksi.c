#include <stdio.h>
#include "listdin.h"

int main(){
    ListDin A;
    int C;
    scanf("%d",&C);
    CreateListDin(&A,C);
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int tipe;
        scanf("%d",&tipe);
        if(tipe==1){
            int x,j;
            scanf("%d",&x);
            insertLast(&A,x);
            for(j=0;j<listLength(A);j++){
                if(ELMT(A,j) < x){
                    // Delete elemen dengan menshif ke kiri
                    int k;
                    for(k=j;k<listLength(A);k++){
                        ELMT(A,k) = ELMT(A,k+1);
                    }
                    // hapus sisa penggeseran
                    int val;
                    deleteLast(&A,&val);
                    j--;
                }
            }
        }else{
            printf("%d\n",listLength(A));
            printList(A);
            printf("\n");
        }
    }

    return 0;
}