#include<stdio.h>
void main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; 

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int d =1 ;
    int a;
    for(int i =0 ;i<n;i++){
        for(int j = i+1;j<=n;j++){
            if(arr[i]==arr[j]){
                d++;
                 a =arr[i];
            }
        }
    }
    if(d==2){
        printf("duplicat number is : %d",a);
    }
    else
    {
        printf("array does not contains duplicate !!");
    }
    
       
}