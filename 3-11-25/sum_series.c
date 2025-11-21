#include<stdio.h>

void main(){
    int i, n, sum=0;

    printf("Enter a n numbers : \n");
    scanf("%d",&n);

    for (i=0;i<=n;i++){
        sum = sum + (i*i);
    }
    printf("Sum = %d" ,sum);

}