#include <stdio.h>
#include <math.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

void main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int dp[n + 1];

    dp[0] = 0; 

    for (int i = 1; i <= n; i++) {
        dp[i] = i; 
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], 1 + dp[i - j * j]);
        }
    }

    printf("Least number of perfect squares: %d\n", dp[n]);

}
