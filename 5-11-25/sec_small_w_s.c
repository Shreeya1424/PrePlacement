#include<stdio.h>

void main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int smallest = arr[0];
    int second = 99999;

    for(int i = 0; i < n; i++) {
        if(arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    for(int i = 0; i < n; i++) {
        if(arr[i] > smallest && arr[i] < second) {
            second = arr[i];
        }
    }

    printf("Second smallest = %d", second);
}
