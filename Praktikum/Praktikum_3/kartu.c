#include <stdio.h>
#include "listdin.h"

int main(){
    ListDin A1,A2,A3;
    int n1,n2,n3,i;
    scanf("%d",&n1);
    CreateListDin(&A1,n1);
    for (i = IDX_MIN; i < n1; i++){
        scanf("%d", &ELMT(A1, i));
    }
    NEFF(A1) = n1;
    scanf("%d",&n2);
    CreateListDin(&A2,n2);
    for (i = IDX_MIN; i < n2; i++){
        scanf("%d", &ELMT(A2, i));
    }
    NEFF(A2) = n2;
    n3 = n1+n2;
    CreateListDin(&A3,n3);
    while(!isEmpty(A1) && !isEmpty(A2)){
        if(ELMT(A1,0) >= ELMT(A2,0)){
            insertLast(&A3,ELMT(A1,0));
            // Delete elemen dengan menshif ke kiri
            int j;
            for(j=0;j<listLength(A1)-1;j++){
                ELMT(A1,j) = ELMT(A1,j+1);
            }
            // hapus sisa penggeseran
            int val;
            deleteLast(&A1,&val);
        }
        else{
            insertLast(&A3,ELMT(A2,0));
            // Delete elemen dengan menshif ke kiri
            int j;
            for(j=0;j<listLength(A2)-1;j++){
                ELMT(A2,j) = ELMT(A2,j+1);
            }
            // hapus sisa penggeseran
            int val;
            deleteLast(&A2,&val);
        }
    }
    if(!isEmpty(A1)){
        for(i =0; i<listLength(A1);i++){
            insertLast(&A3,ELMT(A1,i));
        }
    }
    else if(!isEmpty(A2)){
        for(i =0; i<listLength(A2);i++){
            insertLast(&A3,ELMT(A2,i));
        }
    }

    printList(A3);
    printf("\n");
    return 0;
}