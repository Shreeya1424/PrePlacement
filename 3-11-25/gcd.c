#include <stdio.h>

int main() {
    int a, b, i, min;
int gcd;
    printf("Enter starting number: ");
    scanf("%d", &a);

    printf("Enter ending number: ");
    scanf("%d", &b);
min = a<b? a:b;

    for(i = 1; i <= min; i++){
        if(a%i==0 && b%i ==0){
             gcd =i;
        }
    }
    printf("%d",gcd);
    return 0;
}
