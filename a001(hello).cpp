#include<stdio.h>

int main(){
	char str[9999];
	while(scanf("%s",str)!=EOF)
		printf("hello, %s\n",str);
	return 0;
}
