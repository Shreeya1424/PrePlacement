#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; 

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int largestIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[largestIndex]) {
            largestIndex = i;
        }
    }

    int smallestIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[smallestIndex]) {
            smallestIndex = i;
        }
    }

    printf("Largest number is: %d\n", arr[largestIndex]);
    printf("Smallest number is: %d\n", arr[smallestIndex]);

    return 0;
}
