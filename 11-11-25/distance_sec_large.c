#include<stdio.h>

void main(){

    int n, i;
    int first, second;

    printf("Enter a size of array : ");
    scanf("%d",&n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    first = second =-1;

    for(i=0;i<n;i++){
        if(arr[i] > first){
            second = first;
            first = arr[i];
        }
        else if(arr[i] < first && arr[i] > second){
            second = arr[i];
        }
    }

    if(second == -1){
        printf("second largest does not exist");
    }
    else{
        printf("Second largest = %d\n", second);

    }
    
}