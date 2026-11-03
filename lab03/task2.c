#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4

int main(void) {
    srand((unsigned int)time(NULL));
    int matrix[N][N];

    printf("Original matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 50 + 1;
            printf("%6d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int sum_below_main = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i > j) {
                sum_below_main += matrix[i][j];
            }
        }
    }
    printf("Sum below main diagonal: %d\n\n", sum_below_main);

    for (int i = 0; i < N; i++) {
        matrix[i][N - 1 - i] = 0;
    }

    printf("Matrix after zeroing secondary diagonal:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%6d", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}