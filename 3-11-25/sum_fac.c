#include <stdio.h>

int main() {
    int n, i;
    int sum = 0;
    printf("Enter n number: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        if(n% i== 0) {
        sum = sum + i;
        }
    }
            printf("%d ", sum);

    return 0;
}
