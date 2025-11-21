#include<stdio.h>

void Insertion(int arr[], int n){
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j =i -1;
    
    while (j >= 0 && arr[j]> key)
    {
        arr[j+1]= arr[j];
        j = j-1;
    }
    arr[j+1] = key;
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

    Insertion(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}

