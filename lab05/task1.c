#include <stdio.h>

int divide_with_remainder(const int *a, const int *b, int *quotient, int *remainder) {
    if (a == NULL || b == NULL || quotient == NULL || remainder == NULL) {
        return 1;
    }
    if (*b == 0) {
        return 1;
    }

    *quotient = (*a) / (*b);
    *remainder = (*a) % (*b);
    return 0;
}

int main(void) {
    int a = 29;
    int b = 4;
    int q = 0;
    int r = 0;

    int status = divide_with_remainder(&a, &b, &q, &r);
    if (status != 0) {
        printf("Error: invalid pointer or division by zero.\n");
        return 1;
    }

    printf("A = %d, B = %d -> quotient = %d, remainder = %d\n", a, b, q, r);

    int zero = 0;
    if (divide_with_remainder(&a, &zero, &q, &r) != 0) {
        printf("Division by zero handled correctly (status code: 1).\n");
    }

    return 0;
}
