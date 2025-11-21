#include <stdio.h>

void main() {
    int n = 5;    
    int num = 1;  

    for (int i = 1; i <= n; i++) {    
        if (i % 2 != 0) {
            for (int j = 1; j <= n; j++) {
                printf("%5d", num);
                num++;
            }
        } 
        else {
            int temp = num + n - 1;
            for (int j = 1; j <= n; j++) {
                printf("%5d", temp);
                temp--;
                num++;
            }
        }
        printf("\n");
    }
}
