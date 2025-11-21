#include <stdio.h>

int countWay(int n) {
    int count = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n/2; j++){
           for (int k = 0; k <= n/3; k++){
                if(((i*1) + (j*2) + (k*3)) == n){
                    
                    count ++;
                }
           }
           
        }
    }
    return count;
}

void main() {
    int n;
    printf("Enter a value of N: ");
    scanf("%d", &n);

    int ans = countWay(n);
    printf("Total hopes : %d\n",ans);
}
