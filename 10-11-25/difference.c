#include <stdio.h>
#include <limits.h> 

void main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    
   for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }


    int smallest = INT_MAX, second_smallest = INT_MAX;
    int largest = INT_MIN, second_largest = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] < smallest)
            smallest = arr[i];
        if (arr[i] > largest)
            largest = arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] > smallest && arr[i] < second_smallest)
            second_smallest = arr[i];
        if (arr[i] < largest && arr[i] > second_largest)
            second_largest = arr[i];
    }

    int diff = second_largest - second_smallest;
    printf("Difference: %d\n", diff);

}
