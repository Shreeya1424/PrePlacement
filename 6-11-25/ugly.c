#include<stdio.h>

void main(){
    int n;
    printf("Enter a value of n : ");
    scanf("%d",&n);

    if(n<=0){
        printf("not a ugly number !!!");
    }
    int flag =0;
    while (n != 1)
    {
        if(n%2==0){
            n=n/2;
        }
        else if (n%3==0)
        {
            n=n/3;
        }
        else if (n%5==0)
        {
            n=n/5;
        }
        else 
        {
            flag=1;
            break;
        }  
    }
    if(flag==0){
        printf("It is ugly number");
    }
    else{
        printf("It is not ugly number");
    }
    
}