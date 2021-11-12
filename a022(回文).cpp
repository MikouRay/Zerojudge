#include<stdio.h>

int main(){
	char a[1000];
	int n,m,i,k;
	while(scanf("%s", a)!=EOF){
		k=0;
		for(n=0;a[n]!='\0'; n++);
		m = n / 2;
		for(i=0;i<m;i++){
			if(a[0+i]!=a[n-1-i])
			k=1;
		}
		if(k==0)
		printf("yes\n");
		else
		printf("no\n");
	}
	return 0; 
}
