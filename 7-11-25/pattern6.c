#include<stdio.h>
void main()
{
     int i,j,n;
     printf("Enter Swastik Size(n):");
     scanf("%d",&n);
     printf("* ");
    
     for(i=0; i<n-2; i++)
           printf("  ");
    
     for(i=0; i<n; i++)  // for right upper line
           printf("* ");
    
     printf("\n");
    
     for(j=0; j<n-2; j++)
     {
           printf("* ");

           for(i=0; i<n-2; i++) // first straight line
                printf("  ");
           printf("* \n");
     }
    
     for(i=0; i<n*2-1; i++)     // for horizontal line in middle
           printf("* ");
     printf("\n");
    
     for(j=0; j<n-2; j++)
     {
           for(i=0; i<=n-2; i++)
                printf("  ");
           printf("* ");                // for bottom straight line
           for(i=0; i<n-2; i++)
                printf("  ");
           printf("* \n");
     }

     for(i=0; i<n; i++)  // for bottom left most line
           printf("* ");

     for(i=0; i<n-2; i++)
           printf("  ");
     printf("* ");  
}