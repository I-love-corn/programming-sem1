#include <stdio.h>

#define BUFFER_SIZE 256

int main(void) {
    char str[BUFFER_SIZE];

    printf("Enter a line of text: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }

    int len = 0;
    while (str[len] != '\0') {
        if (str[len] == '\n' || str[len] == '\r') {
            str[len] = '\0';
            break;
        }
        len++;
    }

    int left = 0;
    int right = len - 1;
    int is_palindrome = 1;

    while (left < right) {
        while (left < right && (str[left] == ' ' || str[left] == '\t')) {
            left++;
        }
        while (left < right && (str[right] == ' ' || str[right] == '\t')) {
            right--;
        }

        char c1 = str[left];
        char c2 = str[right];

        if (c1 >= 'A' && c1 <= 'Z') c1 += 32;
        if (c2 >= 'A' && c2 <= 'Z') c2 += 32;

        if (c1 != c2) {
            is_palindrome = 0;
            break;
        }

        left++;
        right--;
    }

    if (is_palindrome) {
        printf("The string IS a palindrome!\n");
    } else {
        printf("The string IS NOT a palindrome.\n");
    }

    return 0;
}