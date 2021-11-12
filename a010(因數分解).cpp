#include<stdio.h>
int main(){
	int num;
	while(scanf("%d",&num)!=EOF){
		int i;
		for(i=2;i<=num;i++){
			if(num%i==0){
				int index=0;
				while(num%i==0){
					num/=i;
					index++;
				}
				if(index==1)
					printf("%d",i);
				else
					printf("%d^%d",i,index);
				if(num==1)
					break;
				else
					printf(" * ");	
			}
		}
		printf("\n");
	}
	return 0;	
}
