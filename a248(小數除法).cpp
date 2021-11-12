#include<stdio.h> 
int main(){
	int a,b,n,i,num;
	while(scanf("%d%d%d",&a,&b,&n)!=EOF){
		num = a/b;
		a = (a%b)*10;
		printf("%d.",num);
		for(i=0;i<n;i++){
			num = a/b;
		    a = (a%b)*10;
		    printf("%d",num);
		}
		printf("\n");
	}
	return 0; 
}
