#include<stdio.h>
void main(){

         int i, rem = 0;
		 int temp = i;
		 int ans = 0;

         for(int i =1;i<=1000;i++)
		{
		  
		    rem = temp%10;
			ans=ans+ rem *rem * rem;
			temp =(temp/10);
			if(ans==i){
			printf("%d",i);
			}
		}
}