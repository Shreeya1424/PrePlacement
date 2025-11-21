#include <stdio.h>

void main() {
    int n = 4;
    int size = 2 * n - 1;  
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            int top = i - 1;
            int left = j - 1;
            int right = size - j;
            int bottom = size - i;

            int min = top;
            if (left < min) min = left;
            if (right < min) min = right;
            if (bottom < min) min = bottom;

            printf("%d ", n - min);
        }
        printf("\n");
    }
}
