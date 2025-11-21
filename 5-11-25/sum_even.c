void main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; 

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    for(int i =0 ; i<n ; i++){
        for(int j = i+1;j<n;j++){
            int sum = arr[i] + arr[j];
            if(sum % 2 ==0){
                printf("(%d, %d) -> Sum = %d\n", arr[i], arr[j], sum);

            }
        }
    }    
 }
