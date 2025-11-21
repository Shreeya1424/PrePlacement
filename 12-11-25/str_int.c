#include<stdio.h>

int myAtoi(char s[]){

    int i = 0, sign = 1, result = 0;

    while(s[i] == ' '){
        i++;
    }
    if(s[i] == '-'){
        sign = -1;
        i++;
    }
    else if(s[i] == '+'){
        i++;
    }
    while(s[i] >= '0' && s[i] <= '9'){
        result = result * 10 + (s[i] - '0');
        i ++;
    }
    return result*sign;
}

void main(){
    char s[100];
    printf("Enter a string : ");
    scanf("%99s",&s);

    int ans = myAtoi(s);
    printf("%d",ans);
}