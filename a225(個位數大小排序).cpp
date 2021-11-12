#include <stdio.h>
#include <algorithm> 
using namespace std;
int main(){
	int k,n,i,j,a[10][1000];
	while(scanf("%d",&n)!=EOF){
		int b[10] = {0,0,0,0,0,0,0,0,0,0};
		for(i=0;i<n;i++){
			scanf("%d",&k);
			b[k%10]++;
			a[k%10][b[k%10]]=k;
		}
		for(i=0;i<=9;i++){
			int c[b[i]];
			for(j=0;j<b[i];j++)
				c[j]=a[i][j+1];
			sort(c,c+b[i]);	
			for(j=b[i]-1;j>=0;j--)
				printf("%d ",c[j]);		
		}
		printf("\n");
	}
return 0;	
}
