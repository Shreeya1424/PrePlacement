#include<stdio.h>
#include<string.h>
#include<math.h>

void main(){
    char bin[100];
    printf("Enter binary number:");
    scanf("%s",&bin);
    int len = strlen(bin);
    int point=-1;
    for(int i=0;i<len;i++){
        if(bin[i] == '.'){
            point = i;
            break;
        }
    }
    if(point == -1){
        point=len;
    }
    double decimal = 0.0;
    int power=0;
    for(int i=point-1;i>=0;i--){
        if(bin[i] == '1'){
            decimal = decimal+pow(2,power);
            
        }
        power++;
    }
    double frac=0.5;
    for(int i=point+1;i<len;i++){
        if(bin[i] == '1'){
            decimal = decimal+frac;
            frac = frac/2;
        }
    }
    printf("decimal of given number:%lf",decimal);
    
}