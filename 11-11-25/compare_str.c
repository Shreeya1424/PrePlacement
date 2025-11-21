#include<stdio.h>
#include<string.h>

void main(){
char s1[100], s2[100];
int i,j,len1,len2,found,count=0;

    printf("Enter the string1: ");
    scanf("%s", s1);

    printf("Enter the string2: ");
    scanf("%s", s2);

    len1 = strlen(s1);
    len2 = strlen(s2);

    if(len1 != len2){
        printf("Both string has no same length ..");
        return;
    }

    for(i = 0; i < len1; i++){
        found = 0;
        for(j = 0; j < len2; j++){
            if(s1[i] == s2[j]){
                s2[j] = '0';
                found = 1;
                break;
            }
        }
        if(found){
            count ++;
        }
        else{
            break;
        }
    }

    if(count == len1){
        printf("Both string are same ..");
    }
    else{
        printf("Both string are not same ..");
    }

}