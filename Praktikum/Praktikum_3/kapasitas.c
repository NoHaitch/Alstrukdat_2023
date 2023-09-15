#include <stdio.h>
#include "listdin.h"
#include "math.h"

int main(){
    ListDin A;
    CreateListDin(&A,0);
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int tipe;
        scanf("%d",&tipe);
        if(tipe==1){
            int x;
            scanf("%d",&x);
            if(CAPACITY(A) == 0){
                expandList(&A,1);
                CAPACITY(A) = 1;
            }
            else if(listLength(A) == CAPACITY(A)){
                expandList(&A,(CAPACITY(A)));
            }
            insertLast(&A,x);
        }else if(tipe==2){
            ElType val;
            deleteLast(&A,&val);
            if(NEFF(A) == round(CAPACITY(A)/2)){
                CAPACITY(A) = round(CAPACITY(A)/2);
            }
        }else{
            printf("%d ",CAPACITY(A));
            printList(A);
            printf("\n");
        }
    }
    return 0;
}