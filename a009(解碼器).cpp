#include <stdio.h>
#include <string>
int main()
{
	//ray
	//0 r 1 a 2 y 3 \0
	char n[1000];
	int i;
	while(scanf("%s",n)!=EOF){
		for(i=0;n[i]!='\0';i++){
			n[i]-=7;
			printf("%c", n[i]);
		} 
		printf("\n");
	}
	return 0;
}
