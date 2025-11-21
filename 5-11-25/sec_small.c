#include <stdio.h>

void bubblesort(int arr[],int n){
    for(int i = 0 ; i<n-1 ;i++){
        for(int j =0 ; j<n-i-1 ; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; 

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    bubblesort(arr,n);
    printf("%d", arr[1]);
       
}