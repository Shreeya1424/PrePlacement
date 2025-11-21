#include<stdio.h>
int multi (int n,int m){
    int i, mul = 0 ;
    for(i = 1 ; i<= m ; i ++){
        mul+=m;
    }
    return mul;
}
int pow(int n, int m){
    int i,r=1;
    for(i=0;i<=m;i++){
        r=multi(r,n);
    }
    return r;
}

void main (){
     int n, m, i, mul = 0;

    printf("Enter a base: ");
    scanf("%d", &n);

    printf("Enter a power: ");
    scanf("%d", &m);

    mul = pow(3,4);
    printf("%d",mul);

}