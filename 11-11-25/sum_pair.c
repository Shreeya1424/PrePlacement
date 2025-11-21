#include<stdio.h>

void main(){

    int n, i, j, k, count = 0;

    printf("Enter a size of array : ");
    scanf("%d",&n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter a value of K : ");
    scanf("%d",&k);

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]+arr[j]== k){
                count ++;
            }
        }
    }
    printf("numbers of pairs : %d ",count);
}    