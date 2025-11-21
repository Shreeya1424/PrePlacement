#include<stdio.h>
void main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    int sum =0;
    int max = arr[0];
    
    
   for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    for(int i =0; i<n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
        int new_max = max * (max + 1) / 2;
        int ans = new_max - sum;
        printf("%d",ans);
    }

    
}