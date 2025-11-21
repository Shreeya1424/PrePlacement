#include <stdio.h>
#include <string.h>

void main() {
    char s[100];
    int i, j, len;
    char repeated = '\0';  

    printf("Enter the string: ");
    scanf("%s", s);

    len = strlen(s);

    for (i = 0; i < len; i++) {
        for (j = i + 1; j < len; j++) {
            if (s[i] == s[j]) {
                repeated = s[i];
                break;  
            }
        } 
    }

    if (repeated != '\0')
        printf("first repeated character: %c\n", repeated);
    else
        printf("No repeated character found.\n");

}
