#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    double x_start, x_end, dx;

    printf("Enter X_start, X_end and dX: ");
    if (scanf("%lf %lf %lf", &x_start, &x_end, &dx) != 3) {
        printf("Error: invalid input data.\n");
        return 1;
    }

    if (x_start >= x_end || dx <= 0) {
        printf("Error: invalid range or step.\n");
        return 1;
    }

    printf("\n+------------+------------+\n");
    printf("|     X      |    Y(X)    |\n");
    printf("+------------+------------+\n");

    for (double x = x_start; x <= x_end + dx / 2.0; x += dx) {
        double y;

        if (x < -1.0) {
            y = -1.0;
        } else if (x <= 1.0) {
            y = sqrt(1.0 - x * x);
        } else {
            y = x - 1.0;
        }

        printf("| %10.2lf | %10.4lf |\n", x, y);
    }

    printf("+------------+------------+\n");
    return 0;
}
