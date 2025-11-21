#include<stdio.h>

void main(){
    int n=15, m=1, k=3, tc=0, w=0, rw=0, nc=0;

    tc = n/m;
    w = tc;

    while (w >= k )
    {
        nc = w/k;
        tc += nc;
        rw = w%k;
        w = nc + rw;
    }
    printf("Total chocolate is  : %d",tc);
}