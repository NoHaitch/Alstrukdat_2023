/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 22 September 2023
    Soal No : 3
*/

#include <stdio.h>
#include "boolean.h"

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    int matrix[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int maxSum = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int p = i; p < N; p++) {
                for (int q = j; q < M; q++) {
                    int currentSum = 0;

                    // Hitung total elemen pada segi empat
                    for (int x = i; x <= p; x++) {
                        for (int y = j; y <= q; y++) {
                            currentSum += matrix[x][y];
                        }
                    }

                    // Periksa apakah luas segi empat sama dengan K dan lebih besar dari maxSum
                    if ((p - i + 1) * (q - j + 1) == K && currentSum > maxSum) {
                        maxSum = currentSum;
                    }
                }
            }
        }
    }

    printf("%d\n", maxSum);

    return 0;
}



