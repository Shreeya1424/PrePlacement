#include<stdio.h>

void main(){
    int n , i=0, decimal =0,rem,place =1;
    
    printf("Enter a value of n : ");
    scanf("%d",&n);
    

    while (n != 0)
    {
        rem = n % 10;
        decimal = decimal + rem*place;
        place = place*8;
        decimal = decimal / 10;
    }
     printf("decimal is : %d ",decimal);
}