#include<stdio.h>

void main(){
    int a[] = { 30, 25, 40 };
        int b[] = { 45, 50, 55, 60, 65 };
        int a1 = 3;
        int b1 = 5;
        int c1;
         c1 = a1 + b1;
        int c[c1];

        for (int i = 0; i < a1; i = i + 1) {
        
            c[i] = a[i];
        }

        for (int i = 0; i < b1; i = i + 1) {


            c[a1 + i] = b[i];
        }
        printf("Merged array: ");
    for (int i = 0; i < c1; i++) {
        printf("%d ", c[i]);
    }
}