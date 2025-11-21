#include<stdio.h>

int main() {
    int n, temp, d, i, fact, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    temp = n;

    while(temp > 0) {
        d = temp % 10;    
        fact = 1;

        for(i = 1; i <= d; i++) {
            fact = fact * i;   
        }

        sum = sum + fact;
        temp = temp / 10;     
    }

    if(sum == n)
        printf("Strong Number", n);
    else
        printf("NOT Strong Number", n);

    return 0;
}
