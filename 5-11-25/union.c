#include<stdio.h>

void main()
{
    int a[] = {1, 2, 3, 4};
    int b[] = {3, 4, 5, 6};
    int A = 4, B = 4;

    int c[20];   
    int k = 0;

    for(int i = 0; i < A; i++)
    {
        c[k] = a[i];
        k++;
    }

    for(int i = 0; i < B; i++)
    {
        int flag = 0;
        for(int j = 0; j < A; j++)
        {
            if(b[i] == a[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            c[k] = b[i];
            k++;
        }
    }

    printf("Union: ");
    for(int i = 0; i < k; i++)
    {
        printf("%d ", c[i]);
    }
}
