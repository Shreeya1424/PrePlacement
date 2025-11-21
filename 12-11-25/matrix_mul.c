#include<stdio.h>

void main(){
    int i, j, k;
    int a[10][10], b[10][10], c[10][10];
    int r1, c1, r2, c2;
 
    printf("First Matrix:\n");
    printf("Enter a size of R1 : ");
    scanf("%d",&r1);

    printf("Enter a size of C1 : ");
    scanf("%d",&c1);

    printf("Second Matrix:\n");
    printf("Enter a size of R2 : ");
    scanf("%d",&r2);

    printf("Enter a size of C2 : ");
    scanf("%d",&c2);

    if(c1 != r2){
        printf("Matrix Multiplication Is Not Possible ! ");
        return;
    }

    printf("Enter elements of first matrix:\n");
    for(i = 0; i < r1; i ++){
        for(j = 0; j < c1; j ++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for(i = 0; i < r2; i ++){
        for(j = 0; j < c2; j ++){
            scanf("%d",&b[i][j]);
        }
    }

    for(i = 0; i < r1; i ++){
        for(j = 0; j < c2; j ++){
            c[i][j] = 0;
        }
    }

    for(i = 0; i < r1; i ++){
        for(j = 0; j < c2; j ++){
            for(k = 0; k < c1; k ++){
            c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("new matrix is :\n");
    for(i = 0; i < r1; i ++){
        for(j = 0; j < c2; j ++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}