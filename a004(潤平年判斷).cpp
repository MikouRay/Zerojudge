#include<stdio.h>

int main(){
	int y;
	while(scanf("%d",&y)!=EOF){
		if(y%4==0){
			if(y%100==0){
				if(y%400==0)
					printf("�|�~\n");
				else
					printf("���~\n");	
			} 
			else{
				printf("�|�~\n");
			}
		}	
		else{
			printf("���~\n");
		}
	}
	return 0;
}
