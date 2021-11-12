#include <stdio.h>
int f(int n){
	long long int sum,i;
	sum = 1;
	for(i=1;i<=n-1;i++)
		sum += 1+i;
	return sum;	
}

int main(){
	long long int n,sum,i;
	while(scanf("%ld",&n)!=EOF){
		printf("%ld ",f(n));
		sum = 0;
		for(i=1;i<=n;i++)
		sum += f(i);
		printf("%ld\n",sum);
	}
return 0;	
}
