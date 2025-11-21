#include <stdio.h>

int main() {
    int n, pos, num;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr1[100], arr2[100];

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr1[i]);
    }

    printf("Enter position to insert (0 to %d): ", n);
    scanf("%d", &pos);

    printf("Enter number to insert: ");
    scanf("%d", &num);

    for (int i = 0; i < pos; i++) {
        arr2[i] = arr1[i];
    }

    arr2[pos] = num;

    for (int i = pos; i < n; i++) {
        arr2[i + 1] = arr1[i];
    }

    n++;

    printf("Array after insertion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }

    printf("\n");
    return 0;
}
