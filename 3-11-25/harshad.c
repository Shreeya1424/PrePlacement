#include <stdio.h>

int main() {
    int n, d;

    int sum=0;
    printf("Enter a number: ");
    scanf("%d", &n);
    int temp = n;
    while(n > 0) {
        d = n % 10;   
        sum = sum + d;  
        n = n / 10;
        
    }
    if(temp%sum==0){
        printf("harshad number");
    }
    else{
        printf("not harshad Number");
    }
    

    return 0;
}
