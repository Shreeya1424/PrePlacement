#include <stdio.h>

int main() {
    int n, i;
    int sum = 0;
    printf("Enter n number: ");
    scanf("%d", &n);

    for(i = 1; i <= n-1;i++){
        if(n% i== 0) {
        sum = sum + i;
        }
    }

    if(n== sum){
        printf("perfect number=%d", n);
    }
    else{
        printf("not perfect");
    }

    return 0;
}
