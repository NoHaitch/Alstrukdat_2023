#include <stdio.h>
#include "point.h"
#include "garis.h"

int main(){
    int b;
    scanf("%d",&b);

    GARIS L;
    BacaGARIS(&L);

    int n, i, count;
    count = 0;
    scanf("%d",&n);
    for(i = 0; i<n; i++){
        POINT P;
        BacaPOINT(&P);
        if(JarakGARIS(L, P) <= b){
            count += 1;
        }
    }
    printf("%d\n", count);
}  