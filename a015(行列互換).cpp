#include<stdio.h>
int main(){
	int n,m,i,j;
	int a[100][100];
	while(scanf("%d%d",&n,&m)!=EOF){
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++)
			scanf("%d",&a[j][i]);
		}
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++)
			printf("%d ",a[i][j]);
			printf("\n");	
		}
	}
	return 0;
}
