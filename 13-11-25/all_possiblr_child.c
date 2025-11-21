#include<stdio.h>
int ways(int n){
    int count=0;
    
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n/2;j++){
                for(int k=0;k<=n/3;k++){
                    if(((i*1)+(j*2)+(k*3))==n){
                        count++;
                    }
                }
            }
        }
        return count;
}
int countWay(int n){
    if(n<0){
        return 0;
    }
    else if(n==0){
        return 1;
    }
    else{
        return countWay(n-1)+countWay(n-2)+countWay(n-3);
    }
}
void main(){
     int n,x;
     printf("Enter n: ");
     scanf("%d", &n);
     printf("Enter x: ");
     scanf("%d", &x);
     if(x==1){
       int ans = ways(n);
       printf("%d",ans);
     }else{
        int ans1 = countWay(n);
        printf("%d",ans1);
     }
     
}