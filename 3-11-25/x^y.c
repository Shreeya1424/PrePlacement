#include <stdio.h>

int main()
{
    int a, b, i, sum = 1;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    for(i = 1; i <= b; i++)
    {
        sum = sum * a ;
    }

    printf("Multiplication  = %d",sum);

    return 0;
}
