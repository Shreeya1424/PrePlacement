#include<stdio.h>
#include<string.h>
#include<ctype.h>
void main(){
    char str[100];
    printf("Enter string: ");
    scanf("%s", &str);
    int left = 0;
    int right = strlen(str) - 1;
    while(left<right){
        if(!isalpha(str[left])){
            left++;
        }
        else if(!isalpha(str[right])){
            right--;
        }
        else{
            int temp = str[left];
            str[left] = str[right];
            str[right] = temp;
            left++;
            right--;
        }
    }
    printf("%s",str);
}