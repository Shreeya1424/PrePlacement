#include<stdio.h>
 int isPrime(int n);
void main(){
    int n = 30;
    int num = 1;
    int count = 9;
    int digit = 1;

    while (n > digit * count)
    {
        n = n - digit*count;
        count = count*10;
        digit += 1;
        num *= 10;
    }
    
    int number = num + (n-1)/digit;
    printf("%d\n",number);
    
    int index = (n-1) % digit; 

    int div = digit - index - 1;
    for (int i = 0; i < div; i++) {
        number /= 10;
    }

    int result = number % 10;
    printf("The digit is: %d\n", result);

}