#include<stdio.h>

void reveerse(int arr[], int start, int end){
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start ++ ;
        end -- ;
    }   
}

void main(){
    int n;
    printf("Enter a size of array : ");
    scanf("%d",&n);

    int arr[n]; 
    n = sizeof(arr) / sizeof(arr[0]);


    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    reveerse(arr, 0, n-1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}