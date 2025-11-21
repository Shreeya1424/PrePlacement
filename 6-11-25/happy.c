#include<stdio.h>

void main(){
    int n,rem,sum;
    int arr[100], size = 0;
    printf("Enter a value of n : ");
    scanf("%d",&n);
    
    int temp = n;
    while (1) {
        sum =0;
        while (temp > 0) {
            rem = temp % 10;
            sum = sum + (rem * rem);
            temp = temp / 10;
        }
            if (sum == 1) {
                printf("It is a Happy Number");
                break;
            } 
    
    
        for(int k =0; k<size;k++){
            if (sum == arr[k])
            {
                printf("not happy number");
                return;
            }
        }
     arr[size] = sum;
        size++;

        temp = sum;
    }
}