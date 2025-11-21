#include<stdio.h>

void main(){
    int n, s, temp, count, ls;
    printf("Enter a value of n : ");
    scanf("%d",&n);

    temp = n;
    s = n*n;

    while (temp > 0)
    {
        count++;
        temp = temp / 10;
    }
     int div = 1;
     for(int i = 0; i < count; i++){
            div *=10;
     }
     ls = s%div;

     if(ls == n){
        printf("It is Automorphic number .");
     }
     else{
        printf("It is not Automorphic number !!");
     }
}