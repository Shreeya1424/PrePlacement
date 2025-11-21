#include <stdio.h>

int n;  // global variable for array size

// Recursive function
int isInArray(int a[], int m) {
     int i = 0;       

    if (i == n)             
        return 0;           

    if (a[i] == m)          

    i++;                    
    return isInArray(a, m); 
}

int main() {
    int a[100], m, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter number to search: ");
    scanf("%d", &m);

    if (isInArray(a, m))
        printf("%d is present in array.\n", m);
    else
        printf("%d is not present in array.\n", m);

    return 0;
}
