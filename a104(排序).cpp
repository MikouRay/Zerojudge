#include <stdio.h>
#include <algorithm> //sort
using namespace std; //sort 
int main(){
	int i,n,a[1000];
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		for(i=0;i<n;i++)
			printf("%d ",a[i]);	
		printf("\n");	
	}
return 0;	
} 
