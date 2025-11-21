#include<stdio.h>
#include<stdbool.h>
bool modify(int array[],int n){
    int i,count=0;
    for(i=0;i<n;i++){
        if(array[i]>array[i+1]){
            count++;
            if(count>1){
                return false ;
            }
            if(array[i]>array[i+1]){
                array[i] = array[i+1];
            }
        }

    }
    return true;
}
void main(){
    int n,i;
    int count=0;
    printf("Enter size of array:");
    scanf("%d",&n);
    int array[n];
    for(i=0;i<n;i++){
        printf("Enter element of array:");
        scanf("%d",&array[i]);
    }
    bool ans = modify(array,n);
    if(ans == false){
        printf("%d",ans);
    }
    else{
        for(i=0;i<n;i++){
        printf("%d",array[i]);
      }
    }
    
}