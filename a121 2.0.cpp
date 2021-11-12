#include<stdio.h>
#include<math.h>
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		int count=0;
		for(int i=a;i<=b;i++){
			bool judge=true;
			if(i==1)
				judge=false;
			for(int j=2;j<=sqrt(i);j++){
				if(i%j==0){
					judge=false;
					break;
				}
			}
			if(judge==true)
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
} 
