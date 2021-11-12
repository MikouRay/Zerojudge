#include<stdio.h>

int main(){
	int n,i,j,d;
	int a[4];
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){
			for(j=0;j<=3;j++)
			scanf("%d",&a[j]);
			if(a[1]/a[0]==a[2]/a[1])
			a[4]=a[3]*(a[1]/a[0]);
			if(a[1]-a[0]==a[2]-a[1])
			a[4]=a[3]+(a[1]-a[0]);
			for(j=0;j<=3;j++)
			printf("%d ",a[j]);
			printf("%d\n",a[4]);
	    }
	}
	return 0;
}
