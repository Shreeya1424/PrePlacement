#include <stdio.h>

void main() {
    char str[100];
    int i, j, count;

    printf("Enter the string: ");
    scanf("%s", str);  // input like 2a3b etc.

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            count = str[i] - '0';  
            i++;
            if (str[i] == '\0')  
                break;

            for (j = 0; j < count; j++) {
                printf("%c", str[i]);
            }
        } else {
            printf("%c", str[i]);
        }
    }

    printf("\n");
}
