#include<stdio.h>
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		int count=0,j;
		for(int i=a;i<=b;i++){
			if(i==1)
				continue;
			if(i==2){
				count++;
				continue;
			}
			for(j=2;j<i;j++){
				if(i%j==0)
					break;
			}
			if(j==i)
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
} 
