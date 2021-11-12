#include<stdio.h>

int main(void){
	int n=0;
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break; 
		if(n%2==0)
			printf("0\n");
		else{
			int sum=0;
			while(n & 1 == 1){
				sum++;
				n = n>>1;			
			} 
			printf("%d\n",sum);
		} 
	}
} 
