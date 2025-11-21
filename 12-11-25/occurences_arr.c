#include<stdio.h>

int ascocrnc(int arr[], int n){

    int i, found = 0, count = 1;

    for(i = 0; i < n-1; i ++){
        if(arr[i] > arr[i+1]){
            printf("Array Is Not Ascending Order !\n");
            return 0;
        }
    }

    for(i = 0; i < n-1; i++){
        if(arr[i] == arr[i+1]){
            count ++;
        }
        else{
            count = 1;
        }

        if(count >= 3){
            found = 1;
            break;
        }
    }

        if(found == 1){
            return 1; 
        }
        else{
            return 0; 
        }
}

void main(){
     int n, i;

     printf("Enter a size of N : ");
     scanf("%d",&n);

    int arr[n];
     for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    n = sizeof(arr) / sizeof(arr[0]);

    int result = ascocrnc(arr, n);
    printf("\nResult = %d\n", result);

}