#include<stdio.h> 
void main(){
     int i, j, n;
      printf("Enter a value of n : "); 
      scanf("%d",&n); 
      for(i = 1;i<=n;i++){ 
        for(j=1;j<=(2*i)-1;j++){ 
            if (i ==2 ||j == 2)
            {
                printf("1 * 1");
            }
            else if(j%2==0){
                printf("*");
            }
            
            
            else{
                printf("%d",j); 
            } 
        } 
        printf("\n"); 
     }
 }