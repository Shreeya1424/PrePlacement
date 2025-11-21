#include<stdio.h>

void main(){
    int n , temp, octal =0,rem,place =1;
    
    printf("Enter a value of n : ");
    scanf("%d",&n);
    temp = n;

    while (n != 0)
    {
        rem = n % 8;
        octal = octal + rem*place;
        n = n/8;
        place = place*10;
    }
     printf("Octal of %d is : %d ",temp,octal);
}