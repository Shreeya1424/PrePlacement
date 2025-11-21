#include<stdio.h>

int main() {
    int n, j, i,sum =0;
    

    printf("Enter number of terms: ");
    scanf("%d", &n);


    for(i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++)
        {
           sum = sum +j;
        }
    }
     printf("%d",sum);

    return 0;
}
