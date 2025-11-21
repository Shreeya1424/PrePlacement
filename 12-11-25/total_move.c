#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Enter a value of n: ");
    scanf("%d", &n);

    int totalMoves = pow(2, n) - 1;
    printf("Total moves required: %d\n", totalMoves);

    return 0;
}
