#include<stdio.h>
#include<string.h>
#include<math.h>

void main(){
    char hex[20];
    int decimal = 0, len, place = 1;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    len = strlen(hex);

    for(int i =len -1;i>=0;i--){
        if(hex[i]>='0' && hex[i]<='9'){
            decimal += (hex[i] - 48) * place;
        }
        else if (hex[i]>='A' && hex[i]<='F')
        {
            decimal += (hex[i] - 55) * place;
        }
        else if (hex[i]>='a' && hex[i]<='f')
        {
            decimal += (hex[i] - 87) * place;
        }
        
        place = place *16; 
    }

    printf("Decimal value = %d", decimal);

}