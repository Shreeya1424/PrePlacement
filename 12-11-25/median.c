#include <stdio.h>

void main() {
    int a[] = {30, 25, 40};
    int b[] = {45, 50, 55, 60, 65};
    int a1 = 3;
    int b1 = 5;
    int c1 = a1 + b1;
    int c[c1];

    for (int i = 0; i < a1; i++) {
        c[i] = a[i];
    }

    for (int i = 0; i < b1; i++) {
        c[a1 + i] = b[i];
    }

    for (int i = 0; i < c1 - 1; i++) {
        for (int j = 0; j < c1 - i - 1; j++) {
            if (c[j] > c[j + 1]) {
                int temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
        }
    }

    printf("Merged & Sorted array: ");
    for (int i = 0; i < c1; i++) {
        printf("%d ", c[i]);
    }

    float median;
    if (c1 % 2 == 0)
        median = (c[c1 / 2 - 1] + c[c1 / 2]) / 2.0;
    else
        median = c[c1 / 2];

    printf("\nMedian: %.2f\n", median);
}
