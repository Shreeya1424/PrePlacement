#include <stdio.h>

void main() {
    int n = 6; // number of rows
    int i, j;

    for(i = 1; i <= n; i++) {
        printf("1 ");  

        for(j = 1; j < i - 1; j++) {
            printf("* ");
        }

        if(i > 1)
            printf("%d ", i);

        for(j = 1; j < i - 1; j++) {
            printf("* ");
        }

        if(i > 1)
            printf("1");

        printf("\n");
    }
}
