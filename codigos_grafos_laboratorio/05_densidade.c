#include <stdio.h>

int main(void) {
    int n = 7;
    int m = 12;

    double densidade = (2.0 * m) / (n * (n - 1));

    printf("Densidade = %.4f\n", densidade);
    return 0;
}
