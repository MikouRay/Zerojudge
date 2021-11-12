#include <stdio.h>

int main(){
	int i,j,T,n,a;
	char s[1000];
	while(scanf("%d",&T)!=EOF){
		for(i=0;i<T;i++){
			scanf("%s", s);
			for(n=0;s[n]!='\0'; n++);
			a=s[0]-'0';
			for(j=0;j<n-1;j++)
				a=a*(s[j+1]-'0');
			printf("%d\n",a);	
		} 
	}
return 0;
}
