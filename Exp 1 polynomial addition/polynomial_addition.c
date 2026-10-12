#include <stdio.h>

struct poly {
    int coeff;
    int expo;
};

int main() {
    struct poly x1[20], x2[20], x3[40];
    int m, n;
    int i = 0, j = 0, k = 0;

    printf("Enter number of terms in first polynomial: ");
    if (scanf("%d", &m) != 1) return 1;

    printf("Enter coefficient and exponent (in descending order of exponent):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d", &x1[i].coeff, &x1[i].expo);
    }

    printf("Enter number of terms in second polynomial: ");
    if (scanf("%d", &n) != 1) return 1;

    printf("Enter coefficient and exponent (in descending order of exponent):\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &x2[i].coeff, &x2[i].expo);
    }

    i = 0;
    j = 0;
    k = 0;

    while (i < m && j < n) {
        if (x1[i].expo == x2[j].expo) {
            x3[k].coeff = x1[i].coeff + x2[j].coeff;
            x3[k].expo = x1[i].expo;
            i++;
            j++;
            k++;
        }
        else if (x1[i].expo > x2[j].expo) {
            x3[k].coeff = x1[i].coeff;
            x3[k].expo = x1[i].expo;
            i++;
            k++;
        }
        else {
            x3[k].coeff = x2[j].coeff;
            x3[k].expo = x2[j].expo;
            j++;
            k++;
        }
    }

    /* Copy remaining terms of first polynomial */
    while (i < m) {
        x3[k].coeff = x1[i].coeff;
        x3[k].expo = x1[i].expo;
        i++;
        k++;
    }

    /* Copy remaining terms of second polynomial */
    while (j < n) {
        x3[k].coeff = x2[j].coeff;
        x3[k].expo = x2[j].expo;
        j++;
        k++;
    }

    printf("\nResultant Polynomial:\n");
    for (i = 0; i < k; i++) {
        // Skip printing terms with a coefficient of 0
        if (x3[i].coeff == 0) continue;

        if (i != 0 && x3[i].coeff > 0)
            printf("+");

        if (x3[i].expo == 0)
            printf("%d", x3[i].coeff);
        else if (x3[i].expo == 1)
            printf("%dx", x3[i].coeff);
        else
            printf("%dx^%d", x3[i].coeff, x3[i].expo);
    }
    printf("\n");

    return 0;
}
