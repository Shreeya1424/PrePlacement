#include<stdio.h>

void main()
{
    int a[] = {1, 2, 3, 4};
    int b[] = {3, 4, 5, 6};
    int A = 4, B = 4;

    printf("Intersection: ");

    for(int i = 0; i < A; i++)
    {
        for(int j = 0; j < B; j++)
        {
            if(a[i] == b[j])
            {
                printf("%d ", a[i]);
            }
        }
    }
}
