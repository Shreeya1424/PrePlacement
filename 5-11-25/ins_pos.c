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

    printf("Enter the position to insert (0 to %d): ", n);
    scanf("%d", &index);

    printf("Enter the number to insert: ");
    scanf("%d", &num);

    for (int i = n; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = num;
    n++; 
    printf("New array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
