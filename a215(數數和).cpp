#include <stdio.h>
int main(){
	int i,n,m,sum;
	while(scanf("%d%d",&n,&m)!=EOF){
		sum = 0;
		for(i=0;sum<=m;i++){
			sum += n;
			n++;
		}
		if(m<0)
		printf("1\n");
		else
		printf("%d\n",i);
	}
return 0;
}
