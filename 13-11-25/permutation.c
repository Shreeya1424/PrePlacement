#include <stdio.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void permute(int arr[], int current[], int n, int pos) {
    if (pos == n) {
        printArray(current, n);
        return;
    }

    for (int i = 0; i < n; i++) {
        int already = 0;

        for (int j = 0; j < pos; j++) {
            if (current[j] == arr[i]) {
                already = 1;
                break;
            }
        }

        if (!already) { 
            current[pos] = arr[i];
            permute(arr, current, n, pos + 1);
        }
    }
}

void main() {
    int arr[] = {1, 2, 3};
    int n = 3;
    int current[10];  

    printf("All permutations:\n");
    permute(arr, current, n, 0);

}
