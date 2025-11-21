#include <stdio.h>
#include <string.h>

int main() {
    char str[20], revstr[20];
    int len, i, j;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);
    j = 0;

    for(i = len - 1; i >= 0; i--) {
        revstr[j++] = str[i];
    }
    revstr[j] = '\0'; 

    if(strcmp(str, revstr) == 0) {
        printf("String is Palindrome");
    } else {
        printf("String is Not Palindrome");
    }

    return 0;
}
