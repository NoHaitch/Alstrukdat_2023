/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 6 September 2023
    Soal No : Pra - 1
*/
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
    Stack s;
    int result = 0;
    CreateEmpty(&s);
    int i,n;
    scanf("%d",&n);
    Push(&s,n);
    if(InfoTop(s) == 0){
        int temp;
        Pop(&s,&temp);
        printf("fibonacci(0)\n");
        result = 0;
    }
    else if(InfoTop(s) == 1){
        int temp;
        Pop(&s,&temp);
        printf("fibonacci(1)\n");
        result = 1;
    }
    while(!IsEmpty(s)){
        int temp;
        if(InfoTop(s) == 0){
            Pop(&s,&temp); 
            printf("fibonacci(%d)\n",temp);
        }
        if(InfoTop(s) == 1){
            result += 1;
            Pop(&s,&temp); 
            printf("fibonacci(%d)\n",temp);
        } else if(InfoTop(s) == 2){
            Pop(&s,&temp); 
            printf("fibonacci(%d)\n",temp);
            printf("fibonacci(1)\n");
            printf("fibonacci(0)\n");
            result += 1;
        } 
        else {
            Pop(&s,&temp);
            printf("fibonacci(%d)\n",temp);
            Push(&s,temp-2);
            Push(&s,temp-1);
        }
    }
    printf("%d\n",result);
    
    return 0;
}
