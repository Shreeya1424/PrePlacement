#include<stdio.h>

void main(){
int i, j, gap, n=5;
int  num;
    for(i=0;i<=n;i++){
        num =i;
        gap = n-1;
        for(j=1;j<=i;j++){
           
            printf("%d",num);
            num=num+gap;
            gap--;
        }
        printf("\n");
    }
}