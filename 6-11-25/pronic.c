#include<stdio.h>

void main(){
    int n , i;
    int flag =0;
    printf("Enter a value of n : ");
    scanf("%d",&n);

    for(i =0 ;i<=n ;i++){
        if(i*(i+1)==n){
            flag =1;
            break;
        }
    }
    if (flag == 1)
    {
        printf("It is pronic number");
    }
    else{
        printf("It is not pronic number");
    }
    
}