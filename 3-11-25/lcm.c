#include <stdio.h>

int main() {
    int a, b, i, max;
int lcm;
    printf("Enter starting number: ");
    scanf("%d", &a);

    printf("Enter ending number: ");
    scanf("%d", &b);
max= a<b? a:b;

    for(i = max;i<=a*b;i++){
        if(i%a==0 && i%b==0){
             lcm=i;
             break;
        }
    }
    printf("%d",lcm);
    return 0;
}
