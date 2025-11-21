#include <stdio.h>

void main() {
    int n = 4; 
    int i, j, k;

    for (i = 1; i <= n; i++) {
        for (j = i; j < n; j++) {
            printf(" ");
        }

        for (k = i; k >= 1; k--) {
            printf("%d", k);
        }

        for (k = 2; k <= i; k++) {
            printf("%d", k);
        }

        printf("\n");
    }

    for (i = n - 1; i >= 1; i--) {
        for (j = n; j > i; j--) {
            printf(" ");
        }

        for (k = i; k >= 1; k--) {
            printf("%d", k);
        }

        for (k = 2; k <= i; k++) {
            printf("%d", k);
        }

        printf("\n");
    }
}
