#include<stdio.h>

int main(){
		int x,ans[1000],i,j;
		while(scanf("%d", &x)!=EOF){
		for(i=0;x>0;i++){
			ans[i]=x%2;
			x=x/2;
		}
    	for(j=i-1;j>=0;j--)
    		printf("%d",ans[j]);
    	printf("\n");
    	}
return 0;    
}

