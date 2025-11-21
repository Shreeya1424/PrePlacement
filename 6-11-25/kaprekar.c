#include<stdio.h>

void main(){
    int n,div = 1,count = 0,sum;
    int s;
    printf("Enter a value of n : ");
    scanf("%d",&n);
    
    s = n*n;
    int temp = n;

    while (temp > 0)
    {
        count++;
        temp = temp / 10;
    }
    for (int i = 0; i < count; i++) {
        div = div * 10;
    }

    sum = (s/div)+(s%div);

    if(sum == n){
        printf("It is kaprekar number");
    }
    else{
        printf("It is not kaprekar number !");
    }
}