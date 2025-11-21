#include <stdio.h>

void main() {
    int n, index, num;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[100]; 
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int last = arr[n-1];

    for(int i =n-1;i>0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=last;

    for(int i =0 ; i<n ; i++){
        printf("%d",arr[i]);
    }
    printf("\n");
    
}