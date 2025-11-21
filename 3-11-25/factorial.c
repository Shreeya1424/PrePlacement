#include<stdio.h>

void main(){
    int i, n, fact=1;
     printf("Enter a n numbers : \n");
    scanf("%d",&n);

    for (i=0;i<=n;i++){
         fact = fact*i;
    }
    printf("fact =%d" ,fact);
}