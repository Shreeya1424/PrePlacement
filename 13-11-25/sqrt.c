#include<stdio.h>

int mySqrt( int n){
    int i = 0;

    while ( i * i <= n)
    {
        i++;
    }
    return i - 1;
}

void main(){
    int n;
    printf("Enter a Value of N : ");
    scanf("%d",&n);

    int result = mySqrt(n);
    printf("Square root is : %d",result);
}