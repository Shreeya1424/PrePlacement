#include<stdio.h>

int main() {
    int n, i;
    int first = 0, second = 1, next;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: %d %d ", first, second);

    for(i = 2; i < n; i++) {
        next = first + second;
        printf("%d ", next);
        first = second;
        second = next;
    }

    return 0;
}
