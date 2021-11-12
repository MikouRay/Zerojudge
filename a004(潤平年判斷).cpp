#include<stdio.h>

int main(){
	int y;
	while(scanf("%d",&y)!=EOF){
		if(y%4==0){
			if(y%100==0){
				if(y%400==0)
					printf("閏年\n");
				else
					printf("平年\n");	
			} 
			else{
				printf("閏年\n");
			}
		}	
		else{
			printf("平年\n");
		}
	}
	return 0;
}
