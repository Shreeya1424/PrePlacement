#include<stdio.h>

void main(){
    int n, rem;
    char hex[20];
    int i=0;

    printf("Enter a value of n : ");
    scanf("%d",&n);
    
    while (n!=0)
    {
        rem = n%16;

        if(rem<10){
            hex[i] = rem + 48 ;
        }
        else{
            hex[i] = rem + 55;
        }
        n = n / 16;
        i++;
    }
    printf("Hexa Decimal Value : ");
    for(int j = i-1; j>=0;j--){
        printf("%c",hex[j]);
    }
    

}