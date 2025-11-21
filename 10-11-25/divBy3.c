#include <stdio.h>

void sortDesc(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void main() {
    int n;
    printf("Enter number of digits: ");
    scanf("%d", &n);

    int arr[n];
    int sum = 0;

   for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
        sum+=arr[i];
    }

    if (sum % 3 != 0) {
        printf("Digits cannot form a number divisible by 3.\n");
    }
    else 
    {
       printf("%d",sum);
    }
    

    sortDesc(arr, n);

    printf("Largest number divisible by 3: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}
