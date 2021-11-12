#include <stdio.h>
#include <string.h>
int main(){
	char n[1000];
	int i;
	while(scanf("%s",n)!=EOF){
		for(i=0;i<strlen(n);i++)
			printf("%c", n[i]-7);
		printf("\n");
	}
	return 0;
}
