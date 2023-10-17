/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 3 Oktober 2023
    Soal No : 1
*/
#include <stdio.h>
#include <stdlib.h>
#include "stack.c"

int main(){
    Stack s;
    int result = 0;
    CreateEmpty(&s);
    int i,n;
    scanf("%d",&n);
    // Masukkan dasar dari Stack
    Push(&s,n);
    if(InfoTop(s) == 0 || InfoTop(s) == 1){
        // jika dasar dari stack adalah 0 atau 1 maka tidak perlu pengulangan karena fibonaci 0 dan 1 adalah basis
        int temp;
        Pop(&s,&temp);
        printf("fibonacci(%d)\n",InfoTop(s));
        result = 0;
    }
    while(!IsEmpty(s)){
        // akan berhenti fibonaci dipecah-pecah menjadi lebih kecil hingga akhirnya Stack kosong atau fibonaci diselesaikan
        int temp;
        if(InfoTop(s) == 0){
            // fibonaci(0) = 0 adalah basis sehingga result ditambah 0
            Pop(&s,&temp); 
            printf("fibonacci(%d)\n",temp);
        }
        if(InfoTop(s) == 1){
            // fibonaci(1) = 1 adalah basis sehingga result ditambah 1
            result += 1;
            Pop(&s,&temp); 
            printf("fibonacci(%d)\n",temp);
        } else{ 
            // fibonachi(n) = fibonachi(n-1) + fibonachi(n-2), n > 1
            // maka hapus fibonaci(n) namun tambahkan fibonachi(n-2) kemudian tambahkan fibonachi (n-1)
            Pop(&s,&temp);
            printf("fibonacci(%d)\n",temp);
            Push(&s,temp-2);
            Push(&s,temp-1);
        }
    }
    printf("%d\n",result);
    
    return 0;
}
