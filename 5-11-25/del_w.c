#include <stdio.h>

int main() {
    int n, pos;
    int arr1[100], arr2[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr1[i]);
    }

    printf("Enter position to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return 0;
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (i != pos) {
            arr2[j] = arr1[i];
            j++;
        }
    }
    n--; 

    printf("Array after deletion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }

    printf("\n");
    return 0;
}
