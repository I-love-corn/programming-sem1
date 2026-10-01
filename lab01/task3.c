#include <stdio.h>

int main(void) {
    double m, v, h;
    const double g = 9.81;

    printf("Enter mass m (kg): ");
    if (scanf("%lf", &m) != 1 || m < 0) {
        printf("Invalid mass.\n");
        return 1;
    }

    printf("Enter velocity v (m/s): ");
    if (scanf("%lf", &v) != 1 || v < 0) {
        printf("Invalid velocity.\n");
        return 1;
    }

    printf("Enter height h (m): ");
    if (scanf("%lf", &h) != 1 || h < 0) {
        printf("Invalid height.\n");
        return 1;
    }

    double Ek = m * v * v / 2.0;
    double Ep = m * g * h;

    printf("Kinetic energy: %.2f J\n", Ek);
    printf("Potential energy: %.2f J\n", Ep);

    return 0;
}