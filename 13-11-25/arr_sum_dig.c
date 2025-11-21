#include<stdio.h>

int digitSum(int n){
    int sum = 0;

    while (n > 0)
    {
        sum = sum + (n % 10);
        n = n/10;
    }
    return sum;
}

void main(){
    int arr[] = {18, 43, 36, 13, 7};
    int n = 5;
    int i, j;
    int maxsum = 0;

    for(i = 0; i < n; i ++){
        for(j = i + 1; j < n; j ++){
            if(digitSum(arr[i]) == digitSum(arr[j])){
                int total = arr[i] + arr[j];
                if(total > maxsum){
                    maxsum = total;
                }
            }
        }
    }
    printf("Max Sum is :%d\n",maxsum);
}