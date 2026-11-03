#include <stdio.h>
#include <stdint.h>

void set_bit(uint32_t *reg, uint8_t bit);
void clear_bit(uint32_t *reg, uint8_t bit);
void toggle_bit(uint32_t *reg, uint8_t bit);
uint8_t check_bit(uint32_t reg, uint8_t bit);
void print_binary(uint32_t reg);

int main(void) {
    uint32_t gpio_reg = 0x00008080;

    printf("Initial register state:\n");
    print_binary(gpio_reg);
    printf("\n");

    set_bit(&gpio_reg, 3);
    printf("After setting bit 3:\n");
    print_binary(gpio_reg);
    printf("\n");

    clear_bit(&gpio_reg, 7);
    printf("After clearing bit 7:\n");
    print_binary(gpio_reg);
    printf("\n");

    toggle_bit(&gpio_reg, 12);
    printf("After toggling bit 12:\n");
    print_binary(gpio_reg);
    printf("\n");

    uint8_t state = check_bit(gpio_reg, 15);
    printf("Bit 15 state: %u\n", state);

    return 0;
}

void set_bit(uint32_t *reg, uint8_t bit) {
    *reg |= (1U << bit);
}

void clear_bit(uint32_t *reg, uint8_t bit) {
    *reg &= ~(1U << bit);
}

void toggle_bit(uint32_t *reg, uint8_t bit) {
    *reg ^= (1U << bit);
}

uint8_t check_bit(uint32_t reg, uint8_t bit) {
    return (reg & (1U << bit)) ? 1 : 0;
}

void print_binary(uint32_t reg) {
    printf("BIN: ");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (reg >> i) & 1);
        if (i % 4 == 0 && i != 0) {
            printf(" ");
        }
    }
    printf(" (0x%08X)\n", reg);
}
