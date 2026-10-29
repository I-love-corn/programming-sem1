#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    double x, eps;

    printf("Enter X and eps: ");
    if (scanf("%lf %lf", &x, &eps) != 2) {
        printf("Error: invalid input.\n");
        return 1;
    }

    if (eps <= 0) {
        printf("Error: eps must be > 0.\n");
        return 1;
    }

    double a_n = x;
    double sum = a_n;
    int n = 0;
    int max_iterations = 100000;
    int reached_limit = 0;

    while (fabs(a_n) >= eps) {
        n++;
        if (n > max_iterations) {
            reached_limit = 1;
            break;
        }

        a_n = a_n * (-x * x) / ((2 * n) * (2 * n + 1));
        sum += a_n;
    }

    if (reached_limit) {
        printf("Warning: iteration limit reached.\n");
    }

    double exact = sin(x);
    double abs_err = fabs(sum - exact);

    printf("\nCalculated sum: %.8lf\n", sum);
    printf("Exact value:    %.8lf\n", exact);
    printf("Absolute error: %.8e\n", abs_err);
    printf("Iterations:     %d\n", n + 1);

    return 0;
}
