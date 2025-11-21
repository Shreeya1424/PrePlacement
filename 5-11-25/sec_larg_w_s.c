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

    int largest = arr[0];
    int second = -99999;

    for(int i = 0; i < n; i++) {
        if(arr[i] > largest) {
            largest = arr[i];
        }
    }

    for(int i = 0; i < n; i++) {
        if(arr[i] > second && arr[i] < largest) {
            second = arr[i];
        }
    }

    printf("Second largest = %d", second);
}
