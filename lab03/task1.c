#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

int main(void) {
    srand((unsigned int)time(NULL));
    int arr[SIZE];

    printf("Original array:\n");
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 21 - 10;
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    int max_val = arr[0];
    for (int i = 1; i < SIZE; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    int first_zero = -1;
    int last_zero = -1;

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] == 0) {
            if (first_zero == -1) {
                first_zero = i;
            }
            last_zero = i;
        }
    }

    printf("Maximum element: %d\n", max_val);

    if (first_zero != -1 && last_zero != -1 && first_zero < last_zero) {
        long long product = 1;
        for (int i = first_zero + 1; i < last_zero; i++) {
            product *= arr[i];
        }
        printf("Product between first (idx %d) and last (idx %d) zeros: %lld\n", 
               first_zero, last_zero, product);
    } else {
        printf("Fewer than two zeros found, product cannot be calculated.\n");
    }

    return 0;
}