#include<stdio.h>

int removedup(int arr[], int n){
    int k = 0;

    for(int i = 0; i < n; i++){
        int flag = 0;
        for(int j = 0; j < k; j++){
            if(arr[i] == arr[j]){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            arr[k++] = arr[i];
        }
    }
    return k;
}

void main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int size = removedup(arr, n);

    printf("Array after removing duplicates:\n");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}
