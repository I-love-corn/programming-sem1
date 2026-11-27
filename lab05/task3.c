#include <stddef.h>
#include <stdio.h>

void reverse_buffer(int *arr, size_t n) {
    if (arr == NULL || n <= 1U) {
        return;
    }

    const int *start_ptr = arr;
    const int *end_ptr = arr + (n - 1U);

    int *left_ptr = arr;
    int *right_ptr = arr + (n - 1U);

    while (left_ptr < right_ptr) {
        if (left_ptr < start_ptr || right_ptr > end_ptr) {
            break;
        }

        int tmp = *left_ptr;
        *left_ptr = *right_ptr;
        *right_ptr = tmp;

        left_ptr++;
        right_ptr--;
    }
}

static void print_buffer(const int *arr, size_t n) {
    if (arr == NULL || n == 0U) {
        printf("(empty buffer)\n");
        return;
    }

    const int *cur = arr;
    const int *last = arr + (n - 1U);
    while (cur <= last) {
        printf("%d", *cur);
        if (cur < last) {
            printf(" ");
        }
        cur++;
    }
    printf("\n");
}

int main(void) {
    int data[] = {10, 20, 30, 40, 50, 60};
    size_t len = sizeof(data) / sizeof(*data);

    printf("Original array: ");
    print_buffer(data, len);

    reverse_buffer(data, len);

    printf("Reversed array: ");
    print_buffer(data, len);

    return 0;
}
