#include <stdio.h>

unsigned long long calculate_factorial(int n);

int main(void) {
    int test_numbers[] = {5, 3, 7, 0, 4};
    int count = sizeof(test_numbers) / sizeof(test_numbers[0]);

    for (int i = 0; i < count; i++) {
        int num = test_numbers[i];
        unsigned long long result = calculate_factorial(num);
        printf("%d! = %llu\n", num, result);
    }

    return 0;
}

unsigned long long calculate_factorial(int n) {
    static unsigned long long total_multiplications = 0;

    if (n < 0) {
        return 0;
    }

    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
        total_multiplications++;
    }

    printf("Total multiplications count: %llu\n", total_multiplications);

    return fact;
}
