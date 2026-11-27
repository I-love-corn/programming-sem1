#include <stdint.h>
#include <stdio.h>

void configure_register(uint32_t *reg) {
    if (reg == NULL) {
        return;
    }

    *reg |= (1U << 0);     /* Set bit 0 to 1 */
    *reg &= ~(1U << 8);    /* Clear bit 8 to 0 */
    *reg ^= (1U << 16);    /* Toggle bit 16 */
}

int check_status_flag(const uint32_t *reg, uint8_t bit_pos) {
    if (reg == NULL || bit_pos >= 32U) {
        return 0;
    }

    return ((*reg & (1U << bit_pos)) != 0U) ? 1 : 0;
}

static void print_binary32(uint32_t value) {
    for (int bit = 31; bit >= 0; --bit) {
        printf("%u", (value >> bit) & 1U);
        if (bit % 4 == 0 && bit != 0) {
            printf(" ");
        }
    }
}

int main(void) {
    /* Initial state: bit 8 = 1 (0x00000100), bit 12 = 1 (0x00001000) */
    uint32_t ctrl_reg = 0x00001100U;

    printf("Before: 0x%08X | ", ctrl_reg);
    print_binary32(ctrl_reg);
    printf("\nBit 12 status (before): %d\n", check_status_flag(&ctrl_reg, 12));

    configure_register(&ctrl_reg);

    printf("After:  0x%08X | ", ctrl_reg);
    print_binary32(ctrl_reg);
    printf("\nBit 12 status (after):  %d\n", check_status_flag(&ctrl_reg, 12));

    return 0;
}
