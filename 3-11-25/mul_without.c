#include <stdio.h>

int main()
{
    int a, i, sum = 0;

    printf("Enter a numbers: ");
    scanf("%d", &a);

    for(i = 1; i <=a; i++)
    {
        sum = sum + a; 
    }

    printf("Multiplication  = %d",sum);

    return 0;
}
