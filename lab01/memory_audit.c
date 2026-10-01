#include <stdio.h>

int main(void) {
    printf("Size of char: %zu byte(s)\n", sizeof(char));
    printf("Size of short: %zu byte(s)\n", sizeof(short));
    printf("Size of int: %zu byte(s)\n", sizeof(int));
    printf("Size of long: %zu byte(s)\n", sizeof(long));
    printf("Size of long long: %zu byte(s)\n", sizeof(long long));
    printf("Size of float: %zu byte(s)\n", sizeof(float));
    printf("Size of double: %zu byte(s)\n", sizeof(double));
    printf("Size of void*: %zu byte(s)\n", sizeof(void*));

    unsigned char byte_test = 255;

    printf("\nBefore overflow:\n");
    printf("Decimal: %u\n", byte_test);
    printf("Hexadecimal: 0x%02X\n", byte_test);

    byte_test = byte_test + 1;

    printf("\nAfter adding 1:\n");
    printf("Decimal: %u\n", byte_test);
    printf("Hexadecimal: 0x%02X\n", byte_test);

    return 0;
}