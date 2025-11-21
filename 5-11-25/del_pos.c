#include <stdio.h>

int main() {
    int n, index;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the position to delete (0 to %d): ", n - 1);
    scanf("%d", &index);

    if (index < 0 || index >= n) {
        printf("Invalid position!\n");
        return 0;
    }

    for (int i = index; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--; 
    printf("New array after deletion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
